//
//  FACamera.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FACamera.h"

FACamera::FACamera() {
    FACamera::position = glm::vec3(0,0,0);
    FACamera::rotation = glm::vec3(0,0,0);
    FACamera::fieldOfView = 70.0f;
    FACamera::aspectRatio = 1.5f;
    FACamera::nearPlane = 0.1f;
    FACamera::farPlane = 100.0f;
    perspective = true;
}
FACamera::FACamera(float fov, float aspect, float near, float far) {
    FACamera::position = glm::vec3(0,0,0);
    FACamera::rotation = glm::vec3(0,0,0);
    FACamera::fieldOfView = fov;
    FACamera::aspectRatio = aspect;
    FACamera::nearPlane = near;
    FACamera::farPlane = far;
    perspective = true;
    
    initProjection();
}
FACamera::FACamera(float width, float height) {
    FACamera::position = glm::vec3(0,0,0);
    FACamera::rotation = glm::vec3(0,0,0);
    perspective = false;
    this->width = width;
    this->heigth = height;
    this->nearPlane = -1;
    this->farPlane = 1;
    initProjection();
}
FACamera::FACamera(float fov, int _width, int _heigth, float near, float far) {
    FACamera::position = glm::vec3(0,0,0);
    FACamera::rotation = glm::vec3(0,0,0);
    perspective = true;
    width = _width;
    heigth = _heigth;
    this->nearPlane = near;
    this->farPlane = far;
    this->fieldOfView = fov;
    this->aspectRatio = width/heigth;
    initProjection();
}
void FACamera::useView() {
    viewMatrix = glm::mat4();
    viewMatrix = glm::rotate(viewMatrix, rotation.x, glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, rotation.y, glm::vec3(0, 1, 0));
    viewMatrix = glm::rotate(viewMatrix, rotation.z, glm::vec3(0, 0, 1));
    viewMatrix = glm::translate(viewMatrix, -position);
}

void FACamera::initProjection() {
    projectionMatrix = glm::mat4();
    
    if (perspective) {
        projectionMatrix = glm::perspectiveFov(degreesToRadians(fieldOfView), width, heigth, nearPlane, farPlane);
    } else {
        projectionMatrix = glm::ortho(-0.5f * width, 0.5f * width, -0.5f * heigth, 0.5f * heigth, nearPlane, farPlane);
    }
}

void FACamera::setX(float x) {
    position.x = x;
}
void FACamera::setY(float y) {
    position.y = y;
}
void FACamera::setZ(float z) {
    position.z = z;
}
void FACamera::setPosition(glm::vec3 p) {
    this->position = p;
}
void FACamera::moveX(float x) {
    position.x += x;
}
void FACamera::moveY(float y) {
    position.y += y;
}
void FACamera::moveZ(float z) {
    position.z += z;
}
void FACamera::move(glm::vec3 p) {
    position += p;
}
void FACamera::rotateX(float f) {
    rotation.x += f;
}
void FACamera::rotateY(float f) {
    rotation.y += f;
}
void FACamera::rotateZ(float f) {
    rotation.z += f;
}
void FACamera::setRX(float rx) {
    rotation.x = rx;
}
void FACamera::setRY(float ry) {
    rotation.y = ry;
}
void FACamera::setRZ(float rz) {
    rotation.z = rz;
}
float FACamera::getX() {
    return position.x;
}
float FACamera::getY() {
    return position.y;
}
float FACamera::getZ() {
    return position.z;
}
glm::vec3 FACamera::getPosition() {
    return position;
}
float FACamera::getRX() {
    return rotation.x;
}
float FACamera::getRY() {
    return rotation.y;
}
float FACamera::getRZ() {
    return rotation.z;
}
float FACamera::getRXD() {
    return degreesToRadians(rotation.x);
}
float FACamera::getRYD() {
    return degreesToRadians(rotation.y);
}
float FACamera::getRZD() {
    return degreesToRadians(rotation.z);
}
float FACamera::getNearPlane() {
    return this->nearPlane;
}
float FACamera::getFarPlane() {
    return this->farPlane;
}
float FACamera::getFieldOfView() {
    return this->fieldOfView;
}
float FACamera::getAspectRatio() {
      return this->aspectRatio;
}
float FACamera::coTangent(float angle) {
    return 1.0/tanf(angle);
}
float FACamera::degreesToRadians(float degrees) {
    return degrees * (M_PI / 180.0);
}