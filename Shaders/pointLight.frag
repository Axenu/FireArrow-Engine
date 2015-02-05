#version 400 core

in vec2 pass_UV;

uniform sampler2D diffuseTexture;
uniform sampler2D normalTexture;
uniform sampler2D depthTexture;
uniform sampler2D positionTexture;
uniform vec4 lightPosition;
uniform vec4 lightColor;
uniform float lightIntensity;

out vec4 frag_data;

void main() {
    
    vec4 image = texture(diffuseTexture, pass_UV);
    vec4 normal = texture(normalTexture, pass_UV);
    vec4 depth = texture(depthTexture, pass_UV);
    vec4 pass_Position = texture(positionTexture, pass_UV);
    
    vec2 ss = pass_UV* 2 - vec2(1,1);
    
    //diffuse
    float ambientComponent = 0.5;
    const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
    const float ambientFactor = 0.5;
    
    
    normal = normalize(normal);
    vec4 lightDir = normalize(lightPosition - pass_Position);
    
    float lambertian = max(dot(lightDir.xyz,normal.xyz), 0.0);
    
    float distanceToLight = length(lightPosition - pass_Position);
    
    
    
    frag_data = lambertian * lightColor * lightIntensity/(distanceToLight * distanceToLight);
    
}