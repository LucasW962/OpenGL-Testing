#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowHeader.h"
#include "InternalInputs.h"

int main() {
    WindowMount mount(800, 600, "Yoda Window");

    Window* win = mount.GetWindow();
    if (!win || !win->handle) {
        std::cerr << "Window creation failed\n";
        return -1;
    }

    InternalInputs inputs(win->handle);

    while (!glfwWindowShouldClose(win->handle)) {
        inputs.ProcessInput();


        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win->handle);
        glfwPollEvents();
    }

    return 0;
}
