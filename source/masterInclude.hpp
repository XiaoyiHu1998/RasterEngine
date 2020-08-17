#ifndef MASTERINCLUDE_HPP
#define MASTERINCLUDE_HPP

#include <thread>
#include <iostream>
#include <vector>
#include <string>

#define WINDOW_RES_X 640
#define WINDOW_RES_Y 400
#define WINDOW_PIXEL_COUNT WINDOW_RES_X * WINDOW_RES_Y

#define THREAD_COUNT std::thread::hardware_concurrency();

#endif //MASTERINCLUDE_HPP