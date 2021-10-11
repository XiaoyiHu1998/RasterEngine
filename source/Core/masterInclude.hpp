#ifndef MASTERINCLUDE_HPP
#define MASTERINCLUDE_HPP

#define NOMINMAX
#include <windows.h>
#undef NOMINMAX

#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"
#include <stdio.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GLM/glm.hpp"
#include "GLM/ext/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"

#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <set>
#include <thread>
#include <vector>

#include "Primitives.hpp"
#include "errorChecking.hpp"

#define WINDOW_RES_X 1366
#define WINDOW_RES_Y 768
#define WINDOW_PIXEL_COUNT WINDOW_RES_X * WINDOW_RES_Y

#define THREAD_COUNT std::thread::hardware_concurrency();

#endif //MASTERINCLUDE_HPP