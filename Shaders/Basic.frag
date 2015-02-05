#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;
uniform vec3 cameraPosition;

in vec4 pass_Normal;
in vec4 pass_Position;

out vec4 frag_data;

void main() {
	float cosine = dot(pass_Normal, normalize(vec4(cameraPosition,0) - pass_Position));
    float factor = max(cosine, 0)/pow(distance(pass_Position, vec4(cameraPosition, 0)), 1) * 2;
    frag_data = vec4(color.r * factor,color.g * factor,color.b * factor,color.a);
//    frag_data = vec4(pass_Normal.xyz, 1);
}