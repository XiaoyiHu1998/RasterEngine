#ifndef SHADER_HPP
#define SHADER_HPP

#include "masterinclude.hpp"
#include <fstream>
#include <sstream>

class Shader{
private:
    uint32_t shaderID;
public:
// D:\Repositories\RasterEngine\assets\shaders\defaultFragmentShader.txt
    // Shader(const char* fragmentShader = "..\\..\\assets\\shaders\\defaultFragmentShader.txt", const char* vertexShader = "..\\..\\assets\\shaders\\defaultVertexShader.txt");
    Shader(const char* fragmentShader = "..\\assets\\shaders\\defaultFragmentShader.txt", const char* vertexShader = "..\\assets\\shaders\\defaultVertexShader.txt");
    ~Shader();
    void bind();
    void unbind();
    void setInt(const std::string& uniformName, int value);
    void setBool(const std::string& uniformName, bool value);
    void setFloat(const std::string& uniformName, float value);
    void setUniform4f(const std::string& uniformName, float x, float y, float z, float w);
    void bindUniforms();
};

#endif //SHADER_HPP