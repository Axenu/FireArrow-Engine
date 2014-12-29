//
//  FAHUDElement.h
//  FireArrow
//
//  Created by Simon Nilsson on 26/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAHUDElement__
#define __FireArrow__FAHUDElement__

#include <stdio.h>
#include "FANode.h"
#include "FAShader.h"
#include "FABBAA2D.h"

class FAHUDElement : public FANode, public FABBAA2D {
    
private:
    
public:
    
    FAHUDElement();
    
    void setID(int id);
    int getID();
    
    virtual bool handleClick(glm::vec2 p);
    
    ~FAHUDElement();
    
protected:
    bool isClickable;
    int id;
    
    virtual void onUpdate(float dt);
};

#endif /* defined(__FireArrow__FAHUDElement__) */
