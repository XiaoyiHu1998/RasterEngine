#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include "masterInclude.hpp"
#include "Mesh.hpp"

class SceneNode{
private:
    int nodeDepth;
    bool visible;
    SceneNode* child;
    Mesh mesh;

    glm::vec4 position;
    glm::vec4 rotation;
    glm::vec4 scaling;
    glm::mat4 parentMatrix;
    glm::mat4 localTransformMatrix;

    
    glm::mat4 setWorldSpaceMatrix();
public:
    SceneNode();
    void render(glm::mat4& parentTransformMatrix);
    void transpose();
    void translate(const glm::vec4& translationVec4);
    void setLocation(const glm::vec4& translationVec4);
    void rotate(const glm::vec4& rotationVec4);
    void setRotation(const glm::vec4& rotationVec4);
    void scale(const glm::vec4& scaleVec4);
    void setScale(const glm::vec4& scaleVec4);
    void transform(const glm::mat4& transform);
    void setTransform(const glm::mat4& transform);
    void resetTransform(const glm::mat4& transform);
    void addMesh(Mesh mesh);
    void addChildNode();
    void addChildNodeAtDepth();
};


#endif //SCENE_NODE_HPP