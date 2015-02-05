#version 400 core

in vec2 in_Position;
in vec2 in_UV;

out vec2 pass_UV;

void main() {
    pass_UV = in_UV;
    gl_Position = vec4(in_Position, 0, 1);
}