#include "StdAfx.h"
#include "GraphRenderer.h"

GraphRenderer::GraphRenderer(int argc, char** argv, double scene_size, boost::shared_ptr< SceneGraph > graph) :
graph_(graph), graphRendererVisitor(graph), GlutApplication(argc, argv, "Graph Renderer")
{
	glutApplicationPointer = this;
	phi=0.0;
	theta=0.0;
	sdepth = scene_size / 2.0;
	zNear=1.0;
	zFar=scene_size;
	downY = 0;
	downX = 0;
	aspect = (double) windowWidth_ / (double) windowHeight_;
	leftButton = false;
	middleButton = false;
}

GraphRenderer::~GraphRenderer(void)
{
}

void GraphRenderer::OnInit(void)
{
	glClearDepth (1.0);
	glEnable (GL_DEPTH_TEST) ;
	glDepthFunc (GL_LEQUAL) ;
	glEnable(GL_CULL_FACE); // Enable Culling
	glCullFace(GL_BACK);
	glDisable( GL_BLEND );
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	


}

void GraphRenderer::OnReshapeWindow(int newWidth, int newHeight)
{
	windowHeight_ = newHeight;
	windowWidth_ = newWidth;
	aspect = (double)windowWidth_ / (double)windowHeight_;
	glViewport( 0, 0, windowWidth_, windowHeight_ );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(64.0, aspect, zNear, zFar);
	
	glutPostRedisplay();
}

void GraphRenderer::OnDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0,0.0,-sdepth);
	glRotated(-theta, 1.0, 0.0, 0.0);
	glRotated(phi, 0.0, 0.0, 1.0);
	boost::depth_first_search( graph_->getGraph(), visitor( graphRendererVisitor ) );
	glutSwapBuffers();
}

void GraphRenderer::OnKeyPressed(unsigned char keyPressed, int x, int y)
{

}

void GraphRenderer::OnMousePressed(int button, int state, int x, int y)
{
	
	downX = x; downY = y;

	leftButton = ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN));

	middleButton = ((button == GLUT_MIDDLE_BUTTON) &&  (state == GLUT_DOWN));

	glutPostRedisplay();
}

void GraphRenderer::OnMouseDrag(int x, int y)
{
	
	if (leftButton)
	{
		phi += (double)(x-downX)/4.0;
		theta += (double)(downY-y)/4.0;
	} // rotate

	if (middleButton)
	{
		sdepth += (double)(downY - y) / 10.0;
	} // scale

	downX = x;   downY = y; 

	glutPostRedisplay();
}
