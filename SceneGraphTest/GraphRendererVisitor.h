#pragma once

#include <boost/graph/depth_first_search.hpp>
#include <boost/shared_ptr.hpp>
#include "SceneGraph.h"
#include <vector>

/**
  *@file GraphRendererVisitor.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *
  */

/**
  *@class GraphRendererVisitor
  *This class implements the scene graph traversal in depth first order with backtracking 
  *and uses the visitor pattern
  */

class GraphRendererVisitor :
	public boost::default_dfs_visitor
{
private:
	boost::shared_ptr<SceneGraph> graph_;

public:
	std::vector<boost::default_color_type> T;
	GraphRendererVisitor( boost::shared_ptr<SceneGraph> graph );
	virtual ~GraphRendererVisitor(void);

	/**
	  *@param v a vertex index which points to which vertex/node is discovered
	  *@param g a reference to the graph being traversed
	  *this method is called by the depth first traversal algorithm every time a node is
	  *discovered it builds the graph string as a stream
	  */
	void discover_vertex(vertex_descriptor v, const graph_type& g);

	/**
	  *@param v a vertex index which points to which vertex/node is discovered
	  *@param g a reference to the graph being traversed
	  *this method is called by the traversal algorithm whenever a vertex/node descendants have all been discovered
	  *it indicates that the traversal is backtracking
	  */
	void finish_vertex(vertex_descriptor v, const graph_type& g);
	;
};
