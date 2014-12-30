#version 150 core

in vec2 in_position;
in vec2 in_texCoord;

out vec2 pass_texCoord;

uniform sampler2D text;

void main(void) {
    gl_Position = vec4(in_position, -1, 1);
    pass_texCoord = in_texCoord;
}