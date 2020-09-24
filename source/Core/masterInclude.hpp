#ifndef MASTERINCLUDE_HPP
#define MASTERINCLUDE_HPP

#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"
#include <stdio.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GLM/glm.hpp"

#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// #include <functional>

#include "Primitives.hpp"

#define DEBUG
#define WINDOW_RES_X 1366
#define WINDOW_RES_Y 768
#define WINDOW_PIXEL_COUNT WINDOW_RES_X * WINDOW_RES_Y

#define THREAD_COUNT std::thread::hardware_concurrency();

static void GLClearError(){
    while(glGetError() != GL_NO_ERROR);     //same as having {} as loop body
}

static bool GLLogCall(const char* function, const char* file, int line){
    if(GLenum glError = glGetError()){     //assigns the errorcode to error and uses it to evaluate loop condition
        std::cout << "[OpenGL Error]" << "(0x" << std::hex << glError << std::dec << ") in " << function << " in file " << file << " on line " << line << std::endl;
        return false;
    }
    return true;
}

#define RE_ASSERT(x) if(!(x)); //exit(-1) should be replaced with a breakstatement

#ifdef DEBUG //GLCall
    #define GLCall(x) GLClearError(); x; RE_ASSERT(GLLogCall(#x, __FILE__, __LINE__)) 
#else
    #define GLCall(x) x
#endif // DEBUG

#endif //MASTERINCLUDE_HPP