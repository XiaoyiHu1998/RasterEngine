#include "Mesh.hpp"

Mesh::Mesh(){
    vertexPositionDimensions = 3;
    vertexNormalComponentCount = 3;
    vertexTextureCoordinateCount = 2;
}

void Mesh::render(){
    // glBegin(GL_TRIANGLES);
    // glVertex2f(0.0f, 0.7f);
    // glVertex2f(-0.5f, -0.5f);
    // glVertex2f(0.5f, -0.5f);
    // glEnd();

    float vertices[9] = {
         0.0f,   0.7f,  0.0f,
        -0.5f,  -0.5f,  0.0f,
         0.5f,  -0.5f,  0.0f
    };
    std::cout << "vertices" << std::endl;

    unsigned int vertexBuffer;
    glCreateBuffers(1, &vertexBuffer);
    glBindBuffer(GL_BUFFER, vertexBuffer);
    std::cout << "create and bind buffer" << std::endl;
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    std::cout << "set bufferdata" << std::endl;

    glEnableClientState(GL_VERTEX_ARRAY);
    std::cout << "enabled vertex arrays" << std::endl;

    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
    std::cout << "set vertexPointer" << std::endl;

    std::cout << "start drawing arrays" << std::endl;
    glDrawArrays(GL_TRIANGLES, 0, 9);
    std::cout << "drawn arrays" << std::endl;

    glDeleteBuffers(1, &vertexBuffer);
    glDisableClientState(GL_VERTEX_ARRAY);
    std::cout << "deleted buffers" << std::endl;

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}