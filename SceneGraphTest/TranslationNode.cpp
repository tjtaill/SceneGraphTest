#include "StdAfx.h"
#include "TranslationNode.h"
#include <GL/glut.h>

TranslationNode::TranslationNode(double x, double y, double z,
								 std::string name) :
	SceneGraphNode(name, TranslationNodeType )
{
	translationVector_[X] = x;
	translationVector_[Y] = y;
	translationVector_[Z] = z;
	

}

TranslationNode::~TranslationNode(void)
{
	
}

void TranslationNode::setState(void)
{
	
	glPushMatrix(); 
	glTranslated( translationVector_[X], translationVector_[Y], translationVector_[Z] );
	
}

void TranslationNode::draw(void)
{

}

void TranslationNode::unsetState(void)
{
	
	glPopMatrix(); 
}