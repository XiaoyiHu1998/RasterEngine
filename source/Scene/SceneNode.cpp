#include "SceneNode.hpp"

SceneNode::SceneNode(int nodeDepth, bool visible, Mesh mesh, const glm::mat4& parentsMatrix):
    nodeDepth{nodeDepth},
    visibility{visible},
    mesh{mesh},
    parentsMatrix{parentsMatrix}
    {
        position = glm::vec4(0,0,0,1);
        rotation = glm::vec4(0,0,0,1);
        scale = glm::vec4(1,1,1,1);
        worldSpaceMatrix = glm::mat4(1.0f);
        worldSpaceMatrix = glm::translate(glm::rotate(glm::scale(worldSpaceMatrix, scale), rotation), position);
    }

void SceneNode::render(){
    mesh.render(worldSpaceMatrix);
    child->render();
}

void SceneNode::transpose(){
    glm::transpose(worldSpaceMatrix);
}

void SceneNode::translate(const glm::vec4& translationVec4){
    position += translation;
    worldSpaceMatrix = glm::translate(worldSpaceMatrix, translation);
    child->translate(translation);
}

void SceneNode::setLocation(const glm::vec4& translationVec4){
    glm::vec4 displacement = translation - position;
    position = translation;
    worldSpaceMatrix = glm::translate(glm::rotate(glm::scale(worldSpaceMatrix, scale), rotation), position);
    child->translate(displacement);
}

void SceneNode::rotate(const glm::vec4& rotationVec4){
    rotation += rotationVec4;
    worldSpaceMatrix = glm::rotate(worldSpaceMatrix, rotationVec4);
}

void SceneNode::setRotation(const glm::vec4& rotationVec4){
    rotated = rotationVec4 - rotation;
    rotation = rotationVec4;
    worldSpaceMatrix = glm::translate(glm::rotate(glm::scale(worldSpaceMatrix, scale), rotation), position);
    child->rotate(rotated);
}

void SceneNode::scale(const glm::vec4& scaleVec4){
    scale += scaleVec4;
    worldSpaceMatrix = glm::scale(worldSpaceMatrix, scale);
}

void SceneNode::setScale(const glm::vec4& scaleVec4){
    scaled = scaleVec4 - scale;
    scale = scaleVec4;
    worldSpaceMatrix = glm::translate(glm::rotate(glm::scale(worldSpaceMatrix, scale), rotation), position);
    child->scale(scaled);
}

void SceneNode::transform(const glm::mat4& transformVec4){}
void SceneNode::setTransform(const glm::mat4& transformVec4){}
void SceneNode::resetTransform(const glm::mat4& transformVec4){
    translation = glm::vec4(0) - position;
    rotation = glm::vec4(0) - rotation;
    scaling = glm::vec4(0) - scale;
    position = glm::vec4(0);
    rotation = glm::Vec4(0);
    scale = glm::vec4(0);
    worldSpaceMatrix = glm::mat4(1);

    child->translate(translation);
    child->rotate(rotation);
    child->scale(scaling);
}

// void SceneNode::addMesh(Mesh mesh);
void SceneNode::addChildNode(){}
void SceneNode::addChildNodeAtDepth(){}