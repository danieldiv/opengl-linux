#include <iostream>
//Biblioteca do OpenGL
#include <GL/glew.h>
//Biblioteca que irá desenhar a tela
#include <GLFW/glfw3.h>
//Biliotecas de validação
#include <cassert>

//Definindo as dimenções da janela
const int Width = 800;
const int Heigth = 600;

int main() {
	setlocale(LC_ALL, "pt_BR");
	//Inicializando a biblioteca do GLFW
	assert(glfwInit() == GLFW_TRUE);

	//Construindo a janela
	GLFWwindow *window = glfwCreateWindow(Width, Heigth, "CG com OpenGL", nullptr, nullptr);
	//Verificar se a janela é nula
	assert(window);

	//Definindo a janela de contexto
	glfwMakeContextCurrent(window);

	//inicializa o GLEW
	int statusGlwInit = glewInit();
	std::cout << statusGlwInit << std::endl;
	assert(glewInit() == GLEW_OK);

	//Verificar a versão do OpenGL que está sendo usando
	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	std::cout << "Maior versão do OpenGL suportada:" << GLMajorVersion << std::endl;
	std::cout << "Menor versão do OpenGL suportada:" << GLMinorVersion << std::endl;

	//Obtendo informações do driver utilizado
	std::cout << "Fabricante do driver de video:" << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Modelo da placa de video:" << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Versão do OpenGL:" << glGetString(GL_VERSION) << std::endl;
	std::cout << "Versão do GLS:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	//Definir cor de fundo
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	//Construindo o loop de eventos
	while (!glfwWindowShouldClose(window)) {
		// Limpar o Buffer de cor
		glClear(GL_COLOR_BUFFER_BIT);

		//Processa todos os eventos na fila do GLFW
		glfwPollEvents();
		//Envia o conteúdo para desenhar na tela
		glfwSwapBuffers(window);
	}

	//Finaliza a biblioteca GLFW
	glfwTerminate();
	return 0;
}