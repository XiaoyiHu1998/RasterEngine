#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include "masterInclude.hpp"
#include "..\Meshes\Mesh.hpp"

class SceneNode{
private:
    int nodeLayer;

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;
    glm::mat4 worldSpaceMatrix;

    SceneNode* child;
    std::vector<Mesh> meshes;
    
    glm::mat4 setWorldSpaceMatrix();
public:
    SceneNode();
    void render(glm::mat4& parentTransformMatrix);
    void transpose();
    void setLocation();
    void scale();
    void setScale();
    void rotate();
    void setRotation();
    void resetTransform();
    void addMesh();
    void addChildNode();
};


#endif //SCENE_NODE_HPP