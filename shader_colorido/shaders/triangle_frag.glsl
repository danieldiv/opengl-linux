#version 330 core

in vec3 Color;
// Declarando uma vari�vel de sa�da do tipo vec4
out vec4 OutColor;

void main(){

	OutColor = vec4(Color, 1.0);

}