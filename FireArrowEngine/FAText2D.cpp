//
//  FAText2D.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 07/04/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAText2D.h"

FAText2D::FAText2D(FAFont *_font) {
    glGenBuffers(1, &myVBO);
    glGenBuffers(1, &myEBO);
    glGenVertexArrays(1, &myVAO);
    std::vector<GLushort> indices = {
        0, 2, 1,
        0, 3, 2,
    };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    font = _font;
    this->setName("2D Text");
    this->position = glm::vec3(0,0,0);
}

FAText2D::FAText2D() {
    this->setName("2D Text");
}

FAText2D::~FAText2D() {
}

void FAText2D::setShader(FAShader *shader) {
    FAText2D::shader = shader;
    
    glUseProgram(shader->shaderProgram);
    
    texture_attribute = glGetAttribLocation(shader->shaderProgram, "in_texCoord");
    position_attribute = glGetAttribLocation(shader->shaderProgram, "in_position");
    uniform_tex = glGetUniformLocation(shader->shaderProgram, "text");
    if(texture_attribute == -1) {
        std::cout << "error textureattrib" << std::endl;
    }
    
    if(position_attribute == -1) {
        std::cout << "error position_attribute" << std::endl;
    }
    
    if(uniform_tex == -1) {
        std::cout << "error uniform_tex" << std::endl;
    }
    
    glUseProgram(0);
}

void FAText2D::setText(std::string _text) {
    text = _text;
}

std::string FAText2D::getText() {
	return text;
}

void FAText2D::renderCharacter(int character, float x, float y, float width, float heigth) {
    
    //TODO some optimizing where I don't send new vertices for each character.
    
    float x1 = -1 + x/font->windowWidth + this->position.x + 1;
    float x2 = x1 + width/font->windowWidth;
    float y1 = -1 - y/font->windowHeight + this->position.y + 1;
    float y2 = -1  - y/font->windowHeight - heigth/font->windowHeight + this->position.y + 1;
    
//    std::cout << "x1: " << x1 << "x2: " << x2 << "y1: " << y1 << "y2: " << y2 << std::endl;
    
    std::vector<GLfloat> vertices = {
        x1, y1, 0, 0,
        x2, y1, 1, 0,
        x2, y2, 1, 1,
        x1, y2, 0, 1,
    };
    
    if (shader->shaderProgram == 0) {
        std::cout << "No valid shader for font" << std::endl;
        return;
    }
	
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(myVAO);
    
    glEnableVertexAttribArray(position_attribute);
    glEnableVertexAttribArray(texture_attribute);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glVertexAttribPointer(position_attribute, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
    glVertexAttribPointer(texture_attribute, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) (2 * sizeof(GLfloat)));
	
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindVertexArray(myVAO);
    glEnableVertexAttribArray(position_attribute);
    glEnableVertexAttribArray(texture_attribute);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, font->texture[character]);
    
    glUseProgram(shader->shaderProgram);
    glUniform1i(uniform_tex, 0);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(position_attribute);
    glDisableVertexAttribArray(texture_attribute);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glUseProgram(0);
	
}

void FAText2D::onRender(FACamera *camera) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    int pen_x = 0, pen_y = 0;
    FT_GlyphSlot slot = font->face->glyph;
    for (int i = 0; i < text.length(); i++ )
    {
        FT_UInt  glyph_index;
        glyph_index = FT_Get_Char_Index( font->face, text[i] );
        int error = FT_Load_Glyph( font->face, glyph_index, FT_LOAD_DEFAULT );
        if ( error )
            continue;
        error = FT_Render_Glyph( slot, FT_RENDER_MODE_NORMAL );
        if ( error )
            continue;
        
        renderCharacter(text[i], pen_x + slot->bitmap_left, pen_y - slot->bitmap_top, slot->bitmap.width, slot->bitmap.rows);
        pen_x += slot->advance.x >> 6;
        pen_y += slot->advance.y >> 6;
    }
    
}

void FAText2D::onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix) {
	onRender(camera);
}

float FAText2D::getFontSize() {
	return font->getFontSize();
}

void FAText2D::onUpdate(float dt) {
	
}