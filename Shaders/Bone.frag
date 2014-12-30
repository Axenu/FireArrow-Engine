#version 330 core

out vec4 outpu;

in vec4 pass_Normal;
in vec3 pass_Color;

void main()
{
	float cosine = dot(pass_Normal, normalize(vec4(0,1,0,0)));
	float factor = max(cosine, 0);
	vec3 color = (pass_Color + vec3(0.2,0.2,0.2)) * factor;
	outpu = vec4(color, 1.0);
}