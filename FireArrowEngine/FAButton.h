//
//  FAButton.h
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAButton__
#define __FireArrow__FAButton__

#include <stdio.h>
#include "FAPlane2D.h"
#include "FAHUDElement.h"

class FAButton : public FAPlane2D {
    
public:
    
    FAButton();
    
    void setSize(float width, float height);
    
    ~FAButton();
    
};

#endif /* defined(__FireArrow__FAButton__) */
