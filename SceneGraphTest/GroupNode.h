#pragma once
#include "scenegraphnode.h"

/**
  * @file GroupNode.h
  * @author Troy Taillefer
  * @date December 7, 2007
  * @version 0.1
  * 
  */

/**
  *@class GroupNode
  *This is a simple grouping node that is used to gather nodes together
  *it implementation of setState and draw are the default empty it is node
  * thats name captures the semantics of grouping other nodes
  */
class GroupNode :
	public SceneGraphNode
{
protected:
	// disable default constructor
	GroupNode(void) {};

public:
	/**
	  *@param name the descriptive name of the node
	  *constructor
	  */
	GroupNode( std::string name );

	/**
	  * destructor
	  */
	virtual ~GroupNode(void);

};
