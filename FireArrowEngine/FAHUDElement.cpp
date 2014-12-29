//
//  FAHUDElement.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 26/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAHUDElement.h"

FAHUDElement::FAHUDElement() {
    isClickable = true;
}

void FAHUDElement::setID(int id) {
    this->id = id;
}
int FAHUDElement::getID() {
    return this->id;
}

void FAHUDElement::onUpdate(float dt) {
}

bool FAHUDElement::handleClick(glm::vec2 p) {
    
    if (collideWith(p)) {
        if (isClickable) {
            
        }
        return true;
    }
    return false;
}

FAHUDElement::~FAHUDElement() {
    
}