#include "IndexBuffer_GL.hpp"

IndexBuffer_GL::IndexBuffer_GL(uint32_t* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(uint32_t);
    GLCall(glGenBuffers(1, &bufferID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

IndexBuffer_GL::~IndexBuffer_GL(){
    GLCall(glDeleteBuffers(1, &bufferID));
}

void IndexBuffer_GL::setBufferData(uint32_t* bufferData, uint32_t dataArrayCount){
    bufferCount = dataArrayCount;
    bufferSize = dataArrayCount * sizeof(uint32_t);
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

uint32_t IndexBuffer_GL::getBufferID(){
    return bufferID;
}

uint32_t IndexBuffer_GL::getCount(){
    return bufferCount;
}

void IndexBuffer_GL::bind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
}

void IndexBuffer_GL::unbind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}