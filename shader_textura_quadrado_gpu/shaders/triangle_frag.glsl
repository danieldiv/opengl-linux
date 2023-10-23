#version 330 core

uniform sampler2D TextureSampler;

in vec3 Color;
in vec2 UV;

// Declarando uma variavel de saida do tipo vec4
out vec4 OutColor;

void main(){
	vec3 TextureColor = texture(TextureSampler, UV).rgb;
	// 1 - Definindo uma cor fixa
	//OutColor = vec4(Color, 1.0);


	// 2 - para a imagem
	// OutColor = vec4(TextureColor, 1.0);

	// Definindo cor via UV
	// OutColor = vec4(UV, 0.0, 1.0);

	// 3 -> interpola as duas
	// vec3 FinalColor = Color * TextureColor;
	// OutColor = vec4(FinalColor, 1.0);

	// 3 -> negativo
	vec3 FinalColor = 1 - Color * TextureColor;
	OutColor = vec4(FinalColor, 1.0);
}