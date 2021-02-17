#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include "masterInclude.hpp"
#include "Mesh.hpp"

class SceneNode{
private:
    int nodeDepth;
    bool visible;
    bool transformed;
    std::shared_ptr<SceneNode> child;
    Mesh mesh;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scaling;
    glm::mat4 modelMatrix;

    
    glm::mat4 setWorldSpaceMatrix();
    glm::mat4 calcModelMatrix();
public:
    SceneNode(int nodeDepth, bool visible, Mesh mesh);
    void render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
    void translate(const glm::vec3& translationVec3);
    void setLocation(const glm::vec3& translationVec3);
    void rotate(const glm::vec3& rotationVec3);
    void setRotation(const glm::vec3& rotationVec3);
    void scale(const glm::vec3& scaleVec3);
    void setScale(const glm::vec3& scaleVec3);
    void transform(const glm::mat4& transform);
    void setTransform(const glm::mat4& transform);
    void resetTransform(const glm::mat4& transform);
    void addMesh(Mesh mesh);
    void addChildNode(Mesh mesh);
    void addChildNodeAtDepth();
};


#endif //SCENE_NODE_HPP