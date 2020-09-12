#include "Scene.hpp"

Scene::Scene(){
    meshVector.push_back(Mesh());
}

void Scene::render(){
    for(int i = 0; i < meshVector.size(); i++){
        meshVector[i].render();
    }
}