//
//  FATexture.h
//  FireArrow
//
//  Created by Simon Nilsson on 11/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FATexture__
#define __FireArrow__FATexture__

#define GLFW_INCLUDE_GLCOREARB
#define GLM_FORCE_RADIANS

#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include <IL/il.h>

class FATexture {
private:
public:
    static GLuint createBMPTexture(const GLchar *path);
    static GLuint createTexture(const GLchar *path);
};



#endif /* defined(__FireArrow__FATexture__) */
