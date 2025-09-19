#pragma once
#include "WindowStruct.h"
#include <iostream>

class WindowMount {
public:
	WindowMount(int32_t width, int32_t height, const char* title);
	~WindowMount();

	Window* GetWindow() const { return win; }

private:
	Window* window_create(int32_t x, int32_t y, const char* title);
	Window* win;
};
