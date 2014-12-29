//
//  FASpatial.h
//  FireArrow
//
//  Created by Simon Nilsson on 14/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FASpatial__
#define __FireArrow__FASpatial__

#include <iostream>
#include "FACamera.h"
#include "FATexture.h"
#include "FAShader.h"

class FASpatial {
    
private:
    glm::mat4 modelMatrix;
    FATexture texture;
    FAShader shader;
    glm::vec3 position;
    glm::vec3 boundingBox;
    
public:
    void update(float dt);
    void render(FACamera camera);
    void render(glm::vec3 p, FACamera camera);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setPos(glm::vec3 pos);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);
    void move(glm::vec3 p);
    float getX();
    float getY();
    float getZ();
    glm::vec3 getPos();
    
protected:
    virtual void onUpdate(float dt) {}
    virtual void onRender(FACamera camera) {
        std::cout << "Render called in FASpatial first!" << std::endl;}
    virtual void onRender(glm::vec3 p, FACamera camera) {
        std::cout << "Render called in FASpatial second!" << std::endl;}
};

#endif /* defined(__FireArrow__FASpatial__) */
