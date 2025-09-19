#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "InternalInputs.h"

InternalInputs::InternalInputs(GLFWwindow* handle)
    : handle(handle) {
}

void InternalInputs::ProcessInput() {
    if (glfwGetKey(handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(handle, true);
    }
    if (glfwGetKey(handle, GLFW_KEY_W) == GLFW_PRESS) {
		std::cout << "W key pressed" << std::endl;
    }
}
