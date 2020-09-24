#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(float* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(float);
    GLCall(glGenBuffers(1, &bufferID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer(){
    GLCall(glDeleteBuffers(1, &bufferID));
}

void VertexBuffer::setBufferData(float* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(float);
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

uint32_t VertexBuffer::getBufferID(){
    return bufferID;
}

uint32_t VertexBuffer::getSize(){
    return bufferSize;
}

uint32_t VertexBuffer::getCount(){
    return bufferCount;
}

void VertexBuffer::bind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
}

void VertexBuffer::unbind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}