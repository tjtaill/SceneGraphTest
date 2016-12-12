#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
/**
  *@file GraphTypes.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 2, 2007
  *This contains the basic type of the scene grap back end representation
  */

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, 
	boost::property<boost::vertex_name_t, std::string >, boost::no_property > graph_type;

typedef boost::graph_traits< graph_type >::vertex_descriptor vertex_descriptor;



enum NodeType 
{ 
	GroupNodeType,
	SolidSphereNodeType,
	TranslationNodeType,
	TextureNodeType,
	RotationAnimationNodeType
};

enum ColorIndexType { RedIndex, GreenIndex, BlueIndex, AlphaIndex };

enum CoordinateIndexType { X, Y, Z, W };



