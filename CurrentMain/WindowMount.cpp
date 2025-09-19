#include "WindowHeader.h"

WindowMount::WindowMount(int32_t width, int32_t height, const char* title) {
	win = window_create(width, height, title);
}

WindowMount::~WindowMount() {
	if (win) {
		if (win->handle) {
			glfwDestroyWindow(win->handle);
		}
		free(win);
	}
	glfwTerminate();
}

Window* WindowMount::window_create(int32_t x, int32_t y, const char* title) {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW\n";
		return nullptr;
	}

	GLFWwindow* handle = glfwCreateWindow(x, y, title, nullptr, nullptr);
	if (!handle) {
		std::cerr << "Failed to create GLFW window\n";
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(handle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		glfwDestroyWindow(handle);
		glfwTerminate();
		return nullptr;
	}

	Window* win = (Window*)malloc(sizeof(Window));
	if (!win) {
		std::cerr << "Failed to allocate memory for Window struct\n";
		glfwDestroyWindow(handle);
		glfwTerminate();
		return nullptr;
	}

	win->handle = handle;
	win->position_x = 0;
	win->position_y = 0;
	win->size_x = x;
	win->size_y = y;

	return win;
}
