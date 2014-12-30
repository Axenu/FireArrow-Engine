#version 150 core

in vec2 pass_texCoord;

out vec4 outpu;

uniform sampler2D text;

void main(void) {
    outpu = vec4(0, 0, 0, texture(text, pass_texCoord).r);
//    outpu = vec4(1,1,1,1);
}