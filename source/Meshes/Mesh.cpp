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
    GLCall(glEnableClientState(GL_VERTEX_ARRAY));
    GLCall(glVertexPointer(3, GL_FLOAT, 0, 0));

    // std::vector<GLenum> bufferValues = {GL_BUFFER_ACCESS, GL_BUFFER_MAPPED, GL_BUFFER_SIZE, GL_BUFFER_USAGE};
    // int bufferValue = 0;
    // std::cout << "vertexBuffer:" << std::endl;
    // for(GLenum value : bufferValues){
    //     glGetBufferParameteriv(GL_ARRAY_BUFFER, value, &bufferValue);
    //     switch(value){
    //         case GL_BUFFER_ACCESS:  std::cout << "bufferAccess == GL_READ_WRITE: "  << (bufferValue == GL_READ_WRITE)    << std::endl;     break;
    //         case GL_BUFFER_MAPPED:  std::cout << "bufferMapped == GL_FALSE: "       << (bufferValue == GL_FALSE)         << std::endl;     break;
    //         case GL_BUFFER_SIZE:    std::cout << "bufferSize: "                     << bufferValue                       << std::endl;     break;
    //         case GL_BUFFER_USAGE:   std::cout << "bufferUseage == GL_STATIC_DRAW: " << (bufferValue == GL_STATIC_DRAW)   << std::endl;     break;
    //         default:                break;
    //     }
    // }

    indexBuffer->bind();


    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, 0));
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