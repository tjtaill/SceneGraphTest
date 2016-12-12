#pragma once
#include "scenegraphnode.h"
#include <GL/glut.h>

/**
  *@file TextureNode.h
  *@author Troy Taillefer
  *@version 0.1
  *@date Decemeber 8, 2007
  *
  */

/**
  *@class TextureNode
  *@warning the glut application must be initialized before this node will work
  *This class loads a texture from a bmp file and applies it to child nodes
  */
class TextureNode :
	public SceneGraphNode
{
private:
	GLuint texture[1]; 
	GLint previous_texture[1];
	GLboolean was_textures_enabled;
	GLint previous_texture_mag_filter[1]; 
	GLint previous_texture_min_filter[1];

	void loadTexture( std::string textureFileName );

public:
	TextureNode(std::string textureFilename, std::string name = "TextureNode");
	virtual ~TextureNode(void);
	virtual void setState(void);
	virtual void draw(void){};
	virtual void unsetState(void);
};

