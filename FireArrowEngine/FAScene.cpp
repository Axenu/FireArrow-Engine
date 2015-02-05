//
//  FAScene.cpp
//  FireArrow
//
//  Created by Simon on 24/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAScene.h"
#include "FAEngine.h"

FAScene::FAScene() {
    
}

void FAScene::setShaderNode(FAShaderNode *shaderNode) {
    this->shaders = shaderNode;
}

void FAScene::setCallback(FAEngine *_callback) {
    this->callback = _callback;
}

void FAScene::setWindowSize(int width, int height) {
    this->windowWidth = width;
    this->windowHeigth = height;
}

void FAScene::setDisplayFps(bool b) {
   this->displayFps = b;
    if (fpsText) {
        fpsText->setAvtive(b);
    }
}

void FAScene::setUseStandardCameraControlls(bool b) {
    this->useStandardCameraControlls = b;
}

void FAScene::setCursorState(int state) {
    callback->setCursorState(state);
}

void FAScene::swapScene(FAScene *scene) {
    this->callback->swapScene(scene);
}

void FAScene::addChild(FANode* child) {
//    this->children.push_back(child);
    children->addNode(child);
}

void FAScene::addSubview(FAScene* scene) {
    this->subviews.push_back(scene);
}

void FAScene::addHUDElement(FAHUDElement* node) {
    this->HUDElements.push_back(node);
    long i = HUDElements.size() - 2;
    if (i < 0) {
        return;
    }
    while (HUDElements[i]->getZ() < node->getZ()) {
        HUDElements[i+1] = HUDElements[i];
        HUDElements[i] = node;
        i--;
        if (i < 0) {
            return;
        }
    }
}

void FAScene::onInit() {
    
    displayFps = true;
    children = new FANode();
    camera = new FACamera();
    
    FAFont *font = new FAFont("Helvetica.ttf", 20, windowWidth, windowHeigth);
    fpsText = new FAText2D(font);
    fpsText->setShader(shaders->getShader("Text2D"));
    fpsText->setText("fps: 60");
    fpsText->setPos(glm::vec3(-0.99,0.95,0));
    fpsText->setColor(FAColorWhite);
    addHUDElement(fpsText);
    
    vertexCountText = new FAText2D(font);
    vertexCountText->setShader(shaders->getShader("Text2D"));
    vertexCountText->setText("Vertices: 0");
    vertexCountText->setPos(glm::vec3(-0.99,0.85,0));
    vertexCountText->setColor(FAColorWhite);
    addHUDElement(vertexCountText);
    
    this->init();
}

void FAScene::render() {
    if (!isActive) {
        return;
    }
    children->render(camera);
//    for(FANode *node : children)
//        node->render(camera);
    for(FAScene *scene : subviews)
        scene->render();
    for(FAHUDElement *node : HUDElements)
        node->render(camera);
}

void FAScene::onUpdate(float dt) {
    if (!isActive) {
        return;
    }
    if (displayFps) {
        if (time > 1) {
            fpsText->setText("fps: " + std::to_string((frames/time)));
            frames = 0;
            time = 0;
        } else {
            time+=dt;
            frames++;
        }
        vertexCountText->setText("vertices: " + std::to_string(children->getVertexCount()));
    }
    update(dt);
}

void FAScene::getMouseKeyInput(int button, int action) {
    //TODO
    if (true) {
        if (button == GLFW_MOUSE_BUTTON_1) {
            if (action == GLFW_PRESS) {
                for (FAHUDElement *node : HUDElements) {
                    if (node->handleClick(lastCursorPosition)) {
                        buttonPressed(node->getID());
                        break;
                    }
                }
            }
        }
    }
    mouseKeyInput(button, action);
}

void FAScene::getCursorPosition(double x, double y) {
    lastCursorPosition = glm::vec2(x/windowWidth,y/windowHeigth);
    cursorPosition(x, y);
}

int FAScene::getCursorState() {
    return callback->getCursorState();
}

FAScene::~FAScene() {
    
}