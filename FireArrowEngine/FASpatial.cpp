//
//  FASpatial.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 14/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FASpatial.h"

void FASpatial::setX(float x) {
    position.x = x;
}
void FASpatial::setY(float y) {
    position.y = y;
}
void FASpatial::setZ(float z) {
    position.z = z;
}
void FASpatial::setPos(glm::vec3 pos) {
    position = pos;
}
void FASpatial::moveX(float x) {
    position.x += x;
}
void FASpatial::moveY(float y) {
    position.y += y;
}
void FASpatial::moveZ(float z) {
    position.z += z;
}
void FASpatial::move(glm::vec3 p) {
    position += p;
}
float FASpatial::getX() {
    return position.x;
}
float FASpatial::getY() {
    return position.y;
}
float FASpatial::getZ() {
    return position.z;
}
glm::vec3 FASpatial::getPos() {
    return position;
}
//int FASpatial::getID() {
//    return id;
//}