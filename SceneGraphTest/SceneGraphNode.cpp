#include "StdAfx.h"
#include "SceneGraphNode.h"
#include <boost/lexical_cast.hpp>


std::string nodeTypeToString( NodeType nodeType )
{
	std::string returnString;

	switch( nodeType )
	{
	case GroupNodeType:
		returnString = "GroupNode";
		break;
	case SolidSphereNodeType:
		returnString = "SolidSphereNode";
		break;
	case TranslationNodeType:
		returnString = "TranslationNode";
		break;
	case TextureNodeType:
		returnString = "TextureNode";
		break;
	case RotationAnimationNodeType:
		returnString = "RotationAnimationNode";
		break;
	default:
		returnString = "UnknownNode";	
	}
	return returnString;
}

SceneGraphNode::SceneGraphNode(std::string name, NodeType nodeType) 
	: name_(name), nodeType_(nodeType)
{
	isInserted_ = false;
	id_ = 0;
}

SceneGraphNode::~SceneGraphNode(void)
{
}

std::string SceneGraphNode::getName(void)
{
	return name_;
}

vertex_descriptor SceneGraphNode::getId(void)
{
	return id_;
}

void SceneGraphNode::setId( vertex_descriptor id )
{
	id_ = id;
}

bool SceneGraphNode::getIsInserted(void)
{
	return isInserted_;
}

void SceneGraphNode::setIsInserted(bool isInserted)
{
	isInserted_ = isInserted;
}

NodeType SceneGraphNode::getNodeType(void)
{
	return nodeType_;
}

void SceneGraphNode::setState(void)
{

}

void SceneGraphNode::draw(void)
{

}

void SceneGraphNode::unsetState(void)
{

}

std::ostream& operator <<(std::ostream &os, const SceneGraphNode &obj)
{
	os << obj.toString();
	return os;
}

std::string SceneGraphNode::toString(void) const
{
	std::string s = "Node{";
	s += name_;
	s += ",";
	s += boost::lexical_cast<std::string>(id_);
	s += ",";
	s += nodeTypeToString( nodeType_ );
	s += "}";
	return s;
}