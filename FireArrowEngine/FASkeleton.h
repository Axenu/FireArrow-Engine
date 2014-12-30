//
//  FASkeleton.h
//  FireArrow
//
//  Created by Simon Nilsson on 29/09/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FASkeleton__
#define __FireArrow__FASkeleton__
#define GLM_FORCE_RADIANS
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "FANode.h"
#include "FACamera.h"
#include "FAShader.h"
#include "FAPrint.h"
#include "FABone.h"

class FASkeleton : public FANode {
private:
	float timer;
	
	//model GL-Stuff
	GLuint positionLocation;
	GLuint normalLocation;
	GLuint indexLocation;
	GLuint weightLocation;
	GLuint colorLocation;
	GLuint projectionMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint modelMatrixLocation;
	GLuint boneMatrixLocation;
	
	GLsizei numberOfVertices;
	GLuint VBO;
	GLuint EBO;
	GLuint VAO;
	
	//Bones
	FABone *rootBone;
	std::vector<FABone *> bones;
	std::vector<glm::mat4> invBindPose;
	std::vector<glm::mat4> animatedXForm;
	
	
public:
	FASkeleton();
	~FASkeleton();
	
	void setShader(FAShader *shader);
	void SetFAModel(std::string path);
	void SetModel(std::vector<GLfloat> vertices, std::vector<GLushort> indices);
	void loadModel();
	void adjustPositions(FABone *b, glm::vec3 diff);
	void setupBoneMatrices(FABone *b);
	int calculateBoneMatrices(FABone *b, int i);
	void setupInverseBindPose(FABone *b);
	
protected:
	virtual void onRender(FACamera *camera);
	virtual void onRenderShadow(FACamera camera);
    virtual void onUpdate(float dt);
	
};

#endif /* defined(__FireArrow__FASkeleton__) */
