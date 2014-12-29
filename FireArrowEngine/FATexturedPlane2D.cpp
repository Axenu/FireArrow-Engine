//
//  FATexturedPlane2D.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 25/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FATexturedPlane2D.h"

FATexturedPlane2D::FATexturedPlane2D() {
    
    this->setName("2D Textured Plane");
    this->position = glm::vec3(0,0,0);
}

void FATexturedPlane2D::setShader(FAShader *shader) {
    this->shader = shader;
    
    glUseProgram(shader->shaderProgram);
    
    textureLoc = glGetAttribLocation(shader->shaderProgram, "in_textureCoord");
    positionLoc = glGetAttribLocation(shader->shaderProgram, "in_position");
    
    modelMatrixUniform = glGetUniformLocation(shader->shaderProgram, "modelMatrix");
    textureUniform = glGetUniformLocation(shader->shaderProgram, "text");
    
    if(textureLoc == -1) {
        std::cout << "error textureLoc" << std::endl;
    }
    if(positionLoc == -1) {
        std::cout << "error positionLoc" << std::endl;
    }
    if(modelMatrixUniform == -1) {
        std::cout << "error modelMatrixUniform" << std::endl;
    }
    if(textureUniform == -1) {
        std::cout << "error textureUniform" << std::endl;
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
        +0.5, +0.5, 1, 1,
        -0.5, +0.5, 0, 1,
        -0.5, -0.5, 0, 0,
        +0.5, -0.5, 1, 0
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(myVAO);
    
    glEnableVertexAttribArray(positionLoc);
    glEnableVertexAttribArray(textureLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glVertexAttribPointer(positionLoc, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
    glVertexAttribPointer(textureLoc, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) (2 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void FATexturedPlane2D::setTexture(GLuint text) {
    texture = text;
}

void FATexturedPlane2D::onRender(FACamera *camera) {
    
    glBindVertexArray(myVAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture);
    
    glUseProgram(shader->shaderProgram);
    
    glUniform1i(textureUniform, 0);
    glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, &modelMatrix[0][0]);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glUseProgram(0);
}
void FATexturedPlane2D::onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix) {
    onRender(camera);
}
void FATexturedPlane2D::onUpdate(float dt, glm::mat4 m) {
}

FATexturedPlane2D::~FATexturedPlane2D() {
    
}