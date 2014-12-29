//
//  FAShader.h
//  FireArrow
//
//  Created by Simon Nilsson on 10/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAShader__
#define __FireArrow__FAShader__

#define GLFW_INCLUDE_GLCOREARB
#define GLM_FORCE_RADIANS

#include <iostream>
#include <fstream>
#include <streambuf>
#include <GLFW/glfw3.h>

class FAShader {
    
private:
    void setupLocations();
    
public:
    FAShader(const GLchar *vertPath, const GLchar *fragPath);
    FAShader(const GLchar *vertPath, const GLchar *geomPath, const GLchar *fragPath);
	FAShader(std::string path);
    FAShader();
    GLuint createShader(const GLchar *path, GLenum shaderType);
    std::string getName();
    void deleteShader();
    GLuint shaderProgram;
    
    GLint positionLocation;
    GLint normalLocation;
    GLint uvLocation;
    GLint colorLocation;

private:
    GLuint vertShader;
    GLuint geomShader;
    GLuint fragShader;
    std::string name;
};

#endif /* defined(__FireArrow__FAShader__) */
