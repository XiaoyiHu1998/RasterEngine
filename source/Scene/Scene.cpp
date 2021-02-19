#include "Scene.hpp"

Scene::Scene():
    renderLayers{std::vector<SceneNode>()},
    camera{Camera(55.0f, 0.1, 500.0f, 16.0f / 9.0f, glm::vec3(0,0,2.0f), glm::vec3(0,0,0))}
    {
        //temp
        float vertices[] = {
            -0.5f,   0.4f,  -0.05f,   //0
            -0.5f,  -0.5f,  -0.05f,   //1
            0.4f,  -0.5f,  -0.05f     //2
        };
        
        float vertices2[] = {
            0.7f,   -0.7f,  0.05f,   //0
            0.7f,  0.7f,  0.05f,     //1
            -0.7f,  0.7f,  0.05f     //2
        };

        uint32_t indices[]{
            0, 1, 2
        };

        rotationMatrix = glm::mat4(1.0f);

        std::shared_ptr<VertexBuffer> vbo(new VertexBuffer(vertices, sizeof(vertices) / sizeof(float)));
        std::shared_ptr<VertexBuffer> vbo2(new VertexBuffer(vertices2, sizeof(vertices2) / sizeof(float)));
        std::shared_ptr<IndexBuffer> ibo(new IndexBuffer(indices, sizeof(vertices) / sizeof(float)));
        std::shared_ptr<Shader> shader(new Shader());
        renderLayers.push_back(SceneNode(Mesh(vbo, ibo, shader)));
        renderLayers[0].addChildNode(Mesh(vbo2, ibo, shader));
    }

void Scene::render(){
    float speed = 3.14f / 250.0f;
    rotationMatrix = glm::rotate(glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0)), speed / 4, glm::vec3(0,0,1));

    for(SceneNode& renderLayer : renderLayers){
        renderLayer.rotate(glm::vec3(0,0,0.01));
        renderLayer.render(camera.getViewMatrix() * rotationMatrix, camera.getProjectionMatrix());
    }
}  

void Scene::render(int viewportWidth, int viewportHeight){
    float speed = 3.14f / 250.0f;
    rotationMatrix = glm::rotate(glm::rotate(rotationMatrix, speed, glm::vec3(0,1,0)), speed / 4, glm::vec3(0,0,1));

    camera.setAspectRatio((float)viewportWidth, (float)viewportHeight);

    for(SceneNode& renderLayer : renderLayers){
        renderLayer.rotate(glm::vec3(0,0,0.01));
        renderLayer.render(camera.getViewMatrix() * rotationMatrix, camera.getProjectionMatrix());
    }
}

// old meshVector code just in case
    // glm::mat4 matrix = camera.getProjectionMatrix() * camera.getViewMatrix() *  rotationMatrix;
    // for(int i = 0; i < meshVector.size(); i++){
    //     meshVector[i].render(matrix);
    // }
        // meshVector.push_back(Mesh(vbo, ibo, shader));
