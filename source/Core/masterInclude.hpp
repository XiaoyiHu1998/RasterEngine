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

static std::string glErrorString(GLenum error){
    switch(error){
        case GL_NO_ERROR:           return "GL_NO_ERROR";
        case GL_INVALID_ENUM:       return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE:      return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION:  return "GL_INVALID_OPERATION";
        case GL_STACK_OVERFLOW:     return "GL_STACK_OVERFLOW";
        case GL_STACK_UNDERFLOW:    return "GL_STACK_UNDERFLOW";
        case GL_OUT_OF_MEMORY:      return "GL_OUT_OF_MEMORY";
        default:                    return "GL_UNKOWN_ERROR";
    }
}

static std::string getFileName(const char* file){
    std::string path = file;
    return path.substr(path.find_last_of('\\') + 1);
}

static bool GLLogCall(const char* function, const char* path, int line){
    if(GLenum glError = glGetError()){     //assigns the errorcode to error and uses it to evaluate loop condition
        std::cout << "[OpenGL Error] (0x0" << std::hex << glError << std::dec << ": " << glErrorString(glError) << ") -> " << function << ", " << path << ":" << line <<std::endl;
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