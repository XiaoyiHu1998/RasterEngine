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

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;
    glm::mat4 parentMatrix;
    glm::mat4 worldSpaceMatrix;

    
    glm::mat4 setWorldSpaceMatrix();
public:
    SceneNode();
    void render(glm::mat4& parentTransformMatrix);
    void transpose();
    void translate(const glm::vec4& translation);
    void setLocation(const glm::vec4& translation);
    void rotate(const glm::vec4& rotation);
    void setRotation(const glm::vec4& rotation);
    void scale(const glm::vec4& scale);
    void setScale(const glm::vec4& scale);
    void transform(const glm::mat4& transform);
    void setTransform(const glm::mat4& transform);
    void resetTransform(const glm::mat4& transform);
    void addMesh(Mesh mesh);
    void addChildNode();
    void addChildNodeAtDepth();
};


#endif //SCENE_NODE_HPP