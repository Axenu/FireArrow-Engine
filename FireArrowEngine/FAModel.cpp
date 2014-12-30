//
//  FAModel.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 16/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAModel.h"

FAModel::FAModel() {
    this->setName("FAModel");
	this->setColor(glm::vec4(0.5,0.5,0.5,1));
	this->setScale(1);
}

FAModel::~FAModel() {
    //dealloc
}

void FAModel::setShader(FAShader *shader) {
    shadowShader = FAShader("BasicWithShadows.vert", "BasicWithShadows.frag");
    
    glUseProgram(shadowShader.shaderProgram);
	
	positionLocShadow = glGetAttribLocation(shadowShader.shaderProgram, "in_Position");
	viewProjectionMatrixLocation = glGetUniformLocation(shadowShader.shaderProgram,"viewProjectionMatrix");
    shadowModelMatrixLocation = glGetUniformLocation(shadowShader.shaderProgram,"modelMatrix");
	
	if(positionLocShadow == -1) {
		std::cout << "error positionLocShadow" << std::endl;
	}
	if(viewProjectionMatrixLocation == -1) {
		std::cout << "error viewProjectionMatrixLocation" << std::endl;
	}
    if(shadowModelMatrixLocation == -1) {
        std::cout << "error shadowModelMatrixLocation" << std::endl;
    }
	
	this->shader = new FAShader("BasicShadow");
	
	glUseProgram(this->shader->shaderProgram);
	
    positionLoc = glGetAttribLocation(this->shader->shaderProgram, "in_Position");
    normalLoc = glGetAttribLocation(this->shader->shaderProgram, "in_Normal");
	
		// Get matrices uniform locations
    colorUniformLoc = glGetUniformLocation(this->shader->shaderProgram, "color");
    projectionMatrixLocation = glGetUniformLocation(this->shader->shaderProgram,"projectionMatrix");
    viewMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "viewMatrix");
	modelMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "modelMatrix");
	textureMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "textureMatrix");
	shadowMapLocation = glGetUniformLocation(this->shader->shaderProgram, "shadowMap");
	
	
	
	if(positionLoc == -1) {
		std::cout << "error positionLoc" << std::endl;
	}
	if(normalLoc == -1) {
		std::cout << "error normalLoc" << std::endl;
	}
	if(colorUniformLoc == -1) {
		std::cout << "error colorUniformLoc" << std::endl;
	}
	if(projectionMatrixLocation == -1) {
		std::cout << "error projectionMatrixLocation" << std::endl;
	}
	if(viewMatrixLocation == -1) {
		std::cout << "error viewMatrixLocation" << std::endl;
	}
	if(modelMatrixLocation == -1) {
		std::cout << "error modelMatrixLocation" << std::endl;
	}
	if(textureMatrixLocation == -1) {
		std::cout << "error textureMatrixLocation" << std::endl;
	}
	if(shadowMapLocation == -1) {
		std::cout << "error shadowMapLocation" << std::endl;
	}
}

void FAModel::SetModel(std::vector<GLfloat> vertices, std::vector<GLushort> indices) {
    
    if (shader->shaderProgram == 0) {
        std::cout << "No valid shader for model" << std::endl;
        return;
    }
	
    numberOfVertices = indices.size();
    
    glGenBuffers(1, &myVBO);
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &myEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glGenVertexArrays(1, &myVAO);
    glBindVertexArray(myVAO);
    
    glEnableVertexAttribArray(positionLoc);
    glEnableVertexAttribArray(normalLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
    glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
	
	
	glGenBuffers(1, &myShadowVBO);
	glBindBuffer(GL_ARRAY_BUFFER, myShadowVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glGenVertexArrays(1, &myShadowVAO);
	glBindVertexArray(myShadowVAO);
	
	glEnableVertexAttribArray(positionLocShadow);
	
	glBindBuffer(GL_ARRAY_BUFFER, myShadowVBO);
	glVertexAttribPointer(positionLocShadow, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void FAModel::SetModel(std::string path) {
	
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;
    std::vector<GLfloat> out_vertices;
    std::vector<glm::vec2> out_uvs;
    std::vector<glm::vec3> out_normals;
    
    
    FILE * file = fopen(path.c_str(), "r");
	if( file == NULL ){
        std::cout << "FAModel failed to open file: " << path << std::endl;
		getchar();
	}
    
	while( 1 ){
        
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;
		
		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "vn" ) == 0 ){
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
			temp_normals.push_back(normal);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2] );
			if (matches != 6){
				printf("File can't be read!\n");
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}else{
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
        
	}
    
	// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){
        
		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
//		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
//		glm::vec2 uv = temp_uvs[ uvIndex-1 ];
		glm::vec3 normal = temp_normals[ normalIndex-1 ];
		
		// Put the attributes in buffers
		out_vertices.push_back(vertex.x);
        out_vertices.push_back(vertex.y);
        out_vertices.push_back(vertex.z);
//		out_vertices.push_back(uv);
		out_vertices.push_back(normal.x);
        out_vertices.push_back(normal.y);
        out_vertices.push_back(normal.z);
	}
    std::vector<GLushort> indices;
    for (int i = 0; i < out_vertices.size()/6; i++) {
        indices.push_back(i);
    }
    SetModel(out_vertices, indices);
}

void FAModel::SetFAModel(std::string path) {
	std::ifstream file (path);
	if (file.is_open()) {
		
		std::vector<glm::vec3> vertexArray;
		std::vector<float> normalArray;
		std::vector<GLfloat> vertices;
		std::vector<GLushort> indices;
		while (!file.eof()) {
			std::string f;
			int count;
			file >> f;
			if (f == "v") {
				file >> count;
				std::cout << count << " number of vertices" << std::endl;
				vertexArray = std::vector<glm::vec3>();
				for (int i = 0; i < count; i++) {
					glm::vec3 vec;
					file >> vec.x >> vec.y >> vec.z;
					vertexArray.push_back(vec);
				}
			} else if (f == "n") {
				file >> count;
				std::cout << count << " number of normals" << std::endl;
				normalArray = std::vector<float> ();
				for (int i = 0; i < count; i++) {
					float v1, v2, v3;
					file >> v1 >> v2 >> v3;
					std::cout << v1 << std::endl;
					std::cout << v2 << std::endl;
					std::cout << v3 << std::endl;
					normalArray.push_back(v1);
					normalArray.push_back(v2);
					normalArray.push_back(v3);
				}
			} else if (f == "i") {
				file >> count;
				std::cout << count << " number of indices" << std::endl;
				indices = std::vector<GLushort> ();
				vertices = std::vector<GLfloat> ();
				for (int i = 0; i < count * 3; i++) {
					indices.push_back(i);
				}
				for (int i = 0; i < count; i++) {
					float v1, v2, v3, n;
					file >> v1;
					std::cout << v1 << std::endl;
					file >> v2;
					std::cout << v2 << std::endl;
					file >> v3;
					std::cout << v3 << std::endl;
					file >> n;
					std::cout << n << std::endl;
					
					vertices.push_back(vertexArray[v1].x);
					vertices.push_back(vertexArray[v1].y);
					vertices.push_back(vertexArray[v1].z);
					vertices.push_back(normalArray[n * 3]);
					vertices.push_back(normalArray[n * 3 + 1]);
					vertices.push_back(normalArray[n * 3 + 2]);
					
					vertices.push_back(vertexArray[v2].x);
					vertices.push_back(vertexArray[v2].y);
					vertices.push_back(vertexArray[v2].z);
					vertices.push_back(normalArray[n * 3]);
					vertices.push_back(normalArray[n * 3 + 1]);
					vertices.push_back(normalArray[n * 3 + 2]);
					
					vertices.push_back(vertexArray[v3].x);
					vertices.push_back(vertexArray[v3].y);
					vertices.push_back(vertexArray[v3].z);
					vertices.push_back(normalArray[n * 3]);
					vertices.push_back(normalArray[n * 3 + 1]);
					vertices.push_back(normalArray[n * 3 + 2]);
				}
			} else {
				std::cout << "Unknown character! asuming it's a comment: \"" << f << "\"" << std::endl;
			}
		}
		SetModel(vertices, indices);
	}
}

void FAModel::setColor(glm::vec4 c) {
    color = c;
}

void FAModel::onRender(FACamera *camera) {
	
	glBindVertexArray(myVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
	
	glUseProgram(shader->shaderProgram);
	
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniform4f(colorUniformLoc, color.x, color.y, color.z, color.w);
	
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	glUseProgram(0);
	
}

void FAModel::onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix) {
    
	glBindVertexArray(myVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
	glUseProgram(shader->shaderProgram);
	glUniform1i(shadowMapLocation, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D_ARRAY, texture);
	
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniform4f(colorUniformLoc, color.x, color.y, color.z, color.w);
	glUniformMatrix4fv(textureMatrixLocation, (GLsizei) textureMatrix.size(), GL_FALSE, &textureMatrix[0][0][0]);
    
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

void FAModel::onRenderShadow(glm::mat4 c) {
    
	glBindVertexArray(myShadowVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
	
	glUseProgram(shadowShader.shaderProgram);
	
    glUniformMatrix4fv(shadowModelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(viewProjectionMatrixLocation, 1, GL_FALSE, &c[0][0]);
	
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

void FAModel::onUpdate(float dt) {
	
}