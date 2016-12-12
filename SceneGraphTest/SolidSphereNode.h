#pragma once
#include "scenegraphnode.h"
#include <GL/glut.h>
/**
  *@file SolidSphereNode.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *
  */

/**
  *@class SolidSphereNode
  *This class is a simple parametrized glu solid sphere that can be textured
  *@todo use boost arrays to have safe bound checked arrays
  */
class SolidSphereNode :
	public SceneGraphNode
{
private:
	double radius_;
	int slices_;
	int stacks_;
	unsigned char sphere_color_[4];
	double previous_color_[4];
	GLUquadric* quadric_; 
	GLboolean was_texture_enabled;

public:
	/**
	  *constructor
	  */
	SolidSphereNode(double radius, 
		int slices,
		int stacks,
		unsigned char red,
		unsigned char green,
		unsigned char blue,
		unsigned char alpha = 0,
		std::string name = "SolidSphereNode");

	
	/**
	  *destructor
	  */
	virtual ~SolidSphereNode(void);
	

	virtual void setState(void);
	virtual void draw(void);
	virtual void unsetState(void);
};
