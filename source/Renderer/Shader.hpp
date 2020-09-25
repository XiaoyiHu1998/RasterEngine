#ifndef SHADER_HPP
#define SHADER_HPP

#include "masterInclude.hpp"

namespace RE{
    enum class ShaderType{
        vertexShader,
        fragmentShader
    };
};

class Shader{
private:
    RE::ShaderType shaderType;
    uint32_t programID;
public:
    Shader(){}
    Shader(const char* fragmentShader, const char* vertexShader = "Shaders/defaultVertexShader.txt");
    ~Shader();
    void useProgram();
    void bindUniforms();
};

#endif //SHADER_HPP