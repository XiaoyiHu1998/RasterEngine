#include "Shader.hpp"

Shader::Shader(const char* fragmentShader, const char* vertexShader){
    //get shadercode in const char* format
    std::string fragShader;
    std::string vertShader;
    std::ifstream file;
    // std::cout << "fragmentShader: " << fragmentShader << std::endl;
    // std::cout << "vertexShader: " << vertexShader << std::endl;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        std::stringstream fragShaderStream;
        std::stringstream vertShaderStream;

        file.open(fragmentShader);
        fragShaderStream << file.rdbuf();
        fragShader = fragShaderStream.str();
        file.close();
        
        file.open(vertexShader);
        vertShaderStream << file.rdbuf();
        file.close();
        vertShader = vertShaderStream.str();
    }
    catch(std::ifstream::failure error){
        std::cout << "ERROR: Failed to load shader files." << std::endl;
    }
    // std::cout << "fragmentShaderContent: " << fragShader << std::endl;
    // std::cout << "vertexShaderContent: " << vertShader << std::endl;
    const char* fragShaderCode = fragShader.c_str();
    const char* vertShaderCode = vertShader.c_str();
    
    //create shaders
    int shaderSuccess;
    char log[512];

    //fragmentShader
    uint32_t fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    GLCall(glShaderSource(fragShaderID, 1, &fragShaderCode, NULL));
    GLCall(glCompileShader(fragShaderID));
    GLCall(glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &shaderSuccess));
    if(!shaderSuccess){
        GLCall(glGetShaderInfoLog(fragShaderID, 512, NULL, log));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE_ERROR" << log << std::endl;
    }
    
    //vertexShader
    uint32_t vertShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLCall(glShaderSource(vertShaderID, 1, &vertShaderCode, NULL));
    GLCall(glCompileShader(vertShaderID));
    GLCall(glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &shaderSuccess));
    if(!shaderSuccess){
        GLCall(glGetShaderInfoLog(vertShaderID, 512, NULL, log));
        std::cout << "ERROR::SHADER::VERTEX::COMPILE_ERROR" << log << std::endl;
    }

    //shaderProgram
    uint32_t shaderProgramID = glCreateProgram();
    GLCall(glAttachShader(shaderProgramID, fragShaderID));
    GLCall(glAttachShader(shaderProgramID, vertShaderID));
    GLCall(glLinkProgram(shaderProgramID));
    GLCall(glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &shaderSuccess));
    if(!shaderSuccess){
        GLCall(glGetProgramInfoLog(shaderProgramID, 512, NULL, log));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE_ERROR" << log << std::endl;
    }
    
    GLCall(glDeleteShader(fragShaderID));
    GLCall(glDeleteShader(vertShaderID));
    
    shaderID = shaderProgramID;
    //glCreateProgram(&programID);
}

Shader::~Shader(){
    GLCall(glDeleteProgram(shaderID));
}

void Shader::bind(){
    GLCall(glUseProgram(shaderID));
}

void Shader::unbind(){
    GLCall(glUseProgram(0));
}

void Shader::setInt(const std::string& uniformName, int value){
    GLCall(glUniform1i(glGetUniformLocation(shaderID, uniformName.c_str()), value));
}

void Shader::setBool(const std::string& uniformName, bool value){
    GLCall(glUniform1i(glGetUniformLocation(shaderID, uniformName.c_str()), (int)value));
}

void Shader::setFloat(const std::string& uniformName, float value){
    GLCall(glUniform1f(glGetUniformLocation(shaderID, uniformName.c_str()), value));
}

void Shader::setUniform4f(const std::string& uniformName, float x, float y, float z, float w){
    GLCall(glUniform4f(glGetUniformLocation(shaderID, uniformName.c_str()), x, y, z, w));
}