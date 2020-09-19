#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "masterInclude.hpp"

class IndexBuffer{
private:
    uint32_t bufferID;
    uint32_t bufferSize;
public:
    IndexBuffer(float (&data)[], int dataArrayCount);
    ~IndexBuffer();
    void setBufferData(float (&data)[], int dataArrayCount);
    uint32_t getBufferID();
};

#endif //INDEX_BUFFER_HPP