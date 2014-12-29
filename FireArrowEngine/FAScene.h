//
//  FAScene.h
//  FireArrow
//
//  Created by Simon on 24/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAScene__
#define __FireArrow__FAScene__

#include <stdio.h>

#include "FANode.h"
#include "FAFont.h"
#include "FAText2D.h"
#include "FAShaderNode.h"
#include "FAHUDElement.h"

class FAEngine;

class FAScene {
    
//    FAText2D *fpsText;
//    FAText2D *positionText;
    
private:
    
    FAText2D *fpsText;
    bool displayFps;
    bool useStandardCameraControlls;
    glm::vec2 lastCursorPosition;
    
    void addNode(FANode* node);
    
public:
    FAScene();
    ~FAScene();
    
    void setShaderNode(FAShaderNode* shaderNode);
    void setCallback(FAEngine* _callback);
    void setWindowSize(int width, int height);
    void setDisplayFps(bool b);
    void setUseStandardCameraControlls(bool b);
    void setCursorState(int state);
    void swapScene(FAScene* scene);
    void addChild(FANode* child);
    void addSubview(FAScene* scene);
    void addHUDElement(FAHUDElement* node);
    
    void onInit();
    void onUpdate(float dt);
    void getMouseKeyInput(int button, int action);
    void getCursorPosition(double x, double y);
    int getCursorState();
    
    virtual void init(){}
    virtual void render();
    virtual void update(float dt){}
    virtual void getKeyInput(int key, int action){}
    virtual void mouseKeyInput(int button, int action){}
    virtual void cursorPosition(double x, double y){}
    virtual void buttonPressed(int index){}
    
    FAEngine* callback;
    
protected:
    std::vector<FAScene*> subviews;
    std::vector<FANode*> children;
    std::vector<FAHUDElement*> HUDElements;
    FACamera* camera;
    FACamera* HUDcamera;
    FAShaderNode* shaders;
    bool isActive = true;
    int windowWidth;
    int windowHeigth;
    
};

#endif /* defined(__FireArrow__FAScene__) */
