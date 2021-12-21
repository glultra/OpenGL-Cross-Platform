#version 330 core
#define GLSLIFY 1

out vec4 fragColor;

in vec2 TexCoords;
uniform sampler2D myTexture;

void main(){
    fragColor = texture(myTexture, TexCoords);
}