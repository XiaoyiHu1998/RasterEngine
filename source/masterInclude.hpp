#ifndef MASTERINCLUDE_HPP
#define MASTERINCLUDE_HPP

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

#define WINDOW_RES_X 960
#define WINDOW_RES_Y 540
#define WINDOW_PIXEL_COUNT WINDOW_RES_X * WINDOW_RES_Y

#define THREAD_COUNT std::thread::hardware_concurrency();

#endif //MASTERINCLUDE_HPP