#include "Mesh.hpp"

Mesh::Mesh(){
    vertexPositionDimensions = 3;
    vertexNormalComponentCount = 3;
    vertexTextureCoordinateCount = 2;
}

void Mesh::render(){
    float vertices[] = {
         0.0f,   0.7f,  0.0f,
        -0.5f,  -0.5f,  0.0f,
         0.5f,  -0.5f,  0.0f
    };

    unsigned int vertexBuffer;
    glCreateBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(float));

    glDeleteBuffers(1, &vertexBuffer);
    glDisableVertexAttribArray(0);
}