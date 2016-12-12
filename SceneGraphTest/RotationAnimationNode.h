#pragma once
#include "scenegraphnode.h"
#include <boost/signal.hpp>
/**
  *@file RotationAnimationNode.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *
  */

/**
  *@class RotationAnimationNode
  *@todo sucussfully integrate this node into the scene graph
  *This class represents a simple rotation animation it uses glut timer by
  *registering with it to be notified of a time event according to the observer pattern
  * it uses the Boost Singnal library
  *
  */
class RotationAnimationNode :
	public SceneGraphNode, public boost::signals::trackable
{
private:
	double angular_step_;
	double current_angle_;
	double rotation_vector_[3];
	

public:
	RotationAnimationNode(double angular_step, double x, double y, double z, std::string name="SRA Node");
	virtual ~RotationAnimationNode(void);
	void update(void);
	/**
	  * sets the opengl state
	  */
	virtual void setState(void);

	/**
	  * render this node using opengl
	  */
	virtual void draw(void);

	/**
	  * unsets the state set by the setState SceneGraphNode#setState method
	  */
	virtual void unsetState(void);
};
