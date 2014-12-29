//
//  FASkeleton.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 29/09/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FASkeleton.h"

FASkeleton::FASkeleton() {
}

void FASkeleton::setShader(FAShader *shader) {
	
	this->shader = shader;
	
	glUseProgram(shader->shaderProgram);
	
	positionLocation = glGetAttribLocation(shader->shaderProgram, "in_Position");
	normalLocation = glGetAttribLocation(shader->shaderProgram, "in_Normal");
	indexLocation = glGetAttribLocation(shader->shaderProgram, "in_Index");
	weightLocation = glGetAttribLocation(shader->shaderProgram, "in_Weight");
	colorLocation = glGetAttribLocation(shader->shaderProgram, "in_Color");
	
	if(positionLocation == -1) {
		std::cout << "error positionLocation" << std::endl;
	}
	if(normalLocation == -1) {
		std::cout << "error normalLocation" << std::endl;
	}
	if(indexLocation == -1) {
		std::cout << "error indexLocation" << std::endl;
	}
	if(weightLocation == -1) {
		std::cout << "error weightLocation" << std::endl;
	}
	if(colorLocation == -1) {
		std::cout << "error colorLocation" << std::endl;
	}
	
		// Get matrices uniform locations
	projectionMatrixLocation = glGetUniformLocation(shader->shaderProgram,"projectionMatrix");
	viewMatrixLocation = glGetUniformLocation(shader->shaderProgram, "viewMatrix");
	modelMatrixLocation = glGetUniformLocation(shader->shaderProgram, "modelMatrix");
	boneMatrixLocation = glGetUniformLocation(shader->shaderProgram, "bones");
	
	if(projectionMatrixLocation == -1) {
		std::cout << "error projectionMatrixLocation" << std::endl;
	}
	if(viewMatrixLocation == -1) {
		std::cout << "error viewMatrixLocation" << std::endl;
	}
	if(modelMatrixLocation == -1) {
		std::cout << "error modelMatrixLocation" << std::endl;
	}
	if(boneMatrixLocation == -1) {
		std::cout << "error boneMatrixLocation" << std::endl;
	}
}

void FASkeleton::SetFAModel(std::string path) {
	std::ifstream file (path);
	std::vector<glm::vec3> vertexArray;
	std::vector<glm::vec3> normalArray;
	std::vector<int> colorArray = std::vector<int>();
	std::vector<glm::vec3> materialArray = std::vector<glm::vec3>();
	std::vector<glm::vec4> weightArray;
	std::vector<GLfloat> vertices;
	std::vector<GLushort> indices;
	
	if (file.is_open() && file.is_open()) {
		
		while (!file.eof()) {
			
			std::string f;
			int count;
			file >> f;
			if (f == "v") {
				file >> count;
				vertexArray = std::vector<glm::vec3>();
				for (int i = 0; i < count; i++) {
					glm::vec3 vec;
					file >> vec.x >> vec.y >> vec.z;
					vertexArray.push_back(vec);
				}
			} else if (f == "n") {
				file >> count;
				normalArray = std::vector<glm::vec3> ();
				for (int i = 0; i < count; i++) {
					glm::vec3 normal;
					file >> normal.x >> normal.y >> normal.z;
					normalArray.push_back(normal);
				}
			} else if (f == "c") {
				file >> count;
				for (int i = 0; i < count; i++) {
					int index;
					file >> index;
					colorArray.push_back(index);
				}
			} else if (f == "m") {
				file >> count;
				for (int i = 0; i < count; i++) {
					glm::vec3 color;
					file >> color.x >> color.y >> color.z;
					materialArray.push_back(color);
				}
			} else if (f == "w") {
				file >> count;
				for (int i = 0; i < count; i++) {
					glm::vec4 v;
					file >> v.x >> v.y >> v.z >> v.w;
					weightArray.push_back(v);
				}
			} else if (f == "i") {
				file >> count;
				indices = std::vector<GLushort> ();
				vertices = std::vector<GLfloat> ();
				for (int i = 0; i < count * 3; i++) {
					indices.push_back(i);
				}
				for (int i = 0; i < count; i++) {
					float v1, v2, v3, n;
					file >> v1 >> v2 >> v3 >> n;
					
					int face = colorArray[n];
					
					vertices.push_back(vertexArray[v1].x);
					vertices.push_back(vertexArray[v1].y);
					vertices.push_back(vertexArray[v1].z);
					vertices.push_back(normalArray[n].x);
					vertices.push_back(normalArray[n].y);
					vertices.push_back(normalArray[n].z);
					vertices.push_back(weightArray[v1].x);
					vertices.push_back(weightArray[v1].z);
					vertices.push_back(weightArray[v1].y);
					vertices.push_back(weightArray[v1].w);
					vertices.push_back(materialArray[face].x);
					vertices.push_back(materialArray[face].y);
					vertices.push_back(materialArray[face].z);
					
					vertices.push_back(vertexArray[v2].x);
					vertices.push_back(vertexArray[v2].y);
					vertices.push_back(vertexArray[v2].z);
					vertices.push_back(normalArray[n].x);
					vertices.push_back(normalArray[n].y);
					vertices.push_back(normalArray[n].z);
					vertices.push_back(weightArray[v2].x);
					vertices.push_back(weightArray[v2].z);
					vertices.push_back(weightArray[v2].y);
					vertices.push_back(weightArray[v2].w);
					vertices.push_back(materialArray[face].x);
					vertices.push_back(materialArray[face].y);
					vertices.push_back(materialArray[face].z);
					
					vertices.push_back(vertexArray[v3].x);
					vertices.push_back(vertexArray[v3].y);
					vertices.push_back(vertexArray[v3].z);
					vertices.push_back(normalArray[n].x);
					vertices.push_back(normalArray[n].y);
					vertices.push_back(normalArray[n].z);
					vertices.push_back(weightArray[v3].x);
					vertices.push_back(weightArray[v3].z);
					vertices.push_back(weightArray[v3].y);
					vertices.push_back(weightArray[v3].w);
					vertices.push_back(materialArray[face].x);
					vertices.push_back(materialArray[face].y);
					vertices.push_back(materialArray[face].z);
				}
			} else if (f == "b") {
				file >> count;
				for (int i = 0; i < count; i++) {
					FABone *b = new FABone();
					int parent;
					std::string name;
					glm::vec3 position;
					file >> name;
					file >> parent;
					file >> position.x >> position.y >> position.z;
					position = glm::vec3(-position.z, position.y, -position.x);
					b->setName(name);
					b->setPosition(position);
					if (parent != -1) {
						b->setParent(bones[parent]);
					} else {
						b->setParent(NULL);
					}
					b->setScale(glm::vec3(1,1,1));
					b->setRotation(glm::vec3(0,0,0));
					bones.push_back(b);
				}
				
				
			} else {
				std::cout << "Unknown character! asuming it's a comment: \"" << f << "\"" << std::endl;
			}
		}
	}
	rootBone = bones[0];
	adjustPositions(rootBone, glm::vec3());
	setupBoneMatrices(rootBone);
	SetModel(vertices, indices);
}

void FASkeleton::adjustPositions(FABone *b, glm::vec3 diff) {
	b->setPosition(b->getPosition() - diff);
	glm::vec3 newDiff = diff + b->getPosition();
	for (FABone *f : b->getChildren()) {
		adjustPositions(f, newDiff);
	}
}

void FASkeleton::setupBoneMatrices(FABone *b) {
	glm::mat4 S = glm::scale(glm::mat4(1), b->getScale());
	glm::mat4 R = glm::rotate(glm::mat4(1), b->getRotation().x, glm::vec3(1,0,0));
	R = glm::rotate(R, b->getRotation().y, glm::vec3(0,1,0));
	R = glm::rotate(R, b->getRotation().z, glm::vec3(0,0,1));
	glm::mat4 T = glm::translate(glm::mat4(1), b->getPosition());
	b->setLocalMatrix(T*R*S);
	
	if (b->getParent() != nullptr) {
		b->setCombinedMatrix(b->getParent()->getCombinedMatrix() * b->getLocalMatrix());
	} else {
		b->setCombinedMatrix(b->getLocalMatrix());
	}
	
	invBindPose.push_back(glm::inverse(b->getCombinedMatrix()));
	
	animatedXForm.push_back(b->getCombinedMatrix());
	
	for (FABone *c : b->getChildren()) {
		setupBoneMatrices(c);
	}
}

int FASkeleton::calculateBoneMatrices(FABone *b, int i) {
	glm::mat4 S = glm::scale(glm::mat4(1), b->getScale());
	glm::mat4 R = glm::rotate(glm::mat4(1), b->getRotation().x, glm::vec3(1,0,0));
	R = glm::rotate(R, b->getRotation().y, glm::vec3(0,1,0));
	R = glm::rotate(R, b->getRotation().z, glm::vec3(0,0,1));
	glm::mat4 T = glm::translate(glm::mat4(1), b->getPosition());
	b->setLocalMatrix(T*R*S);
	
	if (b->getParent() != nullptr) {
		b->setCombinedMatrix(b->getParent()->getCombinedMatrix() * b->getLocalMatrix());
	} else {
		b->setCombinedMatrix(b->getLocalMatrix());
	}
	animatedXForm[i] = b->getCombinedMatrix() * invBindPose[i];
	
	for (FABone *c : b->getChildren()) {
		i = calculateBoneMatrices(c, i + 1);
	}
	return i;
}

void FASkeleton::SetModel(std::vector<GLfloat> vertices, std::vector<GLushort> indices) {
	
	if (shader->shaderProgram == 0) {
		std::cout << "No valid shader for model" << std::endl;
		return;
	}
	
	numberOfVertices = (GLsizei)indices.size();
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glEnableVertexAttribArray(positionLocation);
	glEnableVertexAttribArray(normalLocation);
	glEnableVertexAttribArray(indexLocation);
	glEnableVertexAttribArray(weightLocation);
	glEnableVertexAttribArray(colorLocation);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 13 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
	glVertexAttribPointer(normalLocation, 3, GL_FLOAT, GL_FALSE, 13 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)));
	glVertexAttribPointer(indexLocation, 2, GL_FLOAT, GL_FALSE, 13 * sizeof(GLfloat), (GLvoid *) (6 * sizeof(GLfloat)));
	glVertexAttribPointer(weightLocation, 2, GL_FLOAT, GL_FALSE, 13 * sizeof(GLfloat), (GLvoid *) (8 * sizeof(GLfloat)));
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 13 * sizeof(GLfloat), (GLvoid *) (10 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
}

void FASkeleton::onRender(FACamera *camera) {
	
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(positionLocation);
	glEnableVertexAttribArray(normalLocation);
	glEnableVertexAttribArray(indexLocation);
	glEnableVertexAttribArray(weightLocation);
	glEnableVertexAttribArray(colorLocation);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	
	glUseProgram(shader->shaderProgram);
	
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(boneMatrixLocation, (GLsizei) animatedXForm.size(), GL_FALSE, &animatedXForm[0][0][0]);
	
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(positionLocation);
	glDisableVertexAttribArray(normalLocation);
	glDisableVertexAttribArray(indexLocation);
	glDisableVertexAttribArray(weightLocation);
	glDisableVertexAttribArray(colorLocation);
	glBindVertexArray(0);
	
	glUseProgram(0);
}

void FASkeleton::onRenderShadow(FACamera camera) {
	print("TODO Shadow Skeleton");
}

void FASkeleton::onUpdate(float dt) {
    timer += dt;
    //	bones[3]->setRotation(glm::vec3(1,0,0));
    //			bones[2]->setRotation(glm::vec3(0,0,glm::sin(timer)));
    bones[3]->setRotation(glm::vec3(sinf(timer * 2)/2,0,0));
    //	bones[4]->setRotation(glm::vec3(0,0,glm::sin(timer)));
    //	bones[2]->setScale(glm::vec3(1,1,2));
    //	bones[4].orientation = glm::vec3(0,0,timer);
    
    calculateBoneMatrices(rootBone, 0);
}

FASkeleton::~FASkeleton() {
	
}