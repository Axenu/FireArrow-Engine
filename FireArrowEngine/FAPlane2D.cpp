//
//  FAPlane2D.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 05/07/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAPlane2D.h"

FAPlane2D::FAPlane2D() {
    
    this->setName("2D Plane");
    this->position = glm::vec3(0,0,0);
}


void FAPlane2D::setColor(glm::vec4 c) {
	color = c;
}

void FAPlane2D::setSize(float width, float height) {
    this->scale.x = width;
    this->scale.y = height;
}

void FAPlane2D::setShader(FAShader *shader) {
    this->shader = shader;
    
    glUseProgram(shader->shaderProgram);
    
    positionLoc = glGetAttribLocation(shader->shaderProgram, "in_position");
	
	colorUniform = glGetUniformLocation(shader->shaderProgram, "color");
	modelMatrixUniform = glGetUniformLocation(shader->shaderProgram, "modelMatrix");
	
	if(positionLoc == -1) {
		std::cout << "error positionLoc" << std::endl;
	}
    if(colorUniform == -1) {
        std::cout << "error colorUniform" << std::endl;
	}
    if(modelMatrixUniform == -1) {
        std::cout << "error modelMatrixUniform" << std::endl;
    }
	
    glUseProgram(0);
    
    glGenBuffers(1, &myVBO);
    glGenBuffers(1, &myEBO);
    glGenVertexArrays(1, &myVAO);
    
    std::vector<GLushort> indices = {
        0, 1, 2,
        0, 2, 3,
    };
    std::vector<GLfloat> vertices = {
        +1, +1,
        -1, +1,
        -1, -1,
        +1, -1,
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(myVAO);
    
    glEnableVertexAttribArray(positionLoc);
	
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glVertexAttribPointer(positionLoc, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void FAPlane2D::onRender(FACamera *camera) {
	glBindVertexArray(myVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
	
	glUseProgram(shader->shaderProgram);
	glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniform4f(colorUniform, color.r, color.g, color.b, color.a);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glUseProgram(0);
}
void FAPlane2D::onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix) {
	onRender(camera);
}
void FAPlane2D::onUpdate(float dt) {
}

FAPlane2D::~FAPlane2D() {
    
}