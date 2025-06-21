#include <iostream>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(680, 480, "Logger", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_callback);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();


    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}