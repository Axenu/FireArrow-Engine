#version 150 core

in vec2 in_position;

uniform vec4 color;
uniform mat4x4 modelMatrix;

void main(void) {
	gl_Position = modelMatrix * vec4(in_position, 0, 1);
}