#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

class Mesh{
private:
    VertexBuffer vertexBuffer;
    IndexBuffer indexBuffer;
    Shader shader;
    
    uint32_t vPosDimensions;
    uint32_t vNormalDimensions;
    uint32_t vTexDimensions;
public:
    Mesh(){}
    Mesh(const VertexBuffer vertexBuffer, const IndexBuffer indexBuffer, const Shader shader);
    void render();
};

#endif //MESH_HPP