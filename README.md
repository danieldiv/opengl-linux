# opengl-linux

Instalação e exemplo de uso do OpenGL no linux Ubuntu

## Instalação

```
sudo apt update

// bibliotecas para compilacao do gcc
sudo apt install build-essential

// instalacao das bibliotecas do OpenGL
sudo apt install mesa-common-dev

// instalacao do glew e o glfw
sudo apt install libglew-dev
sudo apt install libglfw3-dev

// execução
g++ -o main main.cpp -lGL -lGLEW -lglfw
```
