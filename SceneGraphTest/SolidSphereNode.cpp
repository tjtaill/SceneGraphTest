#include "StdAfx.h"
#include "SolidSphereNode.h"
#include <GL/glut.h>

SolidSphereNode::SolidSphereNode(double radius, 
		int slices,
		int stacks,
		unsigned char red,
		unsigned char green,
		unsigned char blue,
		unsigned char alpha,
		std::string name) :
	radius_(radius),
	slices_(slices),
	stacks_(stacks),
	SceneGraphNode( name, SolidSphereNodeType )
{
	sphere_color_[RedIndex] = red;
	sphere_color_[GreenIndex] = green;
	sphere_color_[BlueIndex] = blue;
	sphere_color_[AlphaIndex] = alpha;
	quadric_ = gluNewQuadric();
	gluQuadricTexture(quadric_, GL_TRUE);
	
}

SolidSphereNode::~SolidSphereNode(void)
{
	gluDeleteQuadric( quadric_ );
}

void SolidSphereNode::setState(void)
{
	glGetDoublev( GL_CURRENT_COLOR, &previous_color_[0]);
	
	
}

void SolidSphereNode::draw(void)
{
	glEnable( GL_TEXTURE_2D );
	glColor4ubv( &sphere_color_[0] );
	gluSphere( quadric_, radius_, slices_, stacks_);
	glDisable( GL_TEXTURE_2D );
}

void SolidSphereNode::unsetState(void)
{
	glColor4bv( &previous_color_[0] );
}