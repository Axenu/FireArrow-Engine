//
//  FAPlane3D.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 02/02/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAPlane3D__
#define __FireArrowEngine__FAPlane3D__

#define GLFW_INCLUDE_GLCOREARB

#include <stdio.h>
#include <GLFW/glfw3.h>
#include "FANode.h"

class FAPlane3D : public FANode {
    
    //opengl:
    
    GLuint VBO;
    GLuint EBO;
    GLuint VAO;
    
    GLint positionLocation;
    GLint normalLocation;
    GLint colorUniformLocation;
    GLint cameraPositionUniformLocation;
    GLint projectionMatrixLocation;
    GLint viewMatrixLocation;
    GLint modelMatrixLocation;
    
    const unsigned short numberOfVertices = 6;
    glm::vec4 color;
    
    
public:
    FAPlane3D();
    
    void setShader(FAShader *shader);
    void setColor(glm::vec4 color);
    
    
protected:
    virtual void onRender(FACamera *camera);
    virtual void onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix);
//    virtual void onRenderShadow(glm::mat4 c);
//    virtual void onUpdate(float dt);
};

#endif /* defined(__FireArrowEngine__FAPlane3D__) */
