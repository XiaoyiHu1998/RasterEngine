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
    uint32_t shaderID;
public:
    Shader(){}
    ~Shader(){}
    void bindshader(){}
    void bindUniforms(){}
};

#endif //SHADER_HPP