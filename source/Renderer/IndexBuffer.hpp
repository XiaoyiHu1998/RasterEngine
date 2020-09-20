#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
public:
    IndexBuffer(){}
    IndexBuffer(uint32_t* bufferData, int dataArrayCount);
    ~IndexBuffer();
    uint32_t getBufferID();
    void setBufferData(uint32_t* bufferData, int dataArrayCount);
    void bind();
    void unbind();
};

#endif //INDEX_BUFFER_HPP