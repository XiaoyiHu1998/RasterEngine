#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "masterInclude.hpp"

class VertexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
    uint32_t bufferCount;
public:
    VertexBuffer(){}
    VertexBuffer(float* bufferData, uint32_t dataArrayCount);
    ~VertexBuffer();
    uint32_t getBufferID();
    uint32_t getSize();
    uint32_t getCount();
    void setBufferData(float* bufferData, uint32_t dataArrayCount);
    void bind();
    void unbind();
};
#endif //VERTEX_BUFFER_HPP