//
//  normalScene.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 27/01/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "normalScene.h"

normalScene::normalScene() {
    
    
    
}

void normalScene::init() {
    
    camera = new FACamera(40.0f, (float)windowWidth, windowHeigth, 0.001, 400);
    camera->setZ(0);
    camera->setY(0);
    camera->setX(6);
    
    FAModel *m = new FAModel();
//    m->setShader(new FAShader("BasicShadow"));
//    m->SetFAModel("cube.fa");
//    m->setScale(1);
//    m->setPos(glm::vec3(10,0.5,1));
//    m->setColor(FAColorBlue);
//    addChild(m);
    barrel = m;
    
    m = new FAModel();
    m->setShader(new FAShader("FA"));
    m->SetFAModel("tree.fa");
    m->setScale(1);
    m->setPos(glm::vec3(-10,0,1));
    m->setScale(glm::vec3(1,1,1));
    addChild(m);
    
    m = new FAModel();
    m->setShader(new FAShader("FA"));
    m->SetFAModel("barrel.fa");
    m->setScale(1);
    m->setPos(glm::vec3(-5,1,-3));
    m->setScale(glm::vec3(1,1,1));
    addChild(m);
    
    //sovalkov
    FAPlane3D *p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorRed);
    p->setPos(glm::vec3(0.22,0,0));
    p->setY(-1);
    p->setScale(glm::vec3(2.391, 1, 1.64));
    addChild(p);
    //rum
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorDarkRed);
    p->setPos(glm::vec3(0,0,-1.64));
    p->setY(-1);
    p->setScale(glm::vec3(7.215, 1, 3.28));
    addChild(p);
    //hall
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorRed);
    p->setPos(glm::vec3(5.611,0,0));
    p->setY(-1);
    p->setScale(glm::vec3(1.605, 1, 1.64));
    addChild(p);
    
    
    //walls
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>());
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 3.28));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0,0,-1.64));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.22, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0.22,0,-1.64));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>());
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 1.64));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0.46,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.46, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(2.39,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(1.22);
    p->setScale(glm::vec3(1.93, 0.26, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(4.61,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(2.22, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(6.54,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(1.22);
    p->setScale(glm::vec3(1.93, 0.26, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(7.215,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.68, 2.48, 1));
    addChild(p);
    
    //windows
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0.46,0,-4.99));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>());
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.22, 0.07));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(2.39,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.22, 0.07));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(2.39,0,-4.99));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1.93, 2.22, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(4.61,0,-4.99));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>());
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.22, 0.07));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(6.535,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.22, 0.07));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(6.535,0,-4.99));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1.93, 2.22, 1));
    addChild(p);
    
    //end windows
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(7.215,0,0));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 2.45));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(6.515,0,-2.45));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 0.07));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(7.215,0,-2.52));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 2.4));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(2.611,0,0));
    p->setRZ(glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 1.64));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(5.611,0,-1.640));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>());
    p->setY(-1);
    p->setScale(glm::vec3(1, 2.48, 1.64));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(2.611,0,-1.64));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(3, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(0.22,0,0));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(2.391, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(7.215,0,-2.45));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.7, 2.48, 1));
    addChild(p);
    
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(6.515,0,-2.52));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.7, 2.48, 1));
    addChild(p);
    
    //kitchen
//    p = new FAPlane3D;
//    p->setShader(new FAShader("Basic"));
//    p->setColor(FAColorDarkGrey);
//    p->setPos(glm::vec3(6.53,0,-2.52));
//    p->setY(-0.05);
//    p->setScale(glm::vec3(0.685, 1, 2.4));
//    addChild(p);
    
    FACube *c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(6.8725,-0.525,-4.62));
    c->setScale(glm::vec3(0.685, 0.95, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(6.8725,-0.525,-4.02));
    c->setScale(glm::vec3(0.685, 0.95, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(6.8725,-0.525,-3.42));
    c->setScale(glm::vec3(0.685, 0.95, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(6.8725,-0.525,-2.82));
    c->setScale(glm::vec3(0.685, 0.95, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    //top shelf
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(7.055,0.875,-4.62));
    c->setScale(glm::vec3(0.32, 0.96, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(7.055,0.875,-4.02));
    c->setScale(glm::vec3(0.32, 0.96, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(7.055,0.875,-3.42));
    c->setScale(glm::vec3(0.32, 0.96, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(7.055,0.875,-2.82));
    c->setScale(glm::vec3(0.32, 0.96, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
    //island
    p = new FAPlane3D;
    p->setShader(new FAShader("Basic"));
    p->setColor(FAColorWhite);
    p->setPos(glm::vec3(5.510,0,-4.92));
    p->setRZ(glm::pi<float>()/2);
    p->setRY(-3 * glm::pi<float>()/2);
    p->setY(-1);
    p->setScale(glm::vec3(0.9, 2.22, 1));
    addChild(p);
    
    //fridge
    c = new FACube;
    c->setShader(new FAShader("Basic"));
    c->setPos(glm::vec3(5.19,-0.0625,-4.62));
    c->setScale(glm::vec3(0.64, 1.875, 0.6));
    c->setColor(FAColorWhite);
    addChild(c);
    
//    Ground *g = new Ground(2000);
//    g->moveX(-500);
//    g->moveZ(-500);
//    g->setY(0);
//    addChild(g);
    
    setCursorState(GLFW_CURSOR_DISABLED);
    glEnable(GL_CULL_FACE);
}

void normalScene::render() {
    camera->useView();
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    children->render(camera);
    
    for(FANode* node : HUDElements)
        node->render(HUDcamera);
}

void normalScene::update(float dt) {
    
    barrel->rotateX(dt);
    //override
    camera->moveX(cameraMovement.z * dt * sin(camera->getRY()));
    camera->moveZ(-cameraMovement.z * dt * cos(camera->getRY()));
    
    camera->moveX(cameraMovement.x * dt * cos(camera->getRY()));
    camera->moveZ(cameraMovement.x * dt * sin(camera->getRY()));
    camera->moveY(cameraMovement.y * dt);
    
    //    for(FANode *node : children)
    //        node->update(dt);
    children->update(dt);
    for(FAScene *scene : subviews)
        scene->update(dt);
    for(FANode *node : HUDElements)
        node->update(dt);
}

void normalScene::buttonPressed(int index) {
    print(index);
}

void normalScene::getKeyInput(int key, int action) {
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS) {
            cameraMovement.z += speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.z -= speed;
        }
    } else if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS) {
            cameraMovement.z -= speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.z += speed;
        }
    } else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS) {
            cameraMovement.x += speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.x -= speed;
        }
    } else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS) {
            cameraMovement.x -= speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.x += speed;
        }
    } else if (key == GLFW_KEY_SPACE) {
        if (action == GLFW_PRESS) {
            cameraMovement.y += speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.y -= speed;
        }
    } else if (key == GLFW_KEY_DOWN) {
        if (action == GLFW_PRESS) {
            factor-=0.1;
        }
    } else if (key == GLFW_KEY_UP) {
        if (action == GLFW_PRESS) {
            factor+=0.1;
        }
    } else if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS) {
            units-=0.1;
        }
    } else if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS) {
            units+=0.1;
        }
    } else if (key == GLFW_KEY_LEFT_SHIFT) {
        if (action == GLFW_PRESS) {
            cameraMovement.y -= speed;
        } else if (action == GLFW_RELEASE) {
            cameraMovement.y += speed;
        }
    } else if (key == GLFW_KEY_E) {
        if (action == GLFW_PRESS) {
            camera->setPosition(camera->getPosition());
            camera->setRX(camera->getRX());
            camera->setRY(camera->getRY());
            camera->setRZ(camera->getRZ());
        } else if (action == GLFW_RELEASE) {
        }
    } else {
        std::cout << "Key: " << key << " action: " << action << std::endl;
    }
}

void normalScene::mouseKeyInput(int button, int action) {
    
}

void normalScene::cursorPosition(double x, double y) {
    
    //calculated from the uppear left corner
    glm::vec2 currentCursorPos = glm::vec2(x, y);
    glm::vec2 deltaCursorPos = currentCursorPos - previousCursorPosition;
    previousCursorPosition = currentCursorPos;
    if (!cursorHasMoved) {
        if (previousCursorPosition != glm::vec2()) {
            cursorHasMoved = true;
            return;
        }
    }
    if (getCursorState() == GLFW_CURSOR_DISABLED) {
        camera->rotateY(deltaCursorPos.x / 1000.0f);
        camera->rotateX(deltaCursorPos.y / 1000.0f);
    }
    
}

normalScene::~normalScene() {
    
}