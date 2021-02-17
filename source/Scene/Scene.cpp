#include "Scene.hpp"

Scene::Scene():
    camera(Camera(64.0f, 0.1, 500.0f, 16.0f / 9.0f, glm::vec3(0,0,1.5f), glm::vec3(0,0,0)))
    {
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

    glm::mat4 matrix = camera.getProjectionMatrix() * camera.getViewMatrix() *  rotationMatrix;
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render(matrix);
    }
}  

void Scene::render(int viewportWidth, int viewportHeight){
    float speed = 3.14f / 250.0f;
    rotationMatrix = glm::rotate(glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0)), speed / 4, glm::vec3(0,0,1));

    camera.setAspectRatio((float)viewportWidth, (float)viewportHeight);

    glm::mat4 matrix = camera.getProjectionMatrix() * camera.getViewMatrix() *  rotationMatrix;
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render(matrix);
    }
}  