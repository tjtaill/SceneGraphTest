#include "StdAfx.h"
#include "RotationAnimationNode.h"
#include <GL/glut.h>


RotationAnimationNode::~RotationAnimationNode(void)
{

}

RotationAnimationNode::RotationAnimationNode(double angular_step, 
											 double x,
											 double y,
											 double z, 
											 std::string name) :
angular_step_(angular_step), current_angle_(0.0), SceneGraphNode( name, RotationAnimationNodeType )
{
	rotation_vector_[X] = x;
	rotation_vector_[Y] = y;
	rotation_vector_[Z] = z;
	
}
	

void RotationAnimationNode::update(void)
{
	
	current_angle_ += angular_step_;

	if ( current_angle_ >= 360.0 )
	{
		current_angle_ -= 360.0;
	}	
}

	/**
	  * sets the opengl state
	  */
void RotationAnimationNode::setState(void)
{
	//std::cout << "set " + name_ + "\n";
	glPushMatrix(); //std::cout << "glPushMatrix()\n";
	//glTranslated( 0.0, 0.0, 25.0 );
	glRotated( current_angle_, rotation_vector_[X], rotation_vector_[Y], rotation_vector_[Z] );
	//std::cout << "glRotated(" << current_angle_ << "," << rotation_vector_[X] << "," << rotation_vector_[Y] << ","  << rotation_vector_[Z] << ")\n";
	//glTranslated( 0.0, 0.0, -25.0 );
	//glRotated( current_angle_, rotation_vector_[X], rotation_vector_[Y], rotation_vector_[Z] );
}

	/**
	  * render this node using opengl
	  */
void RotationAnimationNode::draw(void)
{
	
}


	/**
	  * unsets the state set by the setState SceneGraphNode#setState method
	  */
void RotationAnimationNode::unsetState(void)
{
	//std::cout << "unset " + name_ + "\n";
	glPopMatrix(); //std::cout << "glPopMatrix()\n";
}