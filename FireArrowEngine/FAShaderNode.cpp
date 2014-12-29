//
//  FAShaderNode.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 05/07/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAShaderNode.h"

FAShaderNode::FAShaderNode() {
    shaders = new std::map<std::string, FAShader*>();
}

void FAShaderNode::addShader(FAShader *shader) {
    shaders->insert(std::pair<std::string, FAShader*>(shader->getName(), shader));
}

FAShader* FAShaderNode::getShader(std::string s) {
    if (shaders->find(s) == shaders->end()) {
        return new FAShader((s + ".vert").c_str(), (s + ".frag").c_str());
    } else {
        return shaders->at(s);
    }
}

FAShader& FAShaderNode::operator[](std::string idx) {
    if (shaders->find(idx) == shaders->end()) {
        return *new FAShader((idx + ".vert").c_str(), (idx + ".frag").c_str());
    } else {
        return *shaders->at(idx);
    }
}

FAShaderNode::~FAShaderNode() {
    
}