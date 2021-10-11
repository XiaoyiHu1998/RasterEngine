#ifndef SCENE_HPP
#define SCENE_HPP

#include "masterInclude.hpp"
#include "SceneNode.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"

class Scene{
private:
    std::vector<Mesh> meshVector;
    std::vector<SceneNode> renderLayers;
    std::vector<bool> layerVisibility;
    glm::mat4 rotationMatrix;
    Camera camera;
public:
    Scene();
    void render(uint32_t width, uint32_t height);
};

#endif //SCENE_HPP