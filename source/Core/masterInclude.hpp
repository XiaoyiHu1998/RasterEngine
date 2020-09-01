#ifndef MASTERINCLUDE_HPP
#define MASTERINCLUDE_HPP

#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"
#include <stdio.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GLM/glm.hpp"

#define NOMINMAX
#include <windows.h>
#undef NOMINMAX

#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

#include "Primitives.hpp"

#define WINDOW_RES_X 1366
#define WINDOW_RES_Y 768
#define WINDOW_PIXEL_COUNT WINDOW_RES_X * WINDOW_RES_Y

#define THREAD_COUNT std::thread::hardware_concurrency();

#endif //MASTERINCLUDE_HPP