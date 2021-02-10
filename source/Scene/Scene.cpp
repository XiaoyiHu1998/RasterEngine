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

    projectionTransformed = true;
    cameraTransformed = true;

    projectionMatrix = glm::perspective(0.56f, 16.0f / 9.0f, 1.0f, 1000.0f);

    cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraRotation = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraScaling = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), cameraPosition);
    glm::mat4 rotationXMatrix = glm::rotate(translationMatrix, cameraRotation.x, glm::vec3(1,0,0));
    glm::mat4 rotationYMatrix = glm::rotate(rotationXMatrix, cameraRotation.y, glm::vec3(0,1,0));
    glm::mat4 rotationZMatrix = glm::rotate(rotationYMatrix, cameraRotation.z, glm::vec3(0,0,1));
    viewMatrix = glm::inverse(glm::scale(rotationZMatrix, cameraScaling));
    rotationMatrix = glm::mat4(1.0f);

    std::shared_ptr<VertexBuffer> vbo(new VertexBuffer(vertices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<IndexBuffer> ibo(new IndexBuffer(indices, sizeof(vertices) / sizeof(float)));
    std::shared_ptr<Shader> shader(new Shader());
    meshVector.push_back(Mesh(vbo, ibo, shader));
}

glm::mat4 Scene::calcViewMatrix(){
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), cameraPosition);
    glm::mat4 rotationXMatrix = glm::rotate(translationMatrix, cameraRotation.x, glm::vec3(1,0,0));
    glm::mat4 rotationYMatrix = glm::rotate(rotationXMatrix, cameraRotation.y, glm::vec3(0,1,0));
    glm::mat4 rotationZMatrix = glm::rotate(rotationYMatrix, cameraRotation.z, glm::vec3(0,0,1));
    return glm::inverse(glm::scale(rotationZMatrix, cameraScaling));
}

// glm::mat4 Scene::calcProjectionMatrix(){
//     return glm::perspective(64.0f, 16.0f / 9.0f, 0.1f, 100.0f);
// }

void Scene::render(){
    // if(cameraTransformed){
    //     cameraTransformed = false;
    //     viewMatrix = calcViewMatrix();
    // }
    // if(projectionTransformed){
    //     projectionTransformed = false;
    //     projectionMatrix = glm::perspective(64.0f, 16.0f / 9.0f, 0.1f, 100.0f);
    //     std::cout << "projectioned" << std::endl;
    // }
    float speed = 3.14f / 240.0f;
    rotationMatrix = glm::rotate(glm::rotate(glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0)), speed, glm::vec3(1,0,0)), speed, glm::vec3(0,0,1));
    // glm::mat4 mat1 = glm::mat4(1.0f);
    // glm::mat4 mat2 = glm::mat4(1.0f);
    // bool equal = mat1 == rotationMatrix;
    // std::cout << equal << std::endl;
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render(rotationMatrix);
    }
}  