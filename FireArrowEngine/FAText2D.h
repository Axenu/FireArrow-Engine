//
//  FAText2D.h
//  FireArrow
//
//  Created by Simon Nilsson on 07/04/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAText2D__
#define __FireArrow__FAText2D__

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "FASpatial.h"
#include "FAShader.h"
#include "FANode.h"
#include "FAFont.h"
#include "FAHUDElement.h"

class FAText2D : public FAHUDElement {
private:
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
    FAShader *shader;
    FAFont *font;
    std::string text;
    GLint texture_attribute;
    GLint position_attribute;
    GLint colorUnifrom;
    GLint uniform_tex;
    GLuint tex;
    GLuint vbo;
    
    glm::vec4 color;
    
    void renderCharacter(int character, float x, float y, float width, float heigth);
    
public:
    
    FAText2D();
    FAText2D(FAFont *_font);
    ~FAText2D();
    void setShader(FAShader *shader);
    void setText(std::string _text);
    void setColor(glm::vec4 color);
	std::string getText();
    void my_draw_bitmap(FT_Bitmap *bitmap, float x, float y);
	float getFontSize();
    
protected:
	virtual void onRender(FACamera *camera);
	virtual void onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix);
    virtual void onUpdate(float dt);
    
};

#endif /* defined(__FireArrow__FAText2D__) */
