//
//  normalScene.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 27/01/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__normalScene__
#define __FireArrowEngine__normalScene__

#include <stdio.h>
#define GL_GLEXT_PROTOTYPES
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include "FAScene.h"
#include "FAModel.h"
#include "Ground.h"
#include "FAPlane2D.h"
#include "FAWireFrame.h"
#include "FASkeleton.h"
#include "FAButton.h"
#include "FATexturedPlane2D.h"
#include "FAPointLight.h"
#include "FAPlane3D.h"
#include "FACube.h"

class normalScene: public FAScene {
    
private:
    
    //debug
    bool isWireFrames = false;
    
    static const int frustums = 4;
    static const int gbufferSize = 3;
    
    GLuint shadowMap;
    GLuint shadowFbo;
    
    GLuint query;
    
    GLuint deferredFbo;
    GLuint deferredTextures[4];
    
    //    glm::mat4 inverseShadowMatrix[frustums];
    float shadowQuality;
    float factor = 0.5;
    float units = 0;
    
    const float speed = 5;
    bool cursorHasMoved = false;
    glm::vec2 previousCursorPosition;
    glm::vec3 cameraMovement;
    
    FAModel *barrel;
    
public:
    
    normalScene();
    
    //debug
    void showWireFrames();
    
    void init();
    void render();
    void renderShadow();
    void update(float dt);
    //    using FAScene::getKeyInput;
    void buttonPressed(int index);
    void getKeyInput(int key, int action);
    void mouseKeyInput(int button, int action);
    void cursorPosition(double x, double y);
    
    ~normalScene();
    
};

#endif /* defined(__FireArrowEngine__normalScene__) */
