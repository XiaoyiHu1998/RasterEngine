#ifndef SCENE_HPP
#define SCENE_HPP

#include "masterInclude.hpp"
#include "Mesh.hpp"

class Scene{
private:
    std::vector<Mesh> meshVector;
public:
    Scene();
    void render();
};

#endif //SCENE_HPP