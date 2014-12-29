//
//  FABBAA2D.h
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FABBAA2D__
#define __FireArrow__FABBAA2D__

#include <stdio.h>
#include <glm/glm.hpp>
#include "FASize.h"

class FABBAA2D {
    
private:
    
public:
    
    FABBAA2D();
    FABBAA2D(glm::vec2 position, FASize size);
    FABBAA2D(float x, float y, float width, float height);
    
    bool collideWith(const FABBAA2D &bb);
    bool collideWith(const glm::vec2 v);
    
protected:
    
    glm::vec2 bbPosition;
    glm::vec2 anchorPoint; //top <^ bottom v>
    FASize size;
    
    glm::vec2 max;
    glm::vec2 min;
    
    void calculateMaxAndMin();
};

#endif /* defined(__FireArrow__FABBAA2D__) */
