//
//  FAWireFrame.h
//  FireArrow
//
//  Created by Simon Nilsson on 08/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAWireFrame__
#define __FireArrow__FAWireFrame__

#include <stdio.h>

#include "FANode.h"

class FAWireFrame : public FANode {
    
private:
    GLuint positionLocation;
    GLuint colorUniformLocation;
    GLuint projectionMatrixLocation;
    GLuint viewMatrixLocation;
    GLuint modelMatrixLocation;
    
    GLuint VBO;
    GLuint EBO;
    GLuint VAO;
    
    glm::vec4 color;
    GLuint numberOfVertices;
    
public:
    FAWireFrame();
    ~FAWireFrame();
    void setShader(FAShader *shader);
    void SetModel(glm::vec3 v[8]);
    void setColor(glm::vec4 c);
    
protected:
    virtual void onRender(FACamera *camera);
    virtual void onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix);
    virtual void onUpdate(float dt, glm::mat4 m);
};

#endif /* defined(__FireArrow__FAWireFrame__) */
