//
//  FATexture.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 11/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FATexture.h"

GLuint FATexture::createTexture(const GLchar *path) {
    
    ILuint image = ilGenImage();
    ilBindImage(image);
    ILboolean loadSucsess = ilLoadImage(path);
    if (!loadSucsess) {
        ilBindImage(0);
        std::cout << "File not found: '" << path << "'" << std::endl;
        ilDeleteImage(image);
        return 0;
    }
    
    ILboolean convertSuccess = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    if (!convertSuccess) {
        ilBindImage(0);
        std::cout << "Failed to conver image: '" << path << "'" << std::endl;
        ilDeleteImage(image);
        return 0;
    }
    
    GLuint texture;
    glGenTextures(1, &texture);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
    glBindTexture(GL_TEXTURE_2D, 0);
    
    ilBindImage(0);
    ilDeleteImage(image);
    return texture;
}

GLuint FATexture::createBMPTexture(const GLchar *path) {
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;
    
    std::ifstream file(path);
    
    if(!file.is_open()) {
        std::cout << "Could not open file: " << path << std::endl;
    }
    char c;
    for (int i = 0; i < 54; i++) {
        file.get(c);
        header[i] = c;
    }
    if (header[0] != 'B' || header[1] != 'M') {
        std::cout << "Incorrect or corrupt bmp file" << std::endl;
    }
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);
	if (imageSize==0) {
        imageSize=width*height*3;
    }
    if (dataPos==0) {
        dataPos=54;
    }
    data = new unsigned char [imageSize];
    
    for (int i = 0; i < imageSize; i++) {
        file.get(c);
        data[i] = c; 
//		std::cout << "," << (int)c;
    }
    file.close();
    
    GLuint texture;
    glGenTextures(1, &texture);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    return texture;
}