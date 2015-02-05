#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;

in vec3 in_Position;
in vec3 in_Normal;

out vec4 pass_Normal;
out vec4 pass_Position;

void main() {
    pass_Position = modelMatrix * vec4(in_Position, 1.0);
    pass_Normal = normalize(modelMatrix * vec4(in_Normal, 0.0));
    gl_Position = projectionMatrix * viewMatrix * pass_Position;
}