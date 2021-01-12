#include "Mesh.hpp"

Mesh::Mesh(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo, std::shared_ptr<Shader> shader):
    vertexBuffer{vbo},
    indexBuffer{ibo},
    shader{shader}
    {
        vPosDimensions = 3;
        vNormalDimensions = 3;
        vTexDimensions = 2;
        for(int i = 0; i < 4; i++){
            position[i] = 0;
        }
        direction = true;
    }

void Mesh::render(){
    vertexBuffer->bind();
    indexBuffer->bind();
    shader->bind();
    
    GLCall(glEnableClientState(GL_VERTEX_ARRAY));
    GLCall(glVertexPointer(vPosDimensions, GL_FLOAT, 0, 0));

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, 0));
    GLCall(glDisableClientState(GL_VERTEX_ARRAY));
    update();
}

void Mesh::render(const glm::mat4& projectionMatrix){
    vertexBuffer->bind();
    indexBuffer->bind();
    shader->bind();
    shader->setMatrix4f("projectionMatrix", projectionMatrix);
    
    GLCall(glEnableClientState(GL_VERTEX_ARRAY));
    GLCall(glVertexPointer(vPosDimensions, GL_FLOAT, 0, 0));

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, 0));
    GLCall(glDisableClientState(GL_VERTEX_ARRAY));
    update();
}

// temp function for little animation test
void Mesh::update(){
    if(direction){
        position[0] -= 0.016;
        position[1] -= 0.026;
        position[2] -= 0.010;
        position[3] -= 0.010;
        if(position[0] < 0){
            direction = false;
        }
    }
    else{
        position[0] += 0.016;
        position[1] += 0.026;
        position[2] += 0.010;
        position[3] += 0.010;
        if(position[0] > 1){
            direction = true;
        }
    }
    shader->setUniform4f("location", position[0], position[1], position[2], position[3]);
}
