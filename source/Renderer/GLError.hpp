#ifndef GL_ERROR_HPP
#define GL_ERROR_HPP

#include "masterInclude.hpp"

void GLClearError(){
    while(glGetError() != GL_NO_ERROR){
        glGetError();
    }
}



#ifdef DEBUG
    #define GLCall(X) GLClearError(); x; ASSERT(GLLogCall()) 
#else
    #define GLCall(x) x
#endif // DEBUG

#endif //GL_ERROR_HPP