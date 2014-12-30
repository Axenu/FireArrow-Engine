//
//  FATexturedPlane2D.h
//  FireArrow
//
//  Created by Simon Nilsson on 25/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FATexturedPlane2D__
#define __FireArrow__FATexturedPlane2D__

#include <stdio.h>

#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
#include "FAShader.h"
#include "FAHUDElement.h"

class FATexturedPlane2D : public FAHUDElement {
private:
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
    GLint positionLoc;
    GLint textureLoc;
    
    GLint textureUniform;
    GLint modelMatrixUniform;
    GLint layeruniform;
    
    GLuint texture;
    
    const GLushort numberOfVertices = 4;
    int h[3];
    int layer = 0;
    
public:
    
    FATexturedPlane2D();
    ~FATexturedPlane2D();
    void setShader(FAShader *shader);
    void setTexture(GLuint text);
    void setLayer(int i);
    
protected:
    virtual void onRender(FACamera *camera);
    virtual void onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix);
    virtual void onUpdate(float dt, glm::mat4 m);
    
};

#endif /* defined(__FireArrow__FATexturedPlane2D__) */
