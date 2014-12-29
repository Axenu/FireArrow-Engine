//
//  FAPrint.h
//  FireArrow
//
//  Created by Simon Nilsson on 8/9/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAPrint__
#define __FireArrow__FAPrint__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

//template <typename T>



struct Bone {
	glm::vec3 orientation;
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 xform;
	glm::mat4 comb;
	std::string name;
	Bone *parent;
	std::vector<Bone *> children;
};

void print(std::string p);
void print(GLint p);
void print(GLuint p);
void print(int p);
void print(float p);
void print(glm::mat4x4 p);
void print(glm::mat3 p);
void print(glm::mat2 p);
void print(glm::vec4 p);
void print(glm::vec3 p);
void print(glm::vec2 p);
void print(Bone b);

#endif /* defined(__FireArrow__FAPrint__) */
