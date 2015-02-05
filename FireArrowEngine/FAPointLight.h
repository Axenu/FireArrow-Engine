//
//  FAPointLight.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 02/01/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAPointLight__
#define __FireArrowEngine__FAPointLight__

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "FANode.h"

class FAPointLight : public FANode {
    
private:
    GLint positionLocation;
    GLint uvLocation;
    
    GLint diffuseTextureUniform;
    GLint normalTextureUniform;
    GLint depthTextureUniform;
    GLint positionTextureUniform;
    GLint lightPositionUniform;
    GLint lightColorUniform;
    GLint lightIntensityUniform;
    
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
    
    glm::vec4 color;
    float intensity;
    
public:
    FAPointLight();
    
    void setColor(glm::vec4 color);
    void setShader(FAShader *shader);
    void onRender(GLuint texures[4]);
    
    ~FAPointLight();
    
protected:
    
//    virtual void onRender(FACamera *camera);
//    virtual void onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix);
//    virtual void onRenderShadow(glm::mat4 c);
//    virtual void onUpdate(float dt);
};

#endif /* defined(__FireArrowEngine__FAPointLight__) */
