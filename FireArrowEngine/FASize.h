//
//  FASize.h
//  FireArrow
//
//  Created by Simon Nilsson on 24/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FASize__
#define __FireArrow__FASize__

#include <stdio.h>

class FASize {
    
private:
    
public:
    float width;
    float height;
    
    FASize();
    FASize(float s);
    FASize(float width, float height);
    
    float getArea() const;
};

#endif /* defined(__FireArrow__FASize__) */
