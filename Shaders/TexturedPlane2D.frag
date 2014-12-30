#version 150 core

out vec4 outpu;

in vec2 pass_TextureCoord;

uniform sampler2DArray text;

void main(void) {
    outpu = vec4(texture(text, vec3(pass_TextureCoord,1)).r, texture(text, vec3(pass_TextureCoord,2)).r, texture(text, vec3(pass_TextureCoord,0)).r, 1.0);
}