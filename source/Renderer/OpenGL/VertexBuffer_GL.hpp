#ifndef VERTEX_BUFFER_GL_HPP
#define VERTEX_BUFFER_GL_HPP

#include "Abstractions/VertexBuffer.hpp"

class VertexBuffer_GL : public VertexBuffer{
private:
public:
    VertexBuffer_GL(){}
    VertexBuffer_GL(float* bufferData, uint32_t dataArrayCount);
    ~VertexBuffer_GL() override;
    uint32_t getBufferID() override;
    uint32_t getSize() override;
    uint32_t getCount() override;
    void setBufferData(float* bufferData, uint32_t dataArrayCount) override;
    void bind() override;
    void unbind() override;
};
#endif //VERTEX_BUFFER_GL_HPP