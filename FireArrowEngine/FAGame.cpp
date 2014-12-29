//
//  FAGame.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAGame.h"

FAGame::FAGame() {
    initEngine();
}

void FAGame::init() {
    
}

FAScene* FAGame::setInitialScene() {
    return new shadowScene();
}

void FAGame::setWindowAttributes() {
    this->setWindowsSize(1024, 720);
    this->setSamples(8);
    this->setDecorated(false);
}

FAGame::~FAGame() {
    
}