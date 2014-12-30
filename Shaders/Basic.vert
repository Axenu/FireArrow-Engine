#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;

in vec3 in_Position;
in vec3 in_Normal;

out vec4 pass_Normal;

void main() {
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
	pass_Normal = vec4(in_Normal, 1.0);
}