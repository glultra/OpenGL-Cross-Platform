#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

out vec2 TexCoords;
out vec3 Colors;

void main(){
    TexCoords = aTexCoords;
    Colors = aColor;
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
}