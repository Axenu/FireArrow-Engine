//
//  FASize.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FASize.h"

FASize::FASize() {
    this->width = 0;
    this->height = 0;
}

FASize::FASize(float s) {
    this->width = s;
    this->height = s;
}

FASize::FASize(float width, float height) {
    this->width = width;
    this->height = height;
}

float FASize::getArea() const {
    return width * height;
}