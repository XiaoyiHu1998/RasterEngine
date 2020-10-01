#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
protected:
    uint32_t bufferID;
    uint32_t bufferSize;
    uint32_t bufferCount;
public:
    IndexBuffer(){}
    ~IndexBuffer(){}
    virtual uint32_t getBufferID() = 0;
    virtual uint32_t getCount() = 0;
    virtual void setBufferData(uint32_t* bufferData, uint32_t dataArrayCount) = 0;
    virtual void bind() = 0;
    virtual void unbind() = 0;
};

#endif //INDEX_BUFFER_HPP