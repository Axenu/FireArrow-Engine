#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat4 normalMatrix;

in vec3 in_Position;
in vec3 in_Normal;

out vec3 pass_Normal;
out vec4 pass_Position;

void main() {
    pass_Normal = (modelMatrix * vec4(in_Normal, 0.0)).xyz;
    pass_Position = modelMatrix * vec4(in_Position, 1.0);
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
    
    
    //	mat4 normalmatrix = transpose(inverse(modelMatrix));
    //	pass_Normal = (normalmatrix * vec4(in_Normal, 0.0)).xyz;
}