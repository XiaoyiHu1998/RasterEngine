#ifndef SCENE_HPP
#define SCENE_HPP

#include "masterInclude.hpp"
#include "SceneNode.hpp"
#include "Mesh.hpp"

class Scene{
private:
    std::vector<Mesh> meshVector;
    std::vector<SceneNode> renderLayers;
    std::vector<bool> layerVisibility;

    bool cameraTransformed;
    bool projectionTransformed;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    glm::vec3 cameraPosition;
    glm::vec3 cameraRotation;
    glm::vec3 cameraScaling;


    glm::mat4 calcViewMatrix();
    glm::mat4 calcProjectionMatrix();
public:
    Scene();
    void render();

};

#endif //SCENE_HPP