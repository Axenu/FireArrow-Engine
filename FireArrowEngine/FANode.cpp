//
//  FANode.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 14/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FANode.h"

#pragma mark Constructor

FANode::FANode() {
    name = "FANode";
    modelMatrix = glm::mat4(1.0);
    scale = glm::vec3(1,1,1);
    vertices = 0;
}

FANode::FANode(const std::string& name) : name(name), parent(NULL) {
	modelMatrix = glm::mat4(1.0);
	scale = glm::vec3(1,1,1);
    vertices = 0;
}

#pragma mark Class Methods

void FANode::render(FACamera *camera) {
    if (!isActive)
        return;
    onRender(camera);
    for(FANode *node : children)
        node->render(camera);
}

void FANode::render(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix) {
    if (!isActive)
        return;
    onRender(camera, texture, textureMatrix);
    for(FANode *node : children)
        node->render(camera, texture, textureMatrix);
}

void FANode::renderShadow(glm::mat4 c) {
    if (!hasShadow)
        return;
    if (!isActive)
        return;
    onRenderShadow(c);
    for(FANode *node : children)
        node->renderShadow(c);
}

//void FANode::renderShadow(std::vector<glm::mat4> &c) {
//    if (!hasShadow)
//        return;
//    if (!isActive)
//        return;
//    onRenderShadow(c);
//    for(FANode *node : children)
//        node->renderShadow(c);
//}

void FANode::update(float dt) {
    if (!isActive)
        return;
    modelMatrix = glm::mat4();
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::scale(modelMatrix, scale);
    modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1,0,0));
    modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0,1,0));
    modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0,0,1));
    onUpdate(dt);
    for(FANode* node : children)
        node->update(dt, modelMatrix);
}

void FANode::update(float dt, glm::mat4 parentModelMatrix) {
    if (!isActive)
        return;
    modelMatrix = glm::mat4();
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::scale(modelMatrix, scale);
    modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1,0,0));
    modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0,1,0));
    modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0,0,1));
    modelMatrix = parentModelMatrix * modelMatrix;
    onUpdate(dt);
    for(FANode* node : children)
        node->update(dt, modelMatrix);
}

void FANode::Activate() {
	isActive = true;
}

void FANode::Deactivate() {
	isActive = false;
}

void FANode::setAvtive(bool b) {
    this->isActive = b;
}

void FANode::addNode(FANode *node)
{
    this->vertices += node->vertices;
    node->setParent(this);
    children.push_back(node);
}

void FANode::removeNode(FANode *node) {
    for(auto itr = begin(children); itr != children.end(); itr++) {
        if(node == (*itr)) {
            children.erase(itr);
            return;
        }
    }
}

#pragma mark Setters

void FANode::setX(float x) {
    position.x = x;
}

void FANode::setY(float y) {
    position.y = y;
}

void FANode::setZ(float z) {
    position.z = z;
}

void FANode::setPos(glm::vec3 pos) {
    position = pos;
}

void FANode::moveX(float x) {
    position.x += x;
}

void FANode::moveY(float y) {
    position.y += y;
}

void FANode::moveZ(float z) {
    position.z += z;
}

void FANode::move(glm::vec3 p) {
    position += p;
}

void FANode::setScale(float p) {
    scale = glm::vec3(p,p,p);
}

void FANode::setScale(glm::vec3 p) {
    scale = p;
}

void FANode::setScale(float x, float y) {
    scale.x = x;
    scale.y = y;
}

void FANode::setRX(float rx) {
    rotation.x = rx;
}

void FANode::setRY(float ry) {
    rotation.y = ry;
}

void FANode::setRZ(float rz) {
    rotation.z = rz;
}

void FANode::rotateX(float f) {
    rotation.x += f;
}

void FANode::rotateY(float f) {
    rotation.y += f;
}

void FANode::rotateZ(float f) {
    rotation.z += f;
}

void FANode::setName(const std::string &name) {
    this->name = name;
}

void FANode::setParent(FANode *parentnode) {
    parent = parentnode;
}

void FANode::setShader(FAShader *shader) {
    this->shader = shader;
}

#pragma mark Getters

float FANode::getX()  {
    return position.x;
}

float FANode::getY()  {
    return position.y;
}

float FANode::getZ()  {
    return position.z;
}

float FANode::getRX()  {
    return rotation.x;
}

float FANode::getRY()  {
    return rotation.y;
}

float FANode::getRZ()  {
    return rotation.z;
}

glm::vec3 FANode::getScale()  {
    return scale;
}

glm::vec3 FANode::getPos()  {
    return position;
}

glm::vec3 FANode::getRotation()  {
    return rotation;
}

std::string FANode::getName()  {
    return name;
}

FANode *FANode::getParent() {
    return parent;
}

std::vector<FANode*>& FANode::getChildren() {
    return children;
}

long FANode::getVertexCount() {
    return this->vertices;
}

#pragma mark Deconstructor

FANode::~FANode() {
    for(FANode *node : children) {
        delete node;
    }
}