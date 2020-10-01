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
protected:
    RE::ShaderType shaderType;
    uint32_t programID;
public:
    Shader(){}
    Shader(const char* fragmentShader, const char* vertexShader = "Shaders/defaultVertexShader.txt");
    ~Shader();
    virtual void useProgram();
    virtual void bindUniforms();
};

#endif //SHADER_HPP