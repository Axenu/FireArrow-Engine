//
//  FAShader.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 10/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAShader.h"

FAShader::FAShader(const GLchar *vertPath, const GLchar *fragPath) {

    
    vertShader = createShader(vertPath, GL_VERTEX_SHADER);
    fragShader = createShader(fragPath, GL_FRAGMENT_SHADER);
	
	std::string s = vertPath;
	if (s.length() > 5) {
		s.erase(s.end() - 5, s.end());
		name = s;
	}
	
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    
    glBindFragDataLocation(shaderProgram, 0, "frag_Data");
    
    glLinkProgram(shaderProgram);
    
    GLint linkStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        std::cout << "Shader program failed to link!" << std::endl;
        
        GLint infoLogLength;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar *infoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
    }
}

FAShader::FAShader(const GLchar *vertPath, const GLchar *geomPath, const GLchar *fragPath) {
    vertShader = createShader(vertPath, GL_VERTEX_SHADER);
    geomShader = createShader(geomPath, GL_GEOMETRY_SHADER);
    fragShader = createShader(fragPath, GL_FRAGMENT_SHADER);
    
    std::string s = vertPath;
    if (s.length() > 5) {
        s.erase(s.end() - 5, s.end());
        name = s;
    }
    
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, geomShader);
    glAttachShader(shaderProgram, fragShader);
    
    glBindFragDataLocation(shaderProgram, 0, "frag_Data");
    
    glLinkProgram(shaderProgram);
    
    GLint linkStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        std::cout << "Shader program failed to link!" << std::endl;
        
        GLint infoLogLength;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar *infoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
}

FAShader::FAShader(std::string path) {
	
	
	vertShader = createShader((path + ".vert").c_str(), GL_VERTEX_SHADER);
	fragShader = createShader((path + ".frag").c_str(), GL_FRAGMENT_SHADER);
	
	name = path;
	
	shaderProgram = glCreateProgram();
	
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	
	glBindFragDataLocation(shaderProgram, 0, "frag_Data");
	
	glLinkProgram(shaderProgram);
	
	GLint linkStatus;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE) {
		std::cout << "Shader program failed to link!" << std::endl;
		
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *infoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
		std::cout << infoLog << std::endl;
		delete[] infoLog;
	}
}

FAShader::FAShader() {
    shaderProgram = 0;
}

void FAShader::setupLocations() {
    positionLocation = glGetAttribLocation(shaderProgram, "position");
    normalLocation = glGetAttribLocation(shaderProgram, "normal");
    uvLocation = glGetAttribLocation(shaderProgram, "uv");
    colorLocation = glGetAttribLocation(shaderProgram, "color");
    
    // Get matrices uniform locations
//    colorUniformLoc = glGetUniformLocation(shader.shaderProgram, "color");
//    projectionMatrixLocation = glGetUniformLocation(shader.shaderProgram,"projectionMatrix");
//    viewMatrixLocation = glGetUniformLocation(shader.shaderProgram, "viewMatrix");
//    modelMatrixLocation = glGetUniformLocation(shader.shaderProgram, "modelMatrix");
//    textureMatrixLocation = glGetUniformLocation(shader.shaderProgram, "textureMatrix");
//    shadowMapLocation = glGetUniformLocation(shader.shaderProgram, "shadowMap");
}

GLuint FAShader::createShader(const GLchar *path, GLenum shaderType) {
    
    std::fstream fin;
    GLuint shaderID = glCreateShader(shaderType);
    
    // Vertex Shader
    fin.open(path);
    if(!fin.is_open()) {
        fin.close();
        std::cout << "File not found: '" << path << "'" << std::endl;
        return 0;
    }
    
    std::string source((std::istreambuf_iterator<GLchar>(fin)), std::istreambuf_iterator<GLchar>());
    fin.close();
    
    const GLchar *shaderSource = source.c_str();
    glShaderSource(shaderID, 1, &shaderSource, NULL);
    
    glCompileShader(shaderID);
    
    GLint compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE) {
        std::cout << "Shader failed to compile: '" << path << "'" << std::endl;
        
        GLint infoLogLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar *infoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
        return 0;
    }
    
    return shaderID;
}

std::string FAShader::getName() {
    return name;
}

void FAShader::deleteShader() {
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    glDeleteProgram(shaderProgram);
}