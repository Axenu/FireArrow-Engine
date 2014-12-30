//
//  FACamera.h
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FACamera__
#define __FireArrow__FACamera__

#include <iostream>
//#include <glm/gtc/>
//#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include "FAPrint.h"

#define forwardVector glm::vec3(0,1,0)

class FACamera {
    
private:
    glm::vec3 position;
    glm::vec3 rotation;
    float fieldOfView;
    float aspectRatio;
    float nearPlane;
    float farPlane;
    float width;
    float heigth;
    bool perspective;
    
public:
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    
    FACamera();
    FACamera(float fov, float aspect, float near, float far);
    FACamera(float width, float height);
    FACamera(float fov, int _width, int _heigth, float near, float far);
    void useView();
    void initProjection();
    
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setPosition(glm::vec3 p);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);
    void move(glm::vec3 p);
    void rotateX(float f);
    void rotateY(float f);
    void rotateZ(float f);
    void setRX(float rx);
    void setRY(float ry);
    void setRZ(float rz);
	
    float getX();
    float getY();
    float getZ();
    glm::vec3 getPosition();
    float getRX();
    float getRY();
    float getRZ();
    float getRXD();
    float getRYD();
    float getRZD();
    float getNearPlane();
    float getFarPlane();
    float getFieldOfView();
    float getAspectRatio();
    float coTangent(float angle);
    float degreesToRadians(float degrees);
};

#endif /* defined(__FireArrow__FACamera__) */
