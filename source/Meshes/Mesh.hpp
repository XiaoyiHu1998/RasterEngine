#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

class Mesh{
private:
    std::shared_ptr<VertexBuffer> vertexBuffer;
    std::shared_ptr<IndexBuffer> indexBuffer;
    std::shared_ptr<Shader> shader;
    
    uint32_t vPosDimensions;
    uint32_t vNormalDimensions;
    uint32_t vTexDimensions;
    float position[4];
    bool direction;
public:
    Mesh(){}
    Mesh(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo, std::shared_ptr<Shader> shader);
    void render();
    void update();
};

#endif //MESH_HPP