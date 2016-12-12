#include "StdAfx.h"
#include "TextureNode.h"
#include <boost/shared_ptr.hpp>

#include <GL/glaux.h>


void TextureNode::loadTexture( std::string textureFileName )
{
	boost::shared_ptr<AUX_RGBImageRec> Image( auxDIBImageLoadA( textureFileName.c_str() ) );
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Image->sizeX, 
		Image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Image->data);
	
	
	
	
}

TextureNode::TextureNode(std::string textureFilename, std::string name) :
	SceneGraphNode( name, TextureNodeType )
{
	glGenTextures(1, &texture[0]);
	GLenum error = glGetError();
	loadTexture( textureFilename );



}

TextureNode::~TextureNode(void)
{
	glDeleteTextures(1, &texture[0] );
}

// glGetIntegerv((_textureTarget == GL_TEXTURE_RECTANGLE_EXT ? GL_TEXTURE_BINDING_RECTANGLE_EXT : GL_TEXTURE_BINDING_2D), &saveTextureName);
void TextureNode::setState(void)
{
	//std::cout << "set " + name_ + "\n";
	// get old settings
	glGetIntegerv( GL_TEXTURE_2D, &previous_texture[0] );
	glGetTexParameteriv( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, &previous_texture_mag_filter[0]);
	glGetTexParameteriv( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &previous_texture_min_filter[0]);

	// set new settings
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void TextureNode::unsetState(void)
{
	//std::cout << "unset " + name_ + "\n";
	// restore old settings
	glBindTexture(GL_TEXTURE_2D, previous_texture[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, previous_texture_mag_filter[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, previous_texture_min_filter[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
}