#include "indexBuffer.hpp"

IndexBuffer::IndexBuffer(uint32_t* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(uint32_t);
    GLCall(glGenBuffers(1, &bufferID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer(){
    GLCall(glDeleteBuffers(1, &bufferID));
}

void IndexBuffer::setBufferData(uint32_t* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(uint32_t);
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

uint32_t IndexBuffer::getBufferID(){
    return bufferID;
}

uint32_t IndexBuffer::getCount(){
    return bufferCount;
}

void IndexBuffer::bind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
}

void IndexBuffer::unbind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}