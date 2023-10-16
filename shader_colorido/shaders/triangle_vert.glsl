#version 330 core

// Declarando uma vari�vel de entrada do tipo vec3
layout (location = 0) in vec3 InPosition;
layout (location = 1) in vec3 InColor;

out vec3 Color;

void main(){

	Color = InColor;
	gl_Position = vec4(InPosition, 1.0);

}