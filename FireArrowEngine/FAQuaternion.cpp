//
//  FAQuaternion.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 20/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAQuaternion.h"

FAQuaternion::FAQuaternion() {
	
}

FAQuaternion::FAQuaternion(const glm::vec3 &n, float a) {
	w = cos(a/2);
	x = n.x*sin(a/2);
	y = n.y*sin(a/2);
	z = n.z*sin(a/2);
}

const FAQuaternion FAQuaternion::Inverted() const {
	FAQuaternion q;
	q.w = w;
	q.x = -x;
	q.y = -y;
	q.z = -z;
	return q;
}

const FAQuaternion FAQuaternion::operator*(const FAQuaternion &q) const {
	FAQuaternion r;
		//r.w = w*q.w + v.Dot(q.v);
		//r.v = v*q.w + q.v*w + v.Cross(q.v);
	return r;
}