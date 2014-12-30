#version 150 core

out vec4 outpu;

in vec2 pass_TextureCoord;

uniform sampler2DArray text;
uniform int layer;

void main(void) {
    outpu = vec4(texture(text, vec3(pass_TextureCoord,layer)).r, texture(text, vec3(pass_TextureCoord,layer)).r, texture(text, vec3(pass_TextureCoord,layer)).r, 1.0);
}