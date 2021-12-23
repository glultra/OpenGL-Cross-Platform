#version 330 core
#define GLSLIFY 1

out vec4 FragColor;

in vec2 TexCoords;
in vec3 Colors;

uniform sampler2D myTexture;

void main() {
    
    FragColor = texture(myTexture, TexCoords) * vec4(Colors, 1.0f);
}