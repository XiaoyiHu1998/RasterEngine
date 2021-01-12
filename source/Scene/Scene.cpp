#include "Scene.hpp"

Scene::Scene(){

    float vertices[] = {
         0.0f,   0.7f,  0.0f,  //0
        -0.5f,  -0.5f,  0.0f,  //1
         0.5f,  -0.5f,  0.0f   //2
    };

    uint32_t indices[]{
        0, 1, 2
    };

    std::shared_ptr<VertexBuffer> vbo(new VertexBuffer(vertices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<IndexBuffer> ibo(new IndexBuffer(indices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<Shader> shader(new Shader());
    meshVector.push_back(Mesh(vbo, ibo, shader));
}

void Scene::render(){
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render();
    }

    for(int i = 0; i < renderLayers.size(); i++){
        if(layerVisibility[i]){
            renderLayers[i];
        }
    }
}