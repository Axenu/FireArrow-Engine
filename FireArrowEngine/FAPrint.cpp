//
//  FAPrint.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 8/9/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAPrint.h"

//template <typename T>

void print(std::string p) {
	std::cout << p << std::endl;
}
void print(GLuint p) {
	std::cout << p << std::endl;
}
void print(int p) {
	std::cout << p << std::endl;
}
void print(float p) {
	std::cout << p << std::endl;
}
void print(glm::mat4x4 p) {
	std::cout << "glm::mat4x4: " << std::endl;
	std::cout << p[0][0] << ", " << p[0][1] << ", " << p[0][2] << ", " << p[0][3] << ", " << std::endl;
	std::cout << p[1][0] << ", " << p[1][1] << ", " << p[1][2] << ", " << p[1][3] << ", " << std::endl;
	std::cout << p[2][0] << ", " << p[2][1] << ", " << p[2][2] << ", " << p[2][3] << ", " << std::endl;
	std::cout << p[3][0] << ", " << p[3][1] << ", " << p[3][2] << ", " << p[3][3] << ", " << std::endl;
}
void print(glm::mat3 p) {
    std::cout << "glm::mat3: " << std::endl;
    std::cout << p[0][0] << ", " << p[0][1] << ", " << p[0][2] << std::endl;
    std::cout << p[1][0] << ", " << p[1][1] << ", " << p[1][2] << std::endl;
    std::cout << p[2][0] << ", " << p[2][1] << ", " << p[2][2] << std::endl;
}
void print(glm::mat2 p) {
    std::cout << "glm::mat2: " << std::endl;
    std::cout << p[0][0] << ", " << p[0][1] << std::endl;
    std::cout << p[1][0] << ", " << p[1][1] << std::endl;
}
void print(glm::vec4 p) {
	std::cout << "glm::vec4: " << std::endl;
	std::cout << p[0] << ", " << p[1] << ", " << p[2] << ", " << p[3] << std::endl;
}
void print(glm::vec3 p) {
	std::cout << "glm::vec3: " << std::endl;
	std::cout << p[0] << ", " << p[1] << ", " << p[2] << std::endl;
}
void print(glm::vec2 p) {
    std::cout << "glm::vec2: " << std::endl;
    std::cout << p[0] << ", " << p[1] << std::endl;
}

void print(Bone b) {
	std::cout << "Name: " << b.name << std::endl;
	std::cout << "Parent: " << b.parent << std::endl;
	std::cout << "Position: " << b.position.x << ", " << b.position.y << ", " << b.position.z << std::endl;
	std::cout << "Orientation: " << b.orientation.x << ", " << b.orientation.y << ", " << b.orientation.z << std::endl;
	std::cout << "Scale: " << b.scale.x << ", " << b.scale.y << ", " << b.scale.z << std::endl;
	std::cout << "xform: " << std::endl;
	std::cout << b.xform[0][0] << ", " << b.xform[0][1] << ", " << b.xform[0][2] << ", " << b.xform[0][3] << ", " << std::endl;
	std::cout << b.xform[1][0] << ", " << b.xform[1][1] << ", " << b.xform[1][2] << ", " << b.xform[1][3] << ", " << std::endl;
	std::cout << b.xform[2][0] << ", " << b.xform[2][1] << ", " << b.xform[2][2] << ", " << b.xform[2][3] << ", " << std::endl;
	std::cout << b.xform[3][0] << ", " << b.xform[3][1] << ", " << b.xform[3][2] << ", " << b.xform[3][3] << ", " << std::endl;
	std::cout << "comb: " << std::endl;
	std::cout << b.comb[0][0] << ", " << b.comb[0][1] << ", " << b.comb[0][2] << ", " << b.comb[0][3] << ", " << std::endl;
	std::cout << b.comb[1][0] << ", " << b.comb[1][1] << ", " << b.comb[1][2] << ", " << b.comb[1][3] << ", " << std::endl;
	std::cout << b.comb[2][0] << ", " << b.comb[2][1] << ", " << b.comb[2][2] << ", " << b.comb[2][3] << ", " << std::endl;
	std::cout << b.comb[3][0] << ", " << b.comb[3][1] << ", " << b.comb[3][2] << ", " << b.comb[3][3] << ", " << std::endl;
}