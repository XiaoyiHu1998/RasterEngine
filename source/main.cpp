#include <iostream>
// #include "..\dependencies\include\GLFW\glfw3.h"
#include "glfw3.h"

int main(){
    GLFWwindow* windowPointer;

    if(!glfwInit()){
        return -1;
    }

    windowPointer = glfwCreateWindow(640, 480, "RasterEngine.exe", NULL, NULL);
    if(!windowPointer){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(windowPointer);
    while(!glfwWindowShouldClose(windowPointer)){
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);
        //swap buffers
        glfwSwapBuffers(windowPointer);
        //event check and handling
        glfwPollEvents();
    }
}