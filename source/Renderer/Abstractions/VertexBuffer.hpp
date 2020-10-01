#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "masterInclude.hpp"

class VertexBuffer{
protected:
    uint32_t bufferID;
    uint32_t bufferSize;
    uint32_t bufferCount;
public:
    VertexBuffer(){}
    virtual ~VertexBuffer(){}
    virtual uint32_t getBufferID() = 0;
    virtual uint32_t getSize() = 0;
    virtual uint32_t getCount() = 0;
    virtual void setBufferData(float* bufferData, uint32_t dataArrayCount) = 0;
    virtual void bind() = 0;
    virtual void unbind() = 0;
};
#endif //VERTEX_BUFFER_HPP