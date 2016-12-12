#pragma once
#include "scenegraphnode.h"
/**
  *@file TranslationNode.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *
  */

/**
  *@class TranslationNode
  *This class is a simple parametrized open gl translation that applies to only its children
  */
class TranslationNode :
	public SceneGraphNode
{
private:
	double translationVector_[3];

public:
	TranslationNode(double x, double y, double z, std::string name = "TranslationNode");
	virtual ~TranslationNode(void);
	virtual void setState(void);
	virtual void draw(void);
	virtual void unsetState(void);
};
