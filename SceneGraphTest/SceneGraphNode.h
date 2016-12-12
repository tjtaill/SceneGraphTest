#pragma once
#include <string>
#include "GraphTypes.h"
#include <ostream>

/**
  * @file SceneGraphNode.h
  * @author Troy Taillefer
  * @date December 2, 2007
  * @version 0.1
  * 
  */

/**
  *@class SceneGraphNode
  *This class is the base class for all the scene graph nodes
  */
class SceneGraphNode
{
private:
	

	// the node type
	NodeType nodeType_;

	

	// the node unique id assigned by the graph
	vertex_descriptor id_;

	// if this node is inserted into graph
	bool isInserted_;

protected:
	// the descriptive name of the node
	std::string name_;

	// disable default constructor
	SceneGraphNode(void) {};

	/**
	  *@param name the descriptive name of the node
	  *@param nodeType The enumerated type of the node
	  *Constructor that should only be called by derived classes
	  */
	SceneGraphNode(std::string name, NodeType nodeType);

public:
	/**
	  * destructor virtual so that the children constructor will be called
	  */
	virtual ~SceneGraphNode(void);

	/**
	  *@return the descriptive name of the node
	  *
	  */
	std::string getName(void);

	/**
	  *@return the unique identifier of this node
	  */
	vertex_descriptor getId(void);

	/**
	  *@warning this method should only be called once by the scene graph
	  *@todo consider making this private / protected and making the scene graph a friend
	  *set the unique identifier 
	  *
	  */
	void setId( vertex_descriptor id );
	
	/**
	  *@return true if inserted into the scene graph otherwise false
	  */
	bool getIsInserted(void);

	/**
	  *@warning this method should only be called when added or removed from the scene graph
	  *@todo consider making this private / protected and making the scene graph a friend
	  *set the status of this node to inserted in the scene graph 
	  *
	  */
	void setIsInserted(bool isInserted);

	/**
	  *@return the node type
	  */
	NodeType getNodeType(void);

	// time to scenegraph a pure virtual class only able to be sublcassed

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

	friend std::ostream& operator <<(std::ostream &os, const SceneGraphNode &obj);

	std::string toString(void) const;

};
