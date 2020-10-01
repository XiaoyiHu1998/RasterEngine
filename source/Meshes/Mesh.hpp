#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"
#include "VertexBuffer_GL.hpp"
#include "IndexBuffer_GL.hpp"
#include "Shader_GL.hpp"

class Mesh{
private:
    std::shared_ptr<VertexBuffer> vertexBuffer;
    std::shared_ptr<IndexBuffer> indexBuffer;
    std::shared_ptr<Shader> shader;
    
    uint32_t vPosDimensions;
    uint32_t vNormalDimensions;
    uint32_t vTexDimensions;
public:
    Mesh(){}
    Mesh(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo, std::shared_ptr<Shader> shader);
    void render();
};

#endif //MESH_HPP