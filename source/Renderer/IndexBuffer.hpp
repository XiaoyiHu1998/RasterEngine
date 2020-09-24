#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
    uint32_t bufferCount;
public:
    IndexBuffer(){}
    IndexBuffer(uint32_t* bufferData, uint32_t dataArrayCount);
    ~IndexBuffer();
    uint32_t getBufferID();
    uint32_t getCount();
    void setBufferData(uint32_t* bufferData, uint32_t dataArrayCount);
    void bind();
    void unbind();
};

#endif //INDEX_BUFFER_HPP