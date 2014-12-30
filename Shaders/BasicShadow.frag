#version 400 core

uniform vec4 color;
uniform sampler2DArray shadowMap;
uniform mat4 modelMatrix;
uniform mat4 textureMatrix[4];
uniform mat4 viewMatrix;

in vec3 pass_Normal;
in vec3 pass_position;
in vec4 pass_shadowCoordinate;

out vec4 frag_data;

void main() {
    //shadow
    
    int index = 0;
    if (gl_FragCoord.z/gl_FragCoord.w < 10) {
        index = 0;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 20) {
        index = 1;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 40) {
        index = 2;
    } else if (gl_FragCoord.z/gl_FragCoord.w < 100) {
        index = 3;
    } else {
        index = -1;
    }
    
    float shadow = 1.0;
    if (index != -1) {
        vec4 shadowCoordinateWdivide = (textureMatrix[index] * pass_shadowCoordinate) / pass_shadowCoordinate.w ;
        
        float distanceFromLight = texture(shadowMap,vec3(shadowCoordinateWdivide.st, index)).r;
        
        if (distanceFromLight > 0) {
            if (pass_shadowCoordinate.w > 0.0) {
                if (distanceFromLight - 0.000001 < shadowCoordinateWdivide.z)
                    shadow =  0.5;
            }
        }
    }
    
    frag_data = vec4(color * shadow);
    frag_data.w = 1.0;
    
    //    if (gl_FragCoord.z/gl_FragCoord.w < 10) {
    //        frag_data = vec4(1,0,0,1);
    //    } else if (gl_FragCoord.z/gl_FragCoord.w < 30) {
    //        frag_data = vec4(0,1,0,1);
    //    } else if (gl_FragCoord.z/gl_FragCoord.w < 60) {
    //        frag_data = vec4(0,0,1,1);
    //    } else {
    //        frag_data = vec4(1,1,0,1);
    //    }
    
}