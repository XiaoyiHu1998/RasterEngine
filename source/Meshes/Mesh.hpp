#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

class Mesh{
private:
    VertexBuffer vertexBuffer;
    IndexBuffer indexbuffer;
    Shader shader;
    
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;
public:
    Mesh(VertexBuffer vertexBuffer, IndexBuffer indexBuffer, Shader shader);
    void render();
};

#endif //MESH_HPP