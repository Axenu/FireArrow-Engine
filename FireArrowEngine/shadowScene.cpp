//
//  shadowScene.cpp
//  FireArrow
//
//  Created by Simon on 28/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "shadowScene.h"

shadowScene::shadowScene() {
    
}

void shadowScene::setShadowQuality(float quality) {
    this->shadowQuality = quality;
}

void shadowScene::init() {
	globalLightDirection = glm::normalize(glm::vec3(1,-1,1));
    shadowQuality = 4;
    
    camera = new FACamera(40.0f, (float)windowWidth, windowHeigth, 0.1, 400);
    camera->setZ(0);
    camera->setY(0);
    camera->setX(0);
    
    HUDcamera = new FACamera(100,-100);
    
	testCamera = new FACamera(40.0f, (float)windowWidth, windowHeigth, 0.1, 100);
	testCamera->setZ(0);
	testCamera->setY(0);
	testCamera->setX(0);
    //	camera.lookAt(glm::vec3(0,0,0));
    
    
    FAModel *m = new FAModel();
    m->setShader(new FAShader("BasicShadow"));
    m->SetFAModel("cube.fa");
    m->setScale(1);
    m->setPos(glm::vec3(10,0.5,1));
    m->setColor(FAColorBlue);
    addChild(m);

    m = new FAModel();
    m->setShader(new FAShader("FA"));
    m->SetFAModel("tree.fa");
    m->setScale(1);
    m->setPos(glm::vec3(-10,0,1));
	m->setScale(glm::vec3(1,1,1));
    addChild(m);
//
//    m = new FAModel();
//    m->setShader(new FAShader("FA"));
//    m->SetFAModel("barrel.fa");
//    m->setScale(1);
//    m->setPos(glm::vec3(0,0.5,1));
//    m->setScale(glm::vec3(1,1,1));
//    m->setRZ(1);
//    addChild(m);
//    
////    FASkeleton *f = new FASkeleton();
////    f->setShader(new FAShader("Bone"));
////    f->SetFAModel("dog v2.fa");
////    addChild(f);
//    
//    for (int x = 0; x < 10; x++) {
        Ground *g = new Ground();
        g->moveX(-50);
        g->moveZ(-50);
//        g->moveY(x * 2);
        g->setY(0);
        addChild(g);
//    }
//
////    FAButton *b = new FAButton();
////    b->setShader(shaders->getShader("Plane2D"));
////    b->setColor(glm::vec4(0.3,0.3,0.3,0.5));
////    b->setSize(0.9, 0.5);
////    b->setID(3);
////    b->setPos(glm::vec3(0,0,-1));
////    addHUDElement(b);
////    
////    b = new FAButton();
////    b->setShader(shaders->getShader("Plane2D"));
////    b->setColor(glm::vec4(0.3,0.3,0.3,0.5));
////    b->setSize(0.4, 0.5);
////    b->setID(5);
////    b->setPos(glm::vec3(0,0,1));
////    addHUDElement(b);
//    
    background = new FATexturedPlane2D();
    background->setShader(shaders->getShader("TexturedPlane2D"));
    background->setScale(2);
    background->update(0);
//
//    plane1 = new FATexturedPlane2D();
//    plane1->setShader(new FAShader("TexturedPlane2D"));
//    plane1->setScale(0.5);
//    plane1->setPos(glm::vec3(-0.5,0.5,0));
//    plane1->setLayer(0);
//    plane1->Deactivate();
//    addHUDElement(plane1);
//    
//    plane2 = new FATexturedPlane2D();
//    plane2->setShader(new FAShader("TexturedPlane2D"));
//    plane2->setScale(0.5);
//    plane2->setPos(glm::vec3(0.5,0.5,0));
//    plane2->setLayer(1);
//        plane2->Deactivate();
//    addHUDElement(plane2);
//    
//    plane3 = new FATexturedPlane2D();
//    plane3->setShader(new FAShader("TexturedPlane2DDepth"));
//    plane3->setScale(0.5);
//    plane3->setPos(glm::vec3(-0.5,-0.5,0));
//    plane3->setLayer(2);
//        plane3->Deactivate();
//    addHUDElement(plane3);
//    
//    plane4 = new FATexturedPlane2D();
//    plane4->setShader(new FAShader("TexturedPlane2D"));
//    plane4->setScale(0.5);
//    plane4->setPos(glm::vec3(0.5,-0.5,0));
//    plane4->setLayer(3);
//        plane4->Deactivate();
//    addHUDElement(plane4);
//    
////    showWireFrames();
//    
//    light1 = new FAPointLight();
//    light1->setShader(shaders->getShader("pointLight"));
//    light1->setColor(FAColorRed);
//    light1->setPos(glm::vec3(0,1,2));
//    lights.push_back(light1);
//    
//    light2 = new FAPointLight();
//    light2->setShader(shaders->getShader("pointLight"));
//    light2->setColor(FAColorGreen);
//    light2->setPos(glm::vec3(0,1,0.5));
//    lights.push_back(light2);

    for (int i = 0; i < 5; i++) {
        float x = glm::sin(i/(glm::pi<float>()/80)) * 10;
        float y = glm::cos(i/(glm::pi<float>()/80)) * 10;
        FAPointLight *l = new FAPointLight();
        l->setShader(shaders->getShader("pointLight"));
        l->setColor(FAColorYellow);
        l->setPos(glm::vec3(y,1,x));
        lights.push_back(l);
    }
    
    setupShadowBuffer();
    setupDeferredBuffer();
    
//    print(glGetString​(GL_RENDERER​));
//    print((std::)glGetString(GL_VENDOR));
//    std::cout << glGetString(GL_RENDERER) << std::endl;
    
    setCursorState(GLFW_CURSOR_DISABLED);
}

void shadowScene::showWireFrames() {
    wireFrame = new FAWireFrame();
    wireFrame->setShader(new FAShader("Simple"));
    wireFrame->setColor(FAColorRed);
    addChild(wireFrame);
    
    shadowWireFrame = new FAWireFrame();
    shadowWireFrame->setShader(new FAShader("Simple"));
    shadowWireFrame->setColor(FAColorBlue);
    addChild(shadowWireFrame);
    isWireFrames = true;
}

glm::mat4 shadowScene::calculateShadowCamera(float near, float far) {
	testCamera->useView();
    glm::vec3 cameraPoints[8];
    glm::vec3 cameraDirection = glm::normalize(glm::vec3(-testCamera->viewMatrix[0][2],-testCamera->viewMatrix[1][2],-testCamera->viewMatrix[2][2]));
    glm::vec3 up = glm::normalize(glm::vec3(testCamera->viewMatrix[0][1],testCamera->viewMatrix[1][1],testCamera->viewMatrix[2][1]));
    glm::vec3 cameraRightVector = glm::normalize(glm::cross(up, cameraDirection));
    
    //setup variables for calculating camerabounds
    float tan = 2 * tanf(testCamera->getFieldOfView() * glm::pi<float>() / 360.0);
    float heightNear = tan * near;
    float heightFar = tan * far;
    
    float widthNear = heightNear * testCamera->getAspectRatio();
    float widthFar = heightFar * testCamera->getAspectRatio();

    glm::vec3 centerNear = testCamera->getPosition() + cameraDirection * near;
    glm::vec3 centerFar = testCamera->getPosition() + cameraDirection * far;
    
    //calculate camera bounds
    cameraPoints[0] = centerNear + (up * (heightNear/2)) - (cameraRightVector * (widthNear/2));
    cameraPoints[1] = centerNear + (up * (heightNear/2)) + (cameraRightVector * (widthNear/2));
    cameraPoints[2] = centerNear - (up * (heightNear/2)) - (cameraRightVector * (widthNear/2));
    cameraPoints[3] = centerNear - (up * (heightNear/2)) + (cameraRightVector * (widthNear/2));
    cameraPoints[4] = centerFar + (up * (heightFar/2)) - (cameraRightVector * (widthFar/2));
    cameraPoints[5] = centerFar + (up * (heightFar/2)) + (cameraRightVector * (widthFar/2));
    cameraPoints[6] = centerFar - (up * (heightFar/2)) - (cameraRightVector * (widthFar/2));
    cameraPoints[7] = centerFar - (up * (heightFar/2)) + (cameraRightVector * (widthFar/2));
    
    glm::vec3 rightLeftNormal = glm::normalize(glm::cross(glm::vec3(0,1,0), globalLightDirection));
    glm::vec3 topBottomNormal = glm::normalize(glm::cross(rightLeftNormal, globalLightDirection));
    
    float furthestPoint = glm::dot(globalLightDirection, cameraPoints[0]);
    float closestPoint = furthestPoint;
    
    float rightPoint = glm::dot(rightLeftNormal, cameraPoints[0]);
    float leftPoint = rightPoint;
    
    float topPoint = glm::dot(topBottomNormal, cameraPoints[0]);
    float bottomPoint = topPoint;
    
    glm::vec3 closest = cameraPoints[0];
    glm::vec3 furthest = closest;
    glm::vec3 right = closest;
    glm::vec3 left = closest;
    glm::vec3 top = closest;
    glm::vec3 bottom = closest;
    
    
    for (int i = 1; i < 8; i++) {
        float p = glm::dot(globalLightDirection, cameraPoints[i]);
        if (p > furthestPoint) {
            furthestPoint = p;
            furthest = cameraPoints[i];
        }
        if (p < closestPoint) {
            closestPoint = p;
            closest = cameraPoints[i];
        }
        p = glm::dot(rightLeftNormal, cameraPoints[i]);
        if (p > rightPoint) {
            rightPoint = p;
            right = cameraPoints[i];
        }
        if (p < leftPoint) {
            leftPoint = p;
            left = cameraPoints[i];
        }
        p = glm::dot(topBottomNormal, cameraPoints[i]);
        if (p > topPoint) {
            topPoint = p;
            top = cameraPoints[i];
        }
        if (p < bottomPoint) {
            bottomPoint = p;
            bottom = cameraPoints[i];
        }
    }
    
    float width = glm::abs(rightPoint - leftPoint)/2.0f;
    glm::vec3 middleRightLeft = (right + left)/2.0f;
    float height = glm::abs(topPoint - bottomPoint)/2.0f;
    glm::vec3 middletopBottom = (top + bottom)/2.0f;
    
    
    float d[3];
    d[0] = glm::dot(globalLightDirection, closest);
    d[1] = glm::dot(rightLeftNormal, middleRightLeft);
    d[2] = glm::dot(topBottomNormal, middletopBottom);
    float farPlane = glm::abs(furthestPoint - closestPoint);
    
    glm::mat3 equations = glm::mat3(globalLightDirection.x, rightLeftNormal.x, topBottomNormal.x, globalLightDirection.y,rightLeftNormal.y, topBottomNormal.y, globalLightDirection.z, rightLeftNormal.z, topBottomNormal.z);
    glm::mat3 solution = glm::inverse(equations);
    glm::vec3 finalPoint = solution * glm::vec3(d[0],d[1],d[2]);
    glm::mat4 projectionMatrix = glm::ortho(-width, width, -height, height, -100.0f, farPlane);
    glm::mat4 viewMatrix = glm::lookAt(finalPoint, finalPoint + globalLightDirection, glm::vec3(0,1,0));
    
    // calculate corners of frustum
    //not nessesary!
    if (isWireFrames) {
        wireFrame->SetModel(cameraPoints);
        glm::vec3 corners[8];
        glm::vec4 planes[6];
        planes[0] = glm::vec4(globalLightDirection.x, globalLightDirection.y, globalLightDirection.z, glm::dot(globalLightDirection, closest));
        planes[1] = glm::vec4(globalLightDirection.x, globalLightDirection.y, globalLightDirection.z, glm::dot(globalLightDirection, furthest));
        planes[2] = glm::vec4(rightLeftNormal.x, rightLeftNormal.y, rightLeftNormal.z, glm::dot(rightLeftNormal, left));
        planes[3] = glm::vec4(rightLeftNormal.x, rightLeftNormal.y, rightLeftNormal.z, glm::dot(rightLeftNormal, right));
        planes[4] = glm::vec4(topBottomNormal.x, topBottomNormal.y, topBottomNormal.z, glm::dot(topBottomNormal, top));
        planes[5] = glm::vec4(topBottomNormal.x, topBottomNormal.y, topBottomNormal.z, glm::dot(topBottomNormal, bottom));
        
        corners[0] = intersectionBetweenThreePlanes(planes[0], planes[2], planes[4]);
        corners[1] = intersectionBetweenThreePlanes(planes[0], planes[2], planes[5]);
        corners[2] = intersectionBetweenThreePlanes(planes[0], planes[3], planes[4]);
        corners[3] = intersectionBetweenThreePlanes(planes[0], planes[3], planes[5]);
        corners[4] = intersectionBetweenThreePlanes(planes[1], planes[2], planes[4]);
        corners[5] = intersectionBetweenThreePlanes(planes[1], planes[2], planes[5]);
        corners[6] = intersectionBetweenThreePlanes(planes[1], planes[3], planes[4]);
        corners[7] = intersectionBetweenThreePlanes(planes[1], planes[3], planes[5]);
        shadowWireFrame->SetModel(corners);
    }

    return projectionMatrix * viewMatrix;
}

glm::vec3 shadowScene::intersectionBetweenThreePlanes(glm::vec4 p1, glm::vec4 p2, glm::vec4 p3) {
    
    glm::mat3 equations = glm::mat3(p1.x, p2.x, p3.x, p1.y, p2.y, p3.y, p1.z, p2.z, p3.z);
    glm::mat3 solution = glm::inverse(equations);
	
    return solution * glm::vec3(p1.w,p2.w,p3.w);
}

void shadowScene::renderShadows() {
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glEnable(GL_CULL_FACE);
    glViewport(0,0,this->windowWidth * shadowQuality,this->windowHeigth * shadowQuality);
    std::vector<glm::mat4> shadowMatrix;
    shadowMatrix.push_back(calculateShadowCamera(0, 2));
    shadowMatrix.push_back(calculateShadowCamera(2, 5));
    shadowMatrix.push_back(calculateShadowCamera(5, 20));
    shadowMatrix.push_back(calculateShadowCamera(20, 100));
    inverseShadowMatrix = std::vector<glm::mat4>();
    glm::mat4 m;
    for (int i = 0; i < frustums; i++) {
        //        shadowMatrix.push_back(calculateShadowCamera(0,100));
        m = glm::translate(glm::mat4(), glm::vec3(0.5,0.5,0.5));
        m = glm::scale(m, glm::vec3(0.5,0.5,0.5));
        m = m * shadowMatrix[i];
        inverseShadowMatrix.push_back(m);
        glBindFramebuffer(GL_FRAMEBUFFER, shadowFbo);
        glFramebufferTextureLayer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, shadowMap, 0, GLint(i));
        
        glClear(GL_DEPTH_BUFFER_BIT);
        
        glCullFace(GL_FRONT);
//        for(FANode *node : children)
//            node->renderShadow();
        children->renderShadow(shadowMatrix[i]);
    }
    
    
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glViewport(0, 0, windowWidth*2, windowHeigth*2);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    //    glEnable(GL_POLYGON_OFFSET_FILL);
    //    glPolygonOffset(factor,units);
    
    glCullFace(GL_BACK);
}

void shadowScene::render() {
    //override
    glEnable(GL_CULL_FACE);
    
    if (!this->isActive) {
        return;
    }
    
//    renderShadows();
    
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, deferredFbo);
//    glClearColor(0, 0, 0, 0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, windowWidth*2, windowHeigth*2);

    
    camera->useView();
//    for(FANode *node : children)
//        node->render(camera, shadowMap, inverseShadowMatrix);
    children->render(camera, shadowMap, inverseShadowMatrix);
//    for(FAScene *scene : subviews)
//        scene->render();
    
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
//    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    
    background->setTexture(deferredTextures[0]);
    background->render(HUDcamera);
    
//
//    for (FAPointLight *light : lights)
//        light->render(camera);

//    plane1->setTexture(deferredTextures[0]);
//    plane2->setTexture(deferredTextures[1]);
//    plane3->setTexture(deferredTextures[2]);
//    plane4->setTexture(deferredTextures[3]);
    
    glClear(GL_DEPTH_BUFFER_BIT);
    for(FANode* node : HUDElements)
        node->render(HUDcamera);
}

void shadowScene::update(float dt) {
    //override
    camera->moveX(cameraMovement.z * dt * sin(camera->getRY()));
    camera->moveZ(-cameraMovement.z * dt * cos(camera->getRY()));
    
    camera->moveX(cameraMovement.x * dt * cos(camera->getRY()));
    camera->moveZ(cameraMovement.x * dt * sin(camera->getRY()));
    camera->moveY(cameraMovement.y * dt);

    testCamera->setPosition(camera->getPosition());
    testCamera->setRX(camera->getRX());
    testCamera->setRY(camera->getRY());
    testCamera->setRZ(camera->getRZ());
    
//    for(FANode *node : children)
//        node->update(dt);
    children->update(dt);
    for(FAScene *scene : subviews)
        scene->update(dt);
    for(FANode *node : HUDElements)
        node->update(dt);
}

void shadowScene::setupDeferredBuffer() {
    
    //create buffer
    glGenFramebuffers(1, &deferredFbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, deferredFbo);
    
    //create texture
    glGenTextures(4, deferredTextures);
    
    //diffuse
    glBindTexture(GL_TEXTURE_2D, deferredTextures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, windowWidth*2, windowHeigth*2, 0, GL_RGBA, GL_FLOAT, NULL);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, deferredTextures[0], 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    //normal
    glBindTexture(GL_TEXTURE_2D, deferredTextures[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, windowWidth*2, windowHeigth*2, 0, GL_RGBA, GL_FLOAT, NULL);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, deferredTextures[1], 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    //position
    glBindTexture(GL_TEXTURE_2D, deferredTextures[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, windowWidth*2, windowHeigth*2, 0, GL_RGBA, GL_FLOAT, NULL);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, deferredTextures[3], 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    //depth
    glBindTexture(GL_TEXTURE_2D, deferredTextures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, windowWidth*2, windowHeigth*2, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, deferredTextures[2], 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    GLenum drawBuffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
    glDrawBuffers(3, drawBuffers);
    
    GLenum fboStatus;
    fboStatus = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
    if (fboStatus != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "Creating shadow framebuffer failed with code: " << fboStatus << std::endl;
        switch (fboStatus)
        {
            case GL_FRAMEBUFFER_UNDEFINED:
                print("No window?");
                // Oops, no window exists?
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                print("Incomplete attachment");
                // Check the status of each attachment
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                print("No buffers!");
                // Attach at least one buffer to the FBO
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                print("Incomplete draw buffer");
                // Check that all attachments enabled via
                // glDrawBuffers exist in FBO
            case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                print("No read buffer!");
                // Check that the buffer specified via // glReadBuffer exists in FBO
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                print("Unsuported");
                // Reconsider formats used for attached buffers break;
            case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                print("Incomplete multisample!");
                // Make sure the number of samples for each // attachment is the same
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
                print("Incorrect number of layers!");
                // Make sure the number of layers for each // attachment is the same
                break;
        }
    }
    
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    
}

void shadowScene::setupShadowBuffer() {
    
    int shadowMapWidth = windowWidth * shadowQuality;
    int shadowMapHeight = windowHeigth * shadowQuality;
    
    glGenTextures(1, &shadowMap);
    glBindTexture(GL_TEXTURE_2D_ARRAY, shadowMap);
    
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_DEPTH_COMPONENT, shadowMapWidth, shadowMapHeight, frustums, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameterf( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
    glTexParameterf( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );
    
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

    glGenFramebuffers(1, &shadowFbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, shadowFbo);
    glDrawBuffers(0, NULL);
    
//    glFramebufferTexture3D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_ARRAY, shadowMap, 0, frustums);
//    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, shadowMap, 0);
//    for (int i = 0; i < frustums; i++) {
//        glFramebufferTextureLayer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, shadowMap, 0, GLint(i));
//    }
//    
//    //don't bind color at all;
//    glDrawBuffer(GL_NONE);
//    glReadBuffer(GL_NONE);
//    
//    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap[i], 0);
    
    GLenum fboStatus;
    fboStatus = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
    if (fboStatus != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "Creating shadow framebuffer failed with code: " << fboStatus << std::endl;
        switch (fboStatus)
        {
            case GL_FRAMEBUFFER_UNDEFINED:
                print("No window?");
                // Oops, no window exists?
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                print("Incomplete attachment");
                // Check the status of each attachment
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                print("No buffers!");
                // Attach at least one buffer to the FBO
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                print("Incomplete draw buffer");
                // Check that all attachments enabled via
                // glDrawBuffers exist in FBO
            case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                print("No read buffer!");
                // Check that the buffer specified via // glReadBuffer exists in FBO
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                print("Unsuported");
                // Reconsider formats used for attached buffers break;
            case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                print("Incomplete multisample!");
                // Make sure the number of samples for each // attachment is the same
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
                print("Incorrect number of layers!");
                // Make sure the number of layers for each // attachment is the same
                break;
        }
    }
    
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

    
    
        //setup the depth texture;
//        glGenTextures(1, &shadowMap[i]);
//        glBindTexture(GL_TEXTURE_2D, shadowMap[i]);
//        
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapWidth, shadowMapHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
//        
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        
//        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
//        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );
//
//        glBindTexture(GL_TEXTURE_2D, 0);
//        
//        //setup shadowFrameBuffer;
//        glGenFramebuffers(1, &fbo[i]);
//        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo[i]);
//        
//        //don't bind color at all;
//        glDrawBuffer(GL_NONE);
//        glReadBuffer(GL_NONE);
//        
//        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap[i], 0);
//        
//        GLenum fboStatus;
//        fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
//        if (fboStatus != GL_FRAMEBUFFER_COMPLETE) {
//            print("Creating shadow framebuffer failed!");
//        }
//        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

void shadowScene::buttonPressed(int index) {
    print(index);
}

void shadowScene::getKeyInput(int key, int action) {
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
                testCamera->setPosition(camera->getPosition());
                testCamera->setRX(camera->getRX());
                testCamera->setRY(camera->getRY());
                testCamera->setRZ(camera->getRZ());
            } else if (action == GLFW_RELEASE) {
            }
        } else {
            std::cout << "Key: " << key << " action: " << action << std::endl;
        }
}

void shadowScene::mouseKeyInput(int button, int action) {
    
}

void shadowScene::cursorPosition(double x, double y) {
    
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

shadowScene::~shadowScene() {
    
}