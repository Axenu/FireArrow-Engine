#version 400 core

uniform vec4 color;
uniform sampler2DArray shadowMap;
uniform mat4 textureMatrix[4];

in vec3 pass_Normal;
in vec4 pass_Position;


layout(location = 0) out vec4 frag_data;
layout(location = 1) out vec4 out_Normal;
layout(location = 2) out vec4 out_Position;

void main() {
    //shadow
    
    int index = 0;
    if (gl_FragCoord.z/gl_FragCoord.w < 2) {
        index = 0;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 5) {
        index = 1;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 20) {
        index = 2;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 100) {
        index = 3;
    } else {
        index = -1;
    }
    
    float shadow = 1.0;
    
    if (index != -1) {
        vec4 shadowCoordinateWdivide = (textureMatrix[index] * pass_Position) / pass_Position.w ;

        float dist = texture(shadowMap,vec3(shadowCoordinateWdivide.st, index)).r;
            if (dist > 0) {
                if (pass_Position.w > 0.0) {
                    if (dist - 0.00001 < shadowCoordinateWdivide.z)
                        shadow =  0.0;
                }
            }
    }
    
    //diffuse
    float ambientComponent = 0.5;
    const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
    
    vec3 normal = normalize(pass_Normal);
    vec3 lightDir = normalize(-vec3(1,-1,1));
    
    float lambertian = dot(lightDir,normal);
    
    if (lambertian < 0) {
        lambertian = 0;
    }
    
    frag_data = color * ambientComponent + color * shadow * lambertian;
    frag_data.a = 1.0;
    
    out_Normal = vec4(pass_Normal, 1);
    out_Position = pass_Position;
    
}