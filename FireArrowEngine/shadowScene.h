//
//  shadowScene.h
//  FireArrow
//
//  Created by Simon on 28/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__shadowScene__
#define __FireArrow__shadowScene__

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

class shadowScene: public FAScene {
    
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
    
    const float speed = 16;
    bool cursorHasMoved = false;
    glm::vec2 previousCursorPosition;
    glm::vec3 cameraMovement;
    glm::vec3 globalLightDirection;
    
    std::vector<glm::mat4> inverseShadowMatrix;
    
    std::vector<FAPointLight*> lights;
    
	FACamera *testCamera;
    FAWireFrame *wireFrame;
    FAWireFrame *shadowWireFrame;
    
    FAPointLight *light1;
    FAPointLight *light2;
    
    FATexturedPlane2D *background;
    
    FATexturedPlane2D *plane1;
    FATexturedPlane2D *plane2;
    FATexturedPlane2D *plane3;
    FATexturedPlane2D *plane4;
    
    void setupShadowBuffer();
    void setupDeferredBuffer();
    
    void renderShadows();
    
    glm::mat4 calculateShadowCamera(float near, float far);
    glm::vec3 intersectionBetweenThreePlanes(glm::vec4 p1, glm::vec4 p2, glm::vec4 p3);
    
    void printSome();
    
public:
    
    shadowScene();
    
    //debug
    void showWireFrames();
    
    void setShadowQuality(float quality);
    
    void init();
    void render();
    void renderShadow();
    void update(float dt);
//    using FAScene::getKeyInput;
    void buttonPressed(int index);
    void getKeyInput(int key, int action);
    void mouseKeyInput(int button, int action);
    void cursorPosition(double x, double y);
    
    bool operator< (const shadowScene &v1);
    
    ~shadowScene();
    
};

#endif /* defined(__FireArrow__shadowScene__) */
