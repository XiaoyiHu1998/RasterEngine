#include "indexBuffer.hpp"

IndexBuffer::IndexBuffer(float (&data)[], int dataArrayCount){
        bufferSize = static_cast<uint32_t>(dataArrayCount) * sizeof(uint32_t);
        glGenBuffers(1, &bufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &bufferID);
}

void IndexBuffer::setBufferData(float (&data)[], int dataArrayCount){
    bufferSize = static_cast<uint32_t>(dataArrayCount) * sizeof(uint32_t);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, data, GL_STATIC_DRAW);
}

uint32_t IndexBuffer::getBufferID(){
    return bufferID;
}