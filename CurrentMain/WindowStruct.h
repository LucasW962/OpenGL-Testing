#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdint>

struct Window {
	GLFWwindow* handle;
	int32_t position_x;
	int32_t position_y;
	int32_t size_x;
	int32_t size_y;
};
