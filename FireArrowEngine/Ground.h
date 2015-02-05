//
//  Ground.h
//  FireArrow
//
//  Created by Simon Nilsson on 9/4/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__Ground__
#define __FireArrow__Ground__

#include <stdio.h>
#include <vector>
#include <glm/glm.hpp>
#include "FAModel.h"

class Ground : public FANode {
	
private:
	float randomDiff();
	float tilesize = 2;
	float width = 100;
	float height = 100;
	
public:
	Ground();
    Ground(int size);
};


#endif /* defined(__FireArrow__Ground__) */
