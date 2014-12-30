#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;

in vec4 pass_Normal;

out vec4 frag_data;

void main() {
	float cosine = dot(pass_Normal, normalize(vec4(1,2,1,0)));
	float factor = max(cosine, 0);
    frag_data = vec4(color.r * factor,color.g * factor,color.b * factor,color.a);
    
}