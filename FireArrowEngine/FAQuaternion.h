//
//  FAQuaternion.h
//  FireArrow
//
//  Created by Simon Nilsson on 20/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAQuaternion__
#define __FireArrow__FAQuaternion__

#include <stdio.h>
#include <glm/glm.hpp>

class FAQuaternion {
	
	
public:
	FAQuaternion();
	FAQuaternion(const glm::vec3 &n, float a);
	const FAQuaternion Inverted() const;
	const FAQuaternion operator*(const FAQuaternion &q) const;
	
	float w,x,y,z;
};

#endif /* defined(__FireArrow__FAQuaternion__) */
