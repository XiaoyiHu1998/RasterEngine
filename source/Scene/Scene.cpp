#include "Scene.hpp"

Scene::Scene(){
    //temp
    float vertices[] = {
         0.0f,   0.7f,  0.0f,  //0
        -0.5f,  -0.5f,  0.0f,  //1
         0.5f,  -0.5f,  0.0f   //2
    };

    uint32_t indices[]{
        0, 1, 2
    };
    rotationMatrix = glm::mat4(1.0f);

    std::shared_ptr<VertexBuffer> vbo(new VertexBuffer(vertices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<IndexBuffer> ibo(new IndexBuffer(indices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<Shader> shader(new Shader());
    meshVector.push_back(Mesh(vbo, ibo, shader));
}

void Scene::render(){
    float speed = 3.14f / 250.0f;
    rotationMatrix = glm::rotate(glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0)), speed / 4, glm::vec3(0,0,1));
    // rotationMatrix = glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0));
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render(rotationMatrix);
    }
}  