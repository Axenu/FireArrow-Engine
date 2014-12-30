//
//  FAModel.h
//  FireArrow
//
//  Created by Simon Nilsson on 16/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAModel__
#define __FireArrow__FAModel__

#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "FAShader.h"
#include "FANode.h"

class FAModel : public FANode {
private:
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
	GLuint myShadowVBO;
	GLuint myShadowVAO;
    GLuint positionLoc;
    GLuint normalLoc;
    GLuint colorUniformLoc;
	GLuint positionLocShadow;
    glm::vec4 color;
	FAShader shadowShader;
    GLushort numberOfVertices;
    GLint projectionMatrixLocation;
    GLint viewMatrixLocation;
    GLint modelMatrixLocation;
	GLint viewProjectionMatrixLocation;
    GLint shadowModelMatrixLocation;
	GLint textureMatrixLocation;
	GLint shadowMapLocation;
	
	std::vector<float> getVerticeArray(std::ifstream file, int numberOfVertices);
	
public:
    
    FAModel();
    ~FAModel();
    void setShader(FAShader *shader);
    void SetModel(std::vector<GLfloat> vertices, std::vector<GLushort> indices);
    void SetModel(std::string path);
	void SetFAModel(std::string path);
	void SetXModel(std::string path);
    void setColor(glm::vec4 c);
    
protected:
	virtual void onRender(FACamera *camera);
	virtual void onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix);
    virtual void onRenderShadow(glm::mat4 c);
	virtual void onUpdate(float dt);
	
};

#endif /* defined(__FireArrow__FAModel__) */
