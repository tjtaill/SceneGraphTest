#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/graph/properties.hpp>
#include <boost/vector_property_map.hpp>
#include "SceneGraphNode.h"
#include "GraphTypes.h"
#include <ostream>
#include <sstream>

/**
  * @file SceneGraph.h
  * @author Troy Taillefer
  * @date December 2, 2007
  * @version 0.1
  * 
  */

/**
  *@class SceneGraph
  *This class is the scene graph
  */
class SceneGraph
{
private:
	// alias types to alleviate typing keep them private unless needed by others classes 
	// in which case they go into GraphTypes.h
	typedef boost::graph_traits< graph_type >::vertex_iterator vertex_iterator;
	typedef boost::graph_traits< graph_type >::vertex_descriptor vertex_descriptor;
	typedef boost::graph_traits< graph_type >::vertices_size_type vertices_size_type;
	typedef boost::property_map< graph_type, boost::vertex_name_t >::type name_map_type;

	// actually data members
	// the scene graph
	graph_type graph_;
	// a vector holding smart pointer to SceneGraphNodes
	std::vector< typename boost::shared_ptr<SceneGraphNode> > nodes_;
	// a property name map to store all the node names
	name_map_type name_property_map_;

	

public:
	/**
	  *Default constructor
	  */
	SceneGraph(void);

	/**
	  *Default destructor
	  */
	~SceneGraph(void);

	/**
	  *@param rootNode The node that will become the node of the scene graph
	  *@warning there can only be one root node
	  *add a root node
	  */
	void addRootNode( boost::shared_ptr< SceneGraphNode > rootNode );

	/**
	  *@param parentNode The parent node already in the scene graph
	  *@param childNode The child node to be added to the graph as a child of parent
	  *@warning the parent node must be in the graph already and the child node can not be 
	  *add a child node to the graph with a specific parent
	  */
	void addNode( boost::shared_ptr< SceneGraphNode > parentNode, 
		boost::shared_ptr< SceneGraphNode > childNode );

	/**
	  *@param id an index of which node to return
	  *@return the node indicated by the index
	  */
	boost::shared_ptr< SceneGraphNode > getNode( vertex_descriptor id );

	/**
	  *@param outputStream an output stream to write a list of nodes in the graphs to
	  */
	std::string listNodes( void );

	/**
	  *@return a graph instance to be traversed by an algorithm
	  */
	const graph_type getGraph(void);

	/**
	  *@return a string containing the graph in graphviz dot format
	  */
	std::string getDotGraph(void);
	

};
