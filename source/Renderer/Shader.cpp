#include "Shader.hpp"

Shader::Shader(const char* fragmentShader, const char* vertexShader = "Shaders/defaultVertexShader.txt"){
    //glCreateProgram(&programID);
}

Shader::~Shader(){
    //glDeleteProgram(&programID);
}

Shader::useProgram(){
    // glUseProgram(programID);
}
