#include "Mesh.hpp"

Mesh::Mesh(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo, std::shared_ptr<Shader> shader):
    vertexBuffer{vbo},
    indexBuffer{ibo},
    shader{shader}
    {
        vPosDimensions = 3;
        vNormalDimensions = 3;
        vTexDimensions = 2;
    }

void Mesh::render(){
    vertexBuffer->bind();
    indexBuffer->bind();
    
    GLCall(glEnableClientState(GL_VERTEX_ARRAY));
    GLCall(glVertexPointer(vPosDimensions, GL_FLOAT, 0, 0));

    shader->bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, 0));
    GLCall(glDisableClientState(GL_VERTEX_ARRAY));
}