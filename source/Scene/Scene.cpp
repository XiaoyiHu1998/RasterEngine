#include "Scene.hpp"

Scene::Scene(){

    float vertices[] = {
         0.0f,   0.7f,  0.0f,
        -0.5f,  -0.5f,  0.0f,
         0.5f,  -0.5f,  0.0f
    };

    uint32_t indices[]{
        1, 2, 3
    };

    VertexBuffer vbo(vertices, sizeof(vertices)/sizeof(float));
    IndexBuffer ibo(indices, sizeof(indices)/sizeof(uint32_t));
    Shader shader;
    meshVector.push_back(Mesh(vbo, ibo, shader));
}

void Scene::render(){
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render();
    }
}