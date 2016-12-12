#include "stdafx.h"

/**
  *@file TranslationNode.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 11, 2007
  *This file contains the unit tests generated during developement
  *uncomment the code make sure any other main function is commented
  * compile and then run
  */

/*

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/auto_unit_test.hpp>
#include "GroupNode.h"
#include "SceneGraph.h"
#include <boost/shared_ptr.hpp>
#include <iostream>
#include "ListGraphVisitor.h"
BOOST_AUTO_TEST_CASE( scene_graph_stream_operator_test )
{
	GroupNode groupNode( "My Node" );
	std::ostringstream os;
	os << groupNode;
	BOOST_REQUIRE( "Node{My Node,0,GroupNode}" 
		== os.str() );
	
}

BOOST_AUTO_TEST_CASE( scene_graph_add_root_node_test )
{
	boost::shared_ptr< SceneGraphNode > pSceneGraphNode( new GroupNode( "My Node" ) ), 
		pRetrievedNode;
	SceneGraph sceneGraph;
	sceneGraph.addRootNode( pSceneGraphNode );
	pRetrievedNode = sceneGraph.getNode(0);
	BOOST_REQUIRE( pSceneGraphNode->getId() == pRetrievedNode->getId() );
}

BOOST_AUTO_TEST_CASE( scene_graph_add_node_test )
{
	boost::shared_ptr< SceneGraphNode > pParentNode( new GroupNode( "Parent Node" ) ), 
		pChildNode( new GroupNode( "Child Node" ) );
	SceneGraph sceneGraph;
	sceneGraph.addRootNode( pParentNode );
	sceneGraph.addNode(pParentNode, pChildNode);
	BOOST_REQUIRE( pParentNode->getId() != pChildNode->getId() ); 
}



BOOST_AUTO_TEST_CASE( print_vertices_test )
{
	using namespace boost;
	typedef shared_ptr< SceneGraphNode > node_pointer_type;
	node_pointer_type family_node( new GroupNode("Family") );
	node_pointer_type troy_node( new GroupNode("Troy") );
	node_pointer_type vivian_node( new GroupNode("Vivian") );
	node_pointer_type gail_node( new GroupNode("Gail") );
	node_pointer_type chris_node( new GroupNode("Chris") );
	node_pointer_type travis_node( new GroupNode("Travis") );
	node_pointer_type diane_node( new GroupNode("Diane") );
	node_pointer_type joyce_node( new GroupNode("Joyce") );
	node_pointer_type mah_node( new GroupNode("Mah") );
	node_pointer_type wang_node( new GroupNode("Wang") );
	SceneGraph sceneGraph;
	sceneGraph.addRootNode( family_node );
	sceneGraph.addNode( family_node, troy_node );
	sceneGraph.addNode( family_node, vivian_node );
	sceneGraph.addNode( family_node, gail_node );
	sceneGraph.addNode( family_node, chris_node );
	sceneGraph.addNode( family_node, travis_node );
	sceneGraph.addNode( family_node, diane_node );
	sceneGraph.addNode( family_node, mah_node );
	sceneGraph.addNode( family_node, joyce_node );
	sceneGraph.addNode( family_node, wang_node );
	std::string testString = "Node{Family,0,GroupNode}\n";
	testString += "Node{Troy,1,GroupNode}\n";
	testString += "Node{Vivian,2,GroupNode}\n";
	testString += "Node{Gail,3,GroupNode}\n";
	testString += "Node{Chris,4,GroupNode}\n";
	testString += "Node{Travis,5,GroupNode}\n";
	testString += "Node{Diane,6,GroupNode}\n";
	testString += "Node{Mah,7,GroupNode}\n";
	testString += "Node{Joyce,8,GroupNode}\n";
	testString += "Node{Wang,9,GroupNode}\n";
	std::string aString = sceneGraph.listNodes( );
	BOOST_REQUIRE( testString == aString );
}

BOOST_AUTO_TEST_CASE( pretty_print_vertices_test )
{
	using namespace boost;
	shared_ptr<SceneGraph> pGraph( new SceneGraph() );
	typedef shared_ptr< SceneGraphNode > node_pointer_type;
	typedef graph_traits< graph_type >::vertices_size_type size_type;
	node_pointer_type family_node( new GroupNode("Family") );
	node_pointer_type gail_node( new GroupNode("Gail") );
	node_pointer_type troy_node( new GroupNode("Troy") );
	node_pointer_type chris_node( new GroupNode("Chris") );
	node_pointer_type travis_node( new GroupNode("Travis") );
	node_pointer_type joyce_node( new GroupNode("Joyce") );

	pGraph->addRootNode( family_node );
	pGraph->addNode( family_node, gail_node );
	pGraph->addNode( gail_node, troy_node );
	pGraph->addNode( gail_node, chris_node );
	pGraph->addNode( gail_node, travis_node );
	pGraph->addNode( troy_node, joyce_node );

	ListGraphVisitor lgv( pGraph );

	depth_first_search( pGraph->getGraph(), visitor(lgv) );

	std::string test_string = "\nNode{Family,0,GroupNode}";
    test_string += "\n\tNode{Gail,1,GroupNode}";
	test_string += "\n\t\tNode{Troy,2,GroupNode}";
	test_string += "\n\t\t\tNode{Joyce,5,GroupNode}";
    test_string += "\n\t\tNode{Chris,3,GroupNode}";
    test_string += "\n\t\tNode{Travis,4,GroupNode}";
	

	BOOST_REQUIRE(  test_string == lgv.getGraphList() );
}

BOOST_AUTO_TEST_CASE( write_dot_test )
{
	using namespace boost;
	shared_ptr<SceneGraph> pGraph( new SceneGraph() );
	typedef shared_ptr< SceneGraphNode > node_pointer_type;
	typedef graph_traits< graph_type >::vertices_size_type size_type;
	node_pointer_type family_node( new GroupNode("Family") );
	node_pointer_type gail_node( new GroupNode("Gail") );
	node_pointer_type troy_node( new GroupNode("Troy") );
	node_pointer_type chris_node( new GroupNode("Chris") );
	node_pointer_type travis_node( new GroupNode("Travis") );
	node_pointer_type joyce_node( new GroupNode("Joyce") );

	pGraph->addRootNode( family_node );
	pGraph->addNode( family_node, gail_node );
	pGraph->addNode( gail_node, troy_node );
	pGraph->addNode( gail_node, chris_node );
	pGraph->addNode( gail_node, travis_node );
	pGraph->addNode( troy_node, joyce_node );

	std::string testString = "digraph G {\n";
	testString += "Family;\n";
	testString += "Gail;\n";
	testString += "Troy;\n";
	testString += "Chris;\n";
	testString += "Travis;\n";
	testString += "Joyce;\n";
	testString += "Family->Gail ;\n";
	testString += "Gail->Troy ;\n";
	testString += "Gail->Chris ;\n";
	testString += "Gail->Travis ;\n";
	testString += "Troy->Joyce ;\n";
	testString += "}\n";

	BOOST_REQUIRE(  testString == pGraph->getDotGraph() );
}
*/
