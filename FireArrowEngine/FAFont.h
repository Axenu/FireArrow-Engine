//
//  FAFont.h
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAFont__
#define __FireArrow__FAFont__
#define GLM_FORCE_RADIANS
#define GLFW_INCLUDE_GLCOREARB

#include <ft2build.h>
#include <freetype.h>
#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class FAFont {
    
private:
    float fontSize;
	float fontHeight;
	
public:
    uint windowWidth;
    uint windowHeight;
    GLuint texture[256];
    FT_Face face;
    
    FAFont();
    FAFont(const char *path, const int _fontSize);
	FAFont(const char *path, const int _fontSize, uint _windowWidth, uint _windowHeight);
    ~FAFont();
    void loadCharacters();
	
	float getFontSize();
	float getFontHeight();
};

#endif /* defined(__FireArrow__FAFont__) */
