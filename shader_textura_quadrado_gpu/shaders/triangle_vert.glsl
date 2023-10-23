#version 330 core

// Declarando uma vari�vel de entrada do tipo vec3
layout (location = 0) in vec3 InPosition;
layout (location = 1) in vec3 InColor;
layout (location = 2) in vec2 InUV;

uniform mat4 ModelViewProjection;

out vec3 Color;
out vec2 UV;

void main(){

	Color = InColor;
	UV = InUV;
	gl_Position = ModelViewProjection * vec4(InPosition, 1.0);
}