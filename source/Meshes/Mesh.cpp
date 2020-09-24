#include "Mesh.hpp"

Mesh::Mesh(const VertexBuffer vertexBuffer, const IndexBuffer indexBuffer, const Shader shader):
    vertexBuffer{vertexBuffer},
    indexBuffer{indexBuffer},
    shader{shader}
    {
        vPosDimensions = 3;
        vNormalDimensions = 3;
        vTexDimensions = 2;
    }

void Mesh::render(){
    std::cout << "binding buffers" << std::endl;
    vertexBuffer.bind();
    vertexBuffer.bind();

    std::cout << "setting clientstate" << std::endl;
    GLCall(glEnableClientState(GL_VERTEX_ARRAY));
    std::cout << "setting vertexPointer" << std::endl;
    GLCall(glVertexPointer(3, GL_FLOAT, 0, 0));

    std::cout << "drawing buffers, " << "indexBufferCount: " << indexBuffer.getCount() << std::endl;
    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0));
    std::cout << "disabling client state" << std::endl;
    GLCall(glDisableClientState(GL_VERTEX_ARRAY));

    // float vertices[] = {
    //      0.0f,   0.7f,  0.0f,
    //     -0.5f,  -0.5f,  0.0f,
    //      0.5f,  -0.5f,  0.0f
    // };

    // unsigned int vertexBuffer;
    // glCreateBuffers(1, &vertexBuffer);
    // glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glEnableVertexAttribArray(0);

    // GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0));

    // glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(float));

    // glDeleteBuffers(1, &vertexBuffer);
    // glDisableVertexAttribArray(0);
}