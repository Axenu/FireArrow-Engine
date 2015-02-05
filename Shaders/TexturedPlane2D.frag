#version 150 core

out vec4 outpu;

in vec2 pass_TextureCoord;

uniform sampler2D text;
uniform int layer;

void main(void) {
    outpu = vec4(texture(text, pass_TextureCoord).rgb, 1.0);
}