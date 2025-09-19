#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class InternalInputs {
public:
    InternalInputs(GLFWwindow* handle);

    void ProcessInput();
private:
    GLFWwindow* handle;
};
