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
        localTransformMatrix = glm::mat4(1.0f);
        localTransformMatrix = glm::translate(glm::rotate(glm::scale(localTransformMatrix, scale), rotation), position);
    }

void SceneNode::render(const glm::mat4& parentTransformMatrix){
    glm::mat4 nodeMatrix = parentTransformMatrix * localTransformMatrix;
    mesh.render(nodeMatrix);
    child->render();
}

void SceneNode::transpose(){
    glm::transpose(localTransformMatrix);
}

void SceneNode::translate(const glm::vec4& translationVec4){
    position += translation;
    localTransformMatrix = glm::translate(localTransformMatrix, translation);
    child->translate(translation);
}

void SceneNode::setLocation(const glm::vec4& translationVec4){
    glm::vec4 displacement = translation - position;
    position = translation;
    localTransformMatrix = glm::translate(glm::rotate(glm::scale(localTransformMatrix, scale), rotation), position);
    child->translate(displacement);
}

void SceneNode::rotate(const glm::vec4& rotationVec4){
    rotation += rotationVec4;
    localTransformMatrix = glm::rotate(localTransformMatrix, rotationVec4);
}

void SceneNode::setRotation(const glm::vec4& rotationVec4){
    rotated = rotationVec4 - rotation;
    rotation = rotationVec4;
    localTransformMatrix = glm::translate(glm::rotate(glm::scale(localTransformMatrix, scale), rotation), position);
    child->rotate(rotated);
}

void SceneNode::scale(const glm::vec4& scaleVec4){
    scaling += scaleVec4;
    localTransformMatrix = glm::scale(localTransformMatrix, scale);
}

void SceneNode::setScale(const glm::vec4& scaleVec4){
    scaled = scaleVec4 - scaling;
    scaling = scaleVec4;
    localTransformMatrix = glm::translate(glm::rotate(glm::scale(localTransformMatrix, scale), rotation), position);
    child->scale(scaled);
}

void SceneNode::transform(const glm::mat4& transformVec4){}
void SceneNode::setTransform(const glm::mat4& transformVec4){}
void SceneNode::resetTransform(const glm::mat4& transformVec4){
    translationDone = glm::vec4(0) - position;
    rotationDone = glm::vec4(0) - rotation;
    scalingDone = glm::vec4(0) - scaling;
    position = glm::vec4(0);
    rotation = glm::Vec4(0);
    scaling = glm::vec4(0);
    localTransformMatrix = glm::mat4(1);

    child->translate(translationDone);
    child->rotate(rotationDone);
    child->scale(scalingDone);
}

// void SceneNode::addMesh(Mesh mesh);
void SceneNode::addChildNode(){}
void SceneNode::addChildNodeAtDepth(){}