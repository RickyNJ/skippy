#include <iostream>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

const int MATRIX_SIZE = 40;

void setupMatrix(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO, int matrix[MATRIX_SIZE][MATRIX_SIZE]){
    // 8 coordinates, 1 colour value
    float vertices[MATRIX_SIZE * MATRIX_SIZE * 9];
    // TODO: figure out coordinates + implement variable gap size for convinience
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            vertices[(i*MATRIX_SIZE + j)] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 1] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 2] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 3] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 4] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 5] = 1.0f;
            vertices[(i*MATRIX_SIZE + j) + 6] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 7] = 0.0f;
            vertices[(i*MATRIX_SIZE + j) + 8] = static_cast<float>(matrix[i][j]);
        }
    }

}


int main() {
    // init GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Skippy", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i*j;
        }
    }

    unsigned int VAO, VBO, EBO;
    setupMatrix(VAO, VBO, EBO, matrix);


    return 0;
}
