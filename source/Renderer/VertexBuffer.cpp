#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(float (&data)[], int dataArrayCount){
        bufferSize = static_cast<uint32_t>(dataArrayCount) * sizeof(uint32_t);
        glGenBuffers(1, &bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferData(GL_ARRAY_BUFFER, bufferSize, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &bufferID);
}

void VertexBuffer::setBufferData(float (&data)[], int dataArrayCount){
    bufferSize = static_cast<uint32_t>(dataArrayCount) * sizeof(uint32_t);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, data, GL_STATIC_DRAW);
}

uint32_t VertexBuffer::getBufferID(){
    return bufferID;
}