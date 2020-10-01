#ifndef INDEX_BUFFER_GL_HPP
#define INDEX_BUFFER_GL_HPP

#include "Abstractions/IndexBuffer.hpp"

class IndexBuffer_GL : public IndexBuffer{
private:
public:
    IndexBuffer_GL(){}
    IndexBuffer_GL(uint32_t* bufferData, uint32_t dataArrayCount);
    ~IndexBuffer_GL();
    uint32_t getBufferID() override;
    uint32_t getCount() override;
    void setBufferData(uint32_t* bufferData, uint32_t dataArrayCount) override;
    void bind() override;
    void unbind() override;
};

#endif //INDEX_BUFFER_GL_HPP