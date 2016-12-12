#pragma once

#include "GlutApplication.h"
#include "GraphRendererVisitor.h"
#include <boost/shared_ptr.hpp>
/**
  *@file GraphRenderer.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *
  */

/**
  *@class GraphRenderer
  *This class extends glut application by using the scene graphto manage a 3d scene and
  *provides a viewer for that scene which can zoom in and out and rotate with the mouse
  */


class GraphRenderer :
	public GlutApplication
{
private:
	boost::shared_ptr< SceneGraph > graph_;
	GraphRendererVisitor graphRendererVisitor;
	double phi, theta;
	double sdepth;
	double zNear, zFar;
	double aspect;
	int downX, downY;
	bool leftButton, middleButton;

public:
	GraphRenderer(int argc, char** argv, double scene_size, boost::shared_ptr< SceneGraph > graph );
	virtual ~GraphRenderer(void);
	virtual void OnInit(void);
	virtual void OnDisplay(void);
	virtual void OnReshapeWindow(int newWidth, int newHeight);
	virtual void OnKeyPressed(unsigned char keyPressed, int x, int y);
	virtual void OnMousePressed(int button, int state, int x, int y);
	virtual void OnMouseDrag(int x, int y);
};
