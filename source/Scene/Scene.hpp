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
public:
    Scene();
    void render();
};

#endif //SCENE_HPP