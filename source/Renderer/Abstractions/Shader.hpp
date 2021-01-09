#ifndef SHADER_HPP
#define SHADER_HPP

#include "masterinclude.hpp"
#include <fstream>
#include <sstream>

class Shader{
private:
    uint32_t shaderID;
public:
    Shader(const char* fragmentShader = "D:\\Git_repos\\RasterEngine\\source\\Renderer\\Abstractions\\defaultFragmentShader.txt", const char* vertexShader = "D:\\Git_repos\\RasterEngine\\source\\Renderer\\Abstractions\\defaultVertexShader.txt");
    // Shader(const char* fragmentShader = "../../assets/Shaders/defaultFragmentShader.txt", const char* vertexShader = "../../assets/Shaders/defaultVertexShader.txt");
    ~Shader();
    void useProgram();
    void setBool(const std::string& uniformName, bool value);
    void setInt(const std::string& uniformName, int value);
    void setFloat(const std::string& uniformName, float value);
    void bindUniforms();
};

#endif //SHADER_HPP