// SceneGraphTest.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <boost/shared_ptr.hpp>
#include "SceneGraph.h"
#include "GraphRenderer.h"
#include "SolidSphereNode.h"
#include "TranslationNode.h"
#include "GroupNode.h"
#include "TextureNode.h"
#include "GlutTimer.h"
#include "RotationAnimationNode.h"
#include <boost/bind.hpp>
#include <math.h>
#include <fstream>

// every size is calculated of the suns size
const double sun_size = 1.0;
const double sun_slices_ratio = 20.0;
const double sun_stacks_ratio = 16.0;
const double sun_slices =  ceil ( sun_size * sun_slices_ratio );
const double sun_stacks = ceil( sun_size * sun_stacks_ratio );
const double planet_slices_ratio = 10.0;
const double planet_stacks_ratio = 8.0;
const double planet_slices =  ceil ( sun_size * planet_slices_ratio );
const double planet_stacks = ceil( sun_size * planet_stacks_ratio );

//mercury ratios
const double mercury_size_ratio = 0.05;
const double mercury_distance_ratio = 0.80;

// mercury sizes
const double mercury_size = mercury_size_ratio * sun_size;
const double mercury_distance = mercury_distance_ratio * sun_size;

// venus ratios
const double venus_size_ratio = 0.1;
const double venus_distance_ratio = 1.60;

// venus sizes
const double venus_size = venus_size_ratio * sun_size;
const double venus_distance = venus_distance_ratio * sun_size;

// earth ratios
const double earth_size_ratio = 0.1;
const double earth_distance_ratio = 2.20;

//earth sizes
const double earth_size = sun_size * earth_size_ratio;
const double earth_distance = sun_size * earth_distance_ratio;

// mars ratios
const double mars_size_ratio = 0.05;
const double mars_distance_ratio = 3.20;

//mars sizes
const double mars_size = sun_size * mars_size_ratio;
const double mars_distance = sun_size * mars_distance_ratio;



// jupiter ratios
const double jupiter_size_ratio = 0.5;
const double jupiter_distance_ratio = 11.00;

//jupiter sizes
const double jupiter_size = sun_size * jupiter_size_ratio;
const double jupiter_distance = sun_size * jupiter_distance_ratio;

// saturn ratios
const double saturn_size_ratio = 0.5;
const double saturn_distance_ratio = 20.40;

//staurn sizes
const double saturn_size = sun_size * saturn_size_ratio;
const double saturn_distance = sun_size * saturn_distance_ratio;

// uranus ratios
const double uranus_size_ratio = 0.25;
const double uranus_distance_ratio = 41.2;

//uranus sizes
const double uranus_size = sun_size * uranus_size_ratio;
const double uranus_distance = sun_size * uranus_distance_ratio;

// neptune ratios
const double neptune_size_ratio = 0.25;
const double neptune_distance_ratio = 64.2;

//neptune sizes
const double neptune_size = sun_size * neptune_size_ratio;
const double neptune_distance = sun_size * neptune_distance_ratio;

// pluto ratios
const double pluto_size_ratio = 0.03;
const double pluto_distance_ratio = 84.2;

//neptune sizes
const double pluto_size = sun_size * pluto_size_ratio;
const double pluto_distance = sun_size * pluto_distance_ratio;

// scene ratios
const double scene_size_ratio = 125.0;




// scene size
const double scene_size = sun_size * scene_size_ratio;

// rotation angular step all angular steps are calculated of the earth
//const double earth_angular_step = 1.0;

// planet angular_step_ratio


int main(int argc, char** argv)
{
	using namespace boost;
	shared_ptr< SceneGraph > graph( new SceneGraph );
	GraphRenderer graphRenderer(argc, argv, scene_size, graph );
	GlutTimer timer(100);
	
	typedef shared_ptr< SceneGraphNode > node_ptr;


	/**
	  *@todo solve the rotation composition problem
	  */
	
	/*
	typedef shared_ptr< RotationAnimationNode > ra_node_ptr;
	
	node_ptr earthAnimationBase( new RotationAnimationNode( 5.0, 0.0, 1.0, 0.0, "Earth Animation" ) );
	ra_node_ptr earthAnimationDerived 
		= shared_dynamic_cast< RotationAnimationNode > ( earthAnimationBase );
	timer.time_signal_->connect( boost::bind(&RotationAnimationNode::update, earthAnimationDerived) );
	*/

	// solarSystem
	node_ptr solarSystem( new GroupNode( "SolarSystem" ) );

	// sun
	node_ptr sunTexture( new TextureNode( ".\\textures\\sun.bmp", "SunTexture" ) );
	node_ptr sun( new SolidSphereNode(sun_size, sun_slices, sun_stacks, 255, 255, 0, 0, "Sun") );

	// mercury 
	node_ptr mercuryTexture( new TextureNode( ".\\textures\\mercury.bmp", "MercuryTexture" ) );
	node_ptr translateMercury( new TranslationNode(mercury_distance, 0.0, 0.0, "TranslateMercury" ) );
	node_ptr mercury( new SolidSphereNode( mercury_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Mercury" ) );

	// venus
	node_ptr venusTexture( new TextureNode( ".\\textures\\venus.bmp", "VenusTexture" ) );
	node_ptr translateVenus( new TranslationNode(venus_distance, 0.0, 0.0, "TranslateVenus" ) );
	node_ptr venus( new SolidSphereNode( venus_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Venus" ) );

	// earth
	node_ptr earthTexture( new TextureNode( ".\\textures\\earth.bmp", "EarthTexture" ) );
	node_ptr earth( new SolidSphereNode( earth_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Earth" ) );
	node_ptr translateEarth( new TranslationNode(earth_distance, 0.0, 0.0, "TranslateEarth" ) );

	// mars
	node_ptr marsTexture( new TextureNode( ".\\textures\\mars.bmp", "MarsTexture" ) );
	node_ptr mars( new SolidSphereNode( mars_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Mars" ) );
	node_ptr translateMars( new TranslationNode(mars_distance, 0.0, 0.0, "TranslateMars" ) );
	
	// jupiter
	node_ptr jupiterTexture( new TextureNode( ".\\textures\\jupiter.bmp", "JupiterTexture" ) );
	node_ptr jupiter( new SolidSphereNode( jupiter_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Jupiter" ) );
	node_ptr translateJupiter( new TranslationNode(jupiter_distance, 0.0, 0.0, "TranslateJupiter" ) );

	// saturn
	node_ptr saturnTexture( new TextureNode( ".\\textures\\saturn.bmp", "SaturnTexture" ) );
	node_ptr saturn( new SolidSphereNode( saturn_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Saturn" ) );
	node_ptr translateSaturn( new TranslationNode(saturn_distance, 0.0, 0.0, "TranslateSaturn" ) );

	// uranus
	node_ptr uranusTexture( new TextureNode( ".\\textures\\uranus.bmp", "UranusTexture" ) );
	node_ptr uranus( new SolidSphereNode( uranus_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Uranus" ) );
	node_ptr translateUranus( new TranslationNode(uranus_distance, 0.0, 0.0, "TranslateUranus" ) );

	// neptune
	node_ptr neptuneTexture( new TextureNode( ".\\textures\\neptune.bmp", "NeptuneTexture" ) );
	node_ptr neptune( new SolidSphereNode( neptune_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Neptune" ) );
	node_ptr translateNeptune( new TranslationNode(neptune_distance, 0.0, 0.0, "TranslateNeptune" ) );

	// pluto
	node_ptr plutoTexture( new TextureNode( ".\\textures\\pluto.bmp", "PlutoTexture" ) );
	node_ptr pluto( new SolidSphereNode( pluto_size, planet_slices, planet_stacks, 255, 255, 255, 0, "Pluto" ) );
	node_ptr translatePluto( new TranslationNode(neptune_distance, 0.0, 0.0, "TranslatePluto" ) );


	// solarSystem
	graph->addRootNode( solarSystem );

	// sun
	graph->addNode( solarSystem, sunTexture );
	graph->addNode( sunTexture, sun );

	// mercury
	graph->addNode( solarSystem, translateMercury );
	graph->addNode( translateMercury, mercuryTexture );
	graph->addNode( mercuryTexture, mercury );
	
	// venus 
	graph->addNode( solarSystem, translateVenus );
	graph->addNode( translateVenus, venusTexture );
	graph->addNode( venusTexture, venus );

	// earth
	graph->addNode( solarSystem, translateEarth );
	graph->addNode( translateEarth, earthTexture );
	graph->addNode( earthTexture, earth );

	// mars
	graph->addNode( solarSystem, translateMars );
	graph->addNode( translateMars, marsTexture );
	graph->addNode( marsTexture, mars );

	// jupiter
	graph->addNode( solarSystem, translateJupiter );
	graph->addNode( translateJupiter, jupiterTexture );
	graph->addNode( jupiterTexture, jupiter );

	// saturn
	graph->addNode( solarSystem, translateSaturn );
	graph->addNode( translateSaturn, saturnTexture );
	graph->addNode( saturnTexture, saturn );

	// uranus
	graph->addNode( solarSystem, translateUranus );
	graph->addNode( translateUranus, uranusTexture );
	graph->addNode( uranusTexture, uranus );

	// neptune
	graph->addNode( solarSystem, translateNeptune );
	graph->addNode( translateNeptune, neptuneTexture );
	graph->addNode( neptuneTexture, neptune );

	// pluto
	graph->addNode( solarSystem, translatePluto );
	graph->addNode( translatePluto, plutoTexture );
	graph->addNode( plutoTexture, pluto );

	/*
	std::ofstream file("solar_system.dot");
	file << graph->getDotGraph();
	*/

	graphRenderer.EnterMainLoop();
	
	return 0;
}

