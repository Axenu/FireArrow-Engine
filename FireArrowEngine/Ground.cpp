//
//  Ground.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 9/4/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "Ground.h"

Ground::Ground() {
	
	name = "Ground";
	
	std::vector<std::vector<glm::vec3>> verticies;
	std::vector<GLfloat> vert;
	std::vector<GLushort> indices;
	
	for (int x = 0; x < width; x++) {
		std::vector<glm::vec3> temp;
		for (int y = 0; y < height; y++) {
			temp.push_back(glm::vec3(x + randomDiff(),randomDiff(),y + randomDiff()));
		}
		verticies.push_back(temp);
	}
	int indcount = 0;
	for (int x = 0; x < width - 1; x++) {
		for (int y = 0; y < height - 1; y++) {
			glm::vec3 p1 = verticies[x + 1][y];
			glm::vec3 p2 = verticies[x][y];
			glm::vec3 p3 = verticies[x][y + 1];
			
			glm::vec3 v1 = p2 - p1;
			glm::vec3 v2 = p3 - p1;
			
			glm::vec3 normal = glm::normalize(glm::cross(v1, v2));
			vert.push_back(p1.x);
			vert.push_back(p1.y);
			vert.push_back(p1.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			vert.push_back(p2.x);
			vert.push_back(p2.y);
			vert.push_back(p2.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			vert.push_back(p3.x);
			vert.push_back(p3.y);
			vert.push_back(p3.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			
			indices.push_back(indcount);
			indcount++;
			indices.push_back(indcount);
			indcount++;
			indices.push_back(indcount);
			indcount++;
			
			p1 = verticies[x][y + 1];
			p2 = verticies[x + 1][y + 1];
			p3 = verticies[x + 1][y];
			
			v1 = p2 - p1;
			v2 = p3 - p1;
			
			normal = glm::normalize(glm::cross(v1, v2));
			
			vert.push_back(p1.x);
			vert.push_back(p1.y);
			vert.push_back(p1.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			vert.push_back(p2.x);
			vert.push_back(p2.y);
			vert.push_back(p2.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			vert.push_back(p3.x);
			vert.push_back(p3.y);
			vert.push_back(p3.z);
			vert.push_back(normal.x);
			vert.push_back(normal.y);
			vert.push_back(normal.z);
			
			indices.push_back(indcount);
			indcount++;
			indices.push_back(indcount);
			indcount++;
			indices.push_back(indcount);
			indcount++;

		}
	}
	FAModel *m = new FAModel();
	FAShader *s = new FAShader("Basic.vert","Basic.frag");
	m->setShader(s);
	m->SetModel(vert, indices);
	m->setColor(FAColorDarkGreen);
	addNode(m);
	delete s;
}

float Ground::randomDiff() {
	return ((arc4random() % 1000) / 1000.0 - 0.5)/3;
}
