//
//  FAShaderNode.h
//  FireArrow
//
//  Created by Simon Nilsson on 05/07/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAShaderNode__
#define __FireArrow__FAShaderNode__

#include <iostream>
#include <map>

#include "FAShader.h"

class FAShaderNode {
    
private:
    std::map<std::string, FAShader*> *shaders;
public:
    FAShaderNode();
    ~FAShaderNode();
    void addShader(FAShader *shader);
    FAShader* getShader(std::string s);
    FAShader& operator[](std::string idx);

};

#endif /* defined(__FireArrow__FAShaderNode__) */
