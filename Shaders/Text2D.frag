#version 150 core

in vec2 pass_texCoord;
uniform vec4 color;

out vec4 outpu;

uniform sampler2D text;

void main(void) {
    outpu = color * texture(text, pass_texCoord).r;
//    outpu = vec4(1,1,1,1);
}