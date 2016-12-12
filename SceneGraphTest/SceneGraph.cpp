#include "StdAfx.h"
#include "SceneGraph.h"
#include <cassert>
#include <boost/tuple/tuple.hpp>


SceneGraph::SceneGraph(void)
{
	name_property_map_ = boost::get(boost::vertex_name, graph_);
}

SceneGraph::~SceneGraph(void)
{
}

void SceneGraph::addRootNode( boost::shared_ptr< SceneGraphNode > rootNode )
{
	// Therecan only be one root node
	vertices_size_type vertices = boost::num_vertices( graph_ );
	assert( 0 == vertices && 0 == nodes_.size() );

	vertex_descriptor d = boost::add_vertex(graph_);
	rootNode->setId( d );

	// add the node to the property name map
	boost::put(name_property_map_, d, rootNode->getName()); 
	//name_property_map_[d] = rootNode->getName();

	nodes_.push_back( rootNode );
	rootNode->setIsInserted( true );
}

void  SceneGraph::addNode( boost::shared_ptr< SceneGraphNode > parentNode, 
			 boost::shared_ptr< SceneGraphNode > childNode )
{
	vertex_descriptor pid = parentNode->getId();

	// The parent should in the graph and the child should not
	assert( parentNode->getIsInserted() && !childNode->getIsInserted() );

	vertex_descriptor cid = boost::add_vertex(graph_);
	childNode->setId( cid );
	
	// put the node name in the property map
	boost::put(name_property_map_, cid, childNode->getName());
	//name_property_map_[cid] = childNode->getName();

	boost::add_edge(pid, cid, graph_);
	nodes_.push_back( childNode );
	childNode->setIsInserted( true );
}
	

boost::shared_ptr< SceneGraphNode >  SceneGraph::getNode( vertex_descriptor id )
{
	return nodes_[id];
}

std::string SceneGraph::listNodes( void )
{
	vertex_iterator begin, end, it;
	std::ostringstream os;
	tie(begin, end) = vertices( graph_ );
	for( it = begin; it != end; it++)
	{
		os << *(nodes_[*it]);
		os << "\n";
	}
	return os.str();
}

const graph_type SceneGraph::getGraph(void)
{
	return graph_;
}



std::string SceneGraph::getDotGraph(void)
{
	std::ostringstream os;
	boost::dynamic_properties dp;
	dp.property("id", boost::get(boost::vertex_name, graph_));
	boost::write_graphviz(os, graph_, dp, std::string("id"));
	return os.str();
}
