#ifndef SHADER_HPP
#define SHADER_HPP

class Shader{
private:
public:
    Shader(const char* fragmentShader = "../../assets/Shaders/defaultFragmentShader.txt", const char* vertexShader = "../../assets/Shaders/defaultVertexShader.txt");
    ~Shader();
    void useProgram();
    void bindUniforms();
};

#endif //SHADER_HPP