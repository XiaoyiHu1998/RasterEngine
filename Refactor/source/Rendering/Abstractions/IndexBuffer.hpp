#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
protected:
    uint32_t bufferID;
    uint32_t bufferSize;
    uint32_t bufferCount;
public:
    IndexBuffer(uint32_t* bufferData, uint32_t dataArrayCount);
    ~IndexBuffer();
    virtual uint32_t getBufferID();
    virtual uint32_t getCount();
    virtual void setBufferData(uint32_t* bufferData, uint32_t dataArrayCount);
    virtual void bind();
    virtual void unbind();
};

#endif //INDEX_BUFFER_HPP