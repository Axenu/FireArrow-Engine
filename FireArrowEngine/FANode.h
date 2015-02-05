//
//  FANode.h
//  FireArrow
//
//  Created by Simon Nilsson on 14/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FANode__
#define __FireArrow__FANode__

#include <iostream>
#include <vector>
#include "FACamera.h"
#include "FATexture.h"
#include "FAShader.h"
#include "FAPrint.h"
#include "FireArrow.h"

#pragma mark Colors

#define FAColorRed glm::vec4(1,0,0,1)
#define FAColorDarkRed glm::vec4(0.5,0,0,1)
#define FAColorGreen glm::vec4(0,1,0,1)
#define FAColorDarkGreen glm::vec4(0,0.5,0,1)
#define FAColorBlue glm::vec4(0,0,1,1)
#define FAColorDarkBlue glm::vec4(0,0,0.5,1)
#define FAColorBlack glm::vec4(0,0,0,1)
#define FAColorWhite glm::vec4(1,1,1,1)
#define FAColorMagenta glm::vec4(0,1,1,1)
#define FAColorYellow glm::vec4(1,1,0,1)
#define FAColorPurple glm::vec4(1,0,1,1)
#define FAColorGrey glm::vec4(0.5,0.5,0.5,1)
#define FAColorDarkGrey glm::vec4(0.25,0.25,0.25,1)
#define FAColorLigthGrey glm::vec4(0.75,0.75,0.75,1)


class FANode {
	friend class Ground;
private:
    std::vector<FANode*> children;
    std::string name;
	bool isActive = true;
	bool hasShadow = true;
	
public:
    
#pragma mark Constructor
    
    FANode();
    FANode(const std::string &name);
    
#pragma mark Class Methods

    void render(FACamera *camera);
	void render(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix);
    void renderShadow(glm::mat4 c);
    
    void update(float dt);
    void update(float dt, glm::mat4 parentModelMatrix);
	
	void Activate();
	void Deactivate();
    void setAvtive(bool b);
    
	void addNode(FANode *node);
    void removeNode(FANode *node);
	
    
#pragma mark Setters
    
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setPos(glm::vec3 pos);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);
    void move(glm::vec3 p);
    void setScale(float p);
    void setScale(glm::vec3 p);
    void setScale(float x, float y);
    void setRX(float rx);
    void setRY(float ry);
    void setRZ(float rz);
    void rotateX(float f);
    void rotateY(float f);
    void rotateZ(float f);
    void setName(const std::string &name);
    void setParent(FANode* parentnode);
    void setShader(FAShader *shader);
	
#pragma mark Getters
    
	float getX();
	float getY();
	float getZ();
    float getRX();
    float getRY();
    float getRZ();
	glm::vec3 getScale();
    glm::vec3 getPos();
    glm::vec3 getRotation();
    std::string getName();
    FANode* getParent();
    std::vector<FANode*>& getChildren();
    long getVertexCount();
    
#pragma mark Deconstructor
    
    virtual ~FANode();
    
protected:
	virtual void onRender(FACamera *camera){}
	virtual void onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix){onRender(camera);}
	virtual void onRenderShadow(glm::mat4 c){}
    virtual void onUpdate(float dt){}
    
    FANode *parent;
    FATexture texture;
    FAShader *shader;
    glm::mat4x4 modelMatrix;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    long vertices;
};

#endif /* defined(__FireArrow__FANode__) */
