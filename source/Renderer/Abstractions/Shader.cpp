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
    char shaderLog[512];

    //fragmentShader
    unsigned int fragShaderID = GLCall(glCreateShader(GL_FRAGMENT_SHADER));
    GLCall(glShaderSource(fragShaderID, &fragShaderCode, NULL));
    GLCall(glShaderCompile(fragShaderID));
    GLCall(glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &shaderSuccess));
    if(!shaderSuccess){
        GLCall(glGetShaderInfoLog(fragShaderID, 512, NULL, shaderLog));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE_ERROR" << shaderLog << std::endl;
    }
    
    //vertexShader
    unsigned int vertShaderID = GLCall(glCreateSHader(GL_VERTEX_SHADER));
    GLCall(glShaderSource(vertShaderID, &vertShaderCode, NULL));
    GLCall(glShaderCompile(vertShaderID));
    GLCall(glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &shaderSuccess));
    if(!shaderSuccesss){
        GLCall(glGetShaderInfoLog(vertShaderID, 512, NULL, shaderLog));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE_ERROR" << shaderLog << std::endl;
    }

    //shaderProgram
    unsigned int shaderProgramID = GLCall(glCreateProgram());
    GLCall(glAttachShader(shaderProgramID, fragShaderID));
    GLCall(glAttachShader(shaderProgramID, vertShaderID));
    GLCall(glLinkProgram(shaderProgramID));
    GLCall(glGetShaderiv(shaderProgramID, GL_LINK_STATUS, &shaderSuccess));
    if(!shaderSuccess){
        GLCall(glGetShaderInfoLog(shaderProgramID, 512, NULL, shaderLog));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE_ERROR" << shaderLog << std::endl;
    }
    
    GLCall(glDeleteShader(fragShaderID));
    GLCall(glDeleteShader(vertShaderID));
    
    shaderID = shaderProgramID;
    //glCreateProgram(&programID);
}

void Shader::setBool(const std::string& uniformName, bool value){
    GLCall(glUniform1i(glGetUniformLocation(shaderID, uniformName.c_str()), std::static_cast<int>(value)));
}

void Shader::setInt(const std::string& uniformName, int value){
    GLCall(glUniform1i(glGetUniformLocation(shaderID, uniformName.c_str()), value));
}

void Shader::setFloat(const std::string& uniformName, float value){
    GLCall(glUniform1f(glGetUniformLocation(shaderID, uniformName.c_str()), value));
}

Shader::~Shader(){
    GLCall(glDeleteProgram(shaderID));
}

void Shader::useProgram(){
    GLCall(glUseProgram(shaderID));
}
