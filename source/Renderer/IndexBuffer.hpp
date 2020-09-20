#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
public:
    IndexBuffer(){}
    IndexBuffer(float* bufferData, int dataArrayCount);
    ~IndexBuffer();
    uint32_t getBufferID();
    void setBufferData(float* bufferData, int dataArrayCount);
    void bind();
    void unbind();
};

#endif //INDEX_BUFFER_HPP