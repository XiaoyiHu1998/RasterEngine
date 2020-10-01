#ifndef SHADER_GL_HPP
#define SHADER_GL_HPP

#include "Abstractions/Shader.hpp"

class Shader_GL : public Shader{
private:
    RE::ShaderType shaderType;
    uint32_t programID;
public:
    Shader_GL(){}
    Shader_GL(const char* fragmentShader, const char* vertexShader = "Shaders/defaultVertexShader.txt");
    ~Shader_GL();
    void useProgram() override;
    void bindUniforms() override;
};

#endif //SHADER_GL_HPP