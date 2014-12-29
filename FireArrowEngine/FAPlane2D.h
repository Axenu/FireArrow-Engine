//
//  FAPlane2D.h
//  FireArrow
//
//  Created by Simon Nilsson on 05/07/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAPlane2D__
#define __FireArrow__FAPlane2D__

#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
#include "FAHUDElement.h"

class FAPlane2D : public FAHUDElement {
private:
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
    GLint positionLoc;
	
	GLint colorUniform;
	GLint modelMatrixUniform;
	
    glm::vec4 color;
	
    const GLushort numberOfVertices = 4;
    
public:
    
    FAPlane2D();
    ~FAPlane2D();
    void setShader(FAShader *shader);
    void setColor(glm::vec4 c);
    void setSize(float width, float height);
	
protected:
	virtual void onRender(FACamera *amera);
	virtual void onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix);
    virtual void onUpdate(float dt);
    
};
#endif /* defined(__FireArrow__FAPlane2D__) */
