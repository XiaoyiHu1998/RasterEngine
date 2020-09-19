#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "masterInclude.hpp"

class VertexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
public:
    VertexBuffer(float (&data)[], int dataArrayCount);
    ~VertexBuffer();
    void setBufferData(float (&data)[], int dataArrayCount);
    uint32_t getBufferID();
};

#endif //VERTEX_BUFFER_HPP