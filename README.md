# opengl-linux

![C++](https://img.shields.io/badge/Linguagem-C++-green.svg)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![VSCode](https://img.shields.io/badge/IDE-VSCode-informational)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)
![License](https://badgen.net/badge/license/MIT/green)

Instalação e exemplo de uso do OpenGL no linux Ubuntu

## Instalação

```C++
sudo apt update

// bibliotecas para compilacao do gcc
sudo apt install build-essential

// instalacao das bibliotecas do OpenGL
sudo apt install mesa-common-dev

// instalacao do glew, glfw e glm
sudo apt install libglew-dev
sudo apt install libglfw3-dev
sudo apt install libglm-dev

// compilacao para unico arquivo
g++ -o main main.cpp -lGL -lGLEW -lglfw
```

## Compilação e execução

| Comando      | Função                                                                                  |
| ------------ | --------------------------------------------------------------------------------------- |
| `make clean` | Apaga a última compilação realizada contida na pasta build                              |
| `make`       | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build |
| `make run`   | Executa o programa da pasta build após a realização da compilação                       |
