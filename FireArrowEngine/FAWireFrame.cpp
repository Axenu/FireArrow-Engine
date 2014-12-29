//
//  FAWireFrame.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 08/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAWireFrame.h"


FAWireFrame::FAWireFrame() {
    this->setName("FAModel");
    this->setColor(glm::vec4(0.5,0.5,0.5,1));
    this->setScale(1);
}

void FAWireFrame::setShader(FAShader *shader) {
    
    shader = new FAShader("Simple");
    
	glUseProgram(shader->shaderProgram);
    
    positionLocation = glGetAttribLocation(shader->shaderProgram, "in_Position");
    
    // Get matrices uniform locations
    colorUniformLocation = glGetUniformLocation(shader->shaderProgram, "color");
    projectionMatrixLocation = glGetUniformLocation(shader->shaderProgram,"projectionMatrix");
    viewMatrixLocation = glGetUniformLocation(shader->shaderProgram, "viewMatrix");
    modelMatrixLocation = glGetUniformLocation(shader->shaderProgram, "modelMatrix");
    
    
    
    if(positionLocation == -1) {
        std::cout << "error positionLocation" << std::endl;
    }
    if(colorUniformLocation == -1) {
        std::cout << "error colorUniformLocation" << std::endl;
    }
    if(projectionMatrixLocation == -1) {
        std::cout << "error projectionMatrixLocation" << std::endl;
    }
    if(viewMatrixLocation == -1) {
        std::cout << "error viewMatrixLocation" << std::endl;
    }
    if(modelMatrixLocation == -1) {
        std::cout << "error modelMatrixLocation" << std::endl;
    }
}

void FAWireFrame::setColor(glm::vec4 c) {
    color = c;
}

void FAWireFrame::SetModel(glm::vec3 v[8]) {
	
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
	
    if (shader->shaderProgram == 0) {
        std::cout << "No valid shader for model" << std::endl;
        return;
    }
    
    GLfloat vertices[24];
    for (int i = 0; i < 8; i++) {
        vertices[i * 3] = v[i].x;
        vertices[i * 3 + 1] = v[i].y;
        vertices[i * 3 + 2] = v[i].z;
    }
    
    GLushort indices[24] = {
        0,1, 0,2, 0,4,
        3,1, 3,2, 3,7,
        6,2, 6,4, 6,7,
        5,1, 5,4, 5,7
    };
    
    numberOfVertices = 24;
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(GLfloat), &vertices[0], GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 24 * sizeof(GLushort), &indices[0], GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glEnableVertexAttribArray(positionLocation);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void FAWireFrame::onRender(FACamera *camera) {
    
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(positionLocation);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glUseProgram(shader->shaderProgram);
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);
    
    glDrawElements(GL_LINES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(positionLocation);
    glBindVertexArray(0);
    
    glUseProgram(0);
    
}

void FAWireFrame::onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix) {
    glDisable(GL_CULL_FACE);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(positionLocation);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glUseProgram(shader->shaderProgram);
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);
    
    glDrawElements(GL_LINES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(positionLocation);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glUseProgram(0);
    glEnable(GL_CULL_FACE);
}

void FAWireFrame::onUpdate(float dt, glm::mat4 m) {
    
}


FAWireFrame::~FAWireFrame() {
    //dealloc
}