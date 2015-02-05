#version 150 core

in vec2 in_Position;
in vec2 in_TextureCoord;

out vec2 pass_TextureCoord;

uniform mat4x4 modelMatrix;

void main(void) {
    pass_TextureCoord = in_TextureCoord;
    gl_Position = modelMatrix * vec4(in_Position, 0, 1);
}