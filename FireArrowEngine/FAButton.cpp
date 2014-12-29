//
//  FAButton.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAButton.h"

FAButton::FAButton() {
    
}

void FAButton::setSize(float width, float height) {
    this->setScale(width, height);
    this->size = FASize(this->scale.x, this->scale.y);
    calculateMaxAndMin();
}


FAButton::~FAButton() {
    
}