#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <iostream>

int main(){
    GLFWwindow* window;

    if(!glfwInit()){
        return -1;
    }

    window = glfwCreateWindow(640, 480, "RasterEngine.exe", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // if(glewInit() != GLEW_OK){
    //     return -1;
    // }
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    while(!glfwWindowShouldClose(window)){
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);
    
        glBegin(GL_TRIANGLES);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glEnd();


        //swap buffers
        glfwSwapBuffers(window);

        //event check and handling
        glfwPollEvents();
    }
}