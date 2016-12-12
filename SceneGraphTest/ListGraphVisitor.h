#pragma once

#include <boost/graph/depth_first_search.hpp>
#include <boost/shared_ptr.hpp>
#include "SceneGraph.h"
#include <string>
#include <vector>

/**
  * @file ListGraphVisitor.h
  * @author Troy Taillefer
  * @date December 7, 2007
  * @version 0.1
  * @todo refactor the implementation into a cpp file this class was originally a template class
  *
  */


/**
  *@class ListGraphVisitor
  *This class list the node in the order they would be encountered depth first
  *and builds a formatted string using newline and tab characters to show the
  *structure of the graph it follows a variant of the visitor desing pattern
  */
class ListGraphVisitor :
	public boost::default_dfs_visitor
{
private:
	int tabs_;
	boost::shared_ptr<std::stringstream> stream_;
	std::string graphString_;
	boost::shared_ptr<SceneGraph> graph_;
	
public:
	/**
	  *a color map required by the depth first traversal algorithm
	  */
	std::vector<boost::default_color_type> T;

	/**
	  * constructor
	  */
	ListGraphVisitor( boost::shared_ptr<SceneGraph> graph ) : 
		tabs_(-1),
		stream_(new std::stringstream()),
		graph_(graph)
	{
		
		
	}
	

	
	/**
	  *destructor
	  */
	~ListGraphVisitor(void)
	{

	}
	
	/**
	  *@param v a vertex index which points to which vertex/node is discovered
	  *@param g a reference to the graph being traversed
	  *this method is called by the depth first traversal algorithm every time a node is
	  *discovered it builds the graph string as a stream
	  */
	void discover_vertex(vertex_descriptor v, const graph_type& g)
	{	
		
		*stream_ << "\n";
		tabs_++;
		for( int i = 0; i < tabs_; i++)
			*stream_ << "\t";
		
		*stream_ << graph_->getNode(v)->toString();
		
	}

	/**
	  *@param v a vertex index which points to which vertex/node is discovered
	  *@param g a reference to the graph being traversed
	  *this method is called by the traversal algorithm whenever a vertex/node descandants have all been discovered
	  *it indicates that the traversal is backtracking
	  */
	void finish_vertex(vertex_descriptor v, const graph_type& g)
	{	
		tabs_--;
	}

	/**
	  *@return the formatted string of the graph
	  *
	  */
	std::string getGraphList(void)
	{
		return stream_->str();
	}

};
