#include "VertexBuffer_GL.hpp"

VertexBuffer_GL::VertexBuffer_GL(float* bufferData, uint32_t dataArrayCount)
{
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(float);
    GLCall(glGenBuffers(1, &bufferID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

VertexBuffer_GL::~VertexBuffer_GL(){
    GLCall(glDeleteBuffers(1, &bufferID));
}

void VertexBuffer_GL::setBufferData(float* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(float);
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

uint32_t VertexBuffer_GL::getBufferID(){
    return bufferID;
}

uint32_t VertexBuffer_GL::getSize(){
    return bufferSize;
}

uint32_t VertexBuffer_GL::getCount(){
    return bufferCount;
}

void VertexBuffer_GL::bind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
}

void VertexBuffer_GL::unbind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}