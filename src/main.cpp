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
	glClearColor(0.0, 0.15, 0.25, 1.0); // azul
	// glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // vermelho
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // padrao eh preenchido
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // mostra apenas contorno
	glLineWidth(4.0);

	//Construindo o loop de eventos
	while (!glfwWindowShouldClose(window)) {
		// Limpar o Buffer de cor

		//Processa todos os eventos na fila do GLFW
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);

		glClear(GL_COLOR_BUFFER_BIT);

		// 0.0 -> eh o centro da pagina
		// RGB

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.5, -0.5, 0.0); // PA
		glVertex3f(0.5, 0.5, 0.0); // PB
		glVertex3f(0.0, 0.5, 0.0); // PC
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0.0); // PA
		glVertex3f(-0.5, 0.5, 0.0); // PB
		glVertex3f(0.0, 0.5, 0.0); // PC
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0.0); // PA
		glVertex3f(0.5, -0.5, 0.0); // PB
		glVertex3f(0.0, -1, 0.0); // PC
		glEnd();

		glColor3f(1.0, 0.0, 0.0); // vermelho
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glEnd();

		//Envia o conteúdo para desenhar na tela
		glfwSwapBuffers(window);
	}

	//Finaliza a biblioteca GLFW
	glfwTerminate();
	return 0;
}