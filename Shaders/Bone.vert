#version 330 core

in vec3 in_Position;
in vec3 in_Normal;
in vec2 in_Index;
in vec2 in_Weight;
in vec3 in_Color;

out vec4 pass_Normal;
out vec3 pass_Color;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

uniform mat4 bones[36];

void main() {
	
	int index = int(in_Index.x);
	
	vec4 newVertex = (bones[index] * in_Weight.x) * vec4(in_Position, 1.0);
	pass_Normal = (bones[index] * in_Weight.x) * vec4(in_Normal, 0.0);
	
	index = int(in_Index.y);
	
	newVertex = (bones[index] * in_Weight.y) * vec4(in_Position, 1.0) + newVertex;
	pass_Normal = (bones[index] * in_Weight.y) * vec4(in_Normal, 0.0) + pass_Normal;
	
	pass_Normal = normalize(pass_Normal);
	pass_Color = in_Color;
	
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * newVertex;
}