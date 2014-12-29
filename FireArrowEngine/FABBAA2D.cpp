//
//  FABBAA2D.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FABBAA2D.h"

FABBAA2D::FABBAA2D() {
    this->anchorPoint = glm::vec2(0.5);
    this->bbPosition = glm::vec2(0.5,0.5);
    this->max = glm::vec2();
    this->min = glm::vec2();
    this->size = FASize();
}

FABBAA2D::FABBAA2D(glm::vec2 position, FASize size) {
    this->anchorPoint = glm::vec2(0.5);
    this->bbPosition = position + glm::vec2(0.5,0.5);
    this->size = size;
    calculateMaxAndMin();
}

FABBAA2D::FABBAA2D(float x, float y, float width, float height) {
    this->anchorPoint = glm::vec2(0.5);
    this->bbPosition = glm::vec2(x + 0.5,y + 0.5);
    this->size = FASize(width, height);
    calculateMaxAndMin();
}

void FABBAA2D::calculateMaxAndMin() {
    max.x = bbPosition.x + (1 - anchorPoint.x) * size.width;
    min.x = bbPosition.x - anchorPoint.x * size.width;
    max.y = bbPosition.y + (1 - anchorPoint.y) * size.height;
    min.y = bbPosition.y - anchorPoint.y * size.height;
}

bool FABBAA2D::collideWith(const FABBAA2D &bb) {
    //TODO
    if (this->max.x < bb.min.x || bb.max.x < this->min.x || this->min.y < bb.max.y || bb.min.y < this->max.y) {
        return true;
    }
    return false;
}

bool FABBAA2D::collideWith(const glm::vec2 v) {
    
    if (v.x < this->max.x && v.x > this->min.x && v.y < this->max.y && v.y > this->min.y) {
        return true;
    }
    
    return false;
}