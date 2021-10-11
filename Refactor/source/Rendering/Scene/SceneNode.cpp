#include "SceneNode.hpp"

SceneNode::SceneNode(Mesh mesh, int nodeDepth, bool visible):
    nodeDepth{nodeDepth},
    visible{visible},
    mesh{mesh},
    child(nullptr),
    transformed{false}
    {
        position = glm::vec3(0,0,0);
        rotation = glm::vec3(0,0,0);
        scaling = glm::vec3(1,1,1);
        modelMatrix = glm::mat4(1.0f);
    }

glm::mat4 SceneNode::calcModelMatrix(){
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
    glm::mat4 rotationXMatrix = glm::rotate(translationMatrix, rotation.x, glm::vec3(1,0,0));
    glm::mat4 rotationYMatrix = glm::rotate(rotationXMatrix, rotation.y, glm::vec3(0,1,0));
    glm::mat4 rotationZMatrix = glm::rotate(rotationYMatrix, rotation.z, glm::vec3(0,0,1));
    glm::mat4 scalingMatrix = glm::scale(rotationZMatrix, scaling);
    return scalingMatrix;
}

//needs to be optimized by multiplying camera and projection matrices first before sending it down the line.
void SceneNode::render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix){
    if(transformed){
        modelMatrix = calcModelMatrix();
        transformed = false;
    }
    glm::mat4 nodeMatrix = projectionMatrix * viewMatrix * modelMatrix;
    mesh.render(nodeMatrix);
    if(child != nullptr)
        child->render(viewMatrix, projectionMatrix);
}

void SceneNode::translate(const glm::vec3& translationVec3){
    transformed = true;
    position += translationVec3;
    if(child != nullptr)
        child->translate(translationVec3);
}

void SceneNode::setLocation(const glm::vec3& translationVec3){
    transformed = true;
    glm::vec3 displacement = translationVec3 - position;
    position = translationVec3;
    if(child != nullptr)
        child->translate(displacement);
}

void SceneNode::rotate(const glm::vec3& rotationVec3){
    transformed = true;
    rotation += rotationVec3;
    if(child != nullptr)
        child->rotate(rotationVec3);
}

void SceneNode::setRotation(const glm::vec3& rotationVec3){
    transformed = true;
    glm::vec3 rotated = rotationVec3 - rotation;
    rotation = rotationVec3;
    if(child != nullptr)
        child->rotate(rotated);
}

void SceneNode::scale(const glm::vec3& scaleVec3){
    transformed = true;
    scaling += scaleVec3;
    if(child != nullptr)
        child->scale(scaleVec3);
}

void SceneNode::setScale(const glm::vec3& scaleVec3){
    transformed = true;
    glm::vec3 scaled = scaleVec3 - scaling;
    scaling = scaleVec3;
    if(child != nullptr)
        child->scale(scaled);
}

// void SceneNode::transform(const glm::mat4& transformVec3){}
// void SceneNode::setTransform(const glm::mat4& transformVec3){}

void SceneNode::resetTransform(const glm::mat4& transformVec3){
    transformed = true;
    glm::vec3 translationDone = glm::vec3(0) - position;
    glm::vec3 rotationDone = glm::vec3(0) - rotation;
    glm::vec3 scalingDone = glm::vec3(0) - scaling;
    position = glm::vec3(0);
    rotation = glm::vec3(0);
    scaling = glm::vec3(0);

    if(child != nullptr){
        child->translate(translationDone);
        child->rotate(rotationDone);
        child->scale(scalingDone);
    }
}

// // void SceneNode::addMesh(Mesh mesh);
//TODO: needs to check if buffers get destroyed due to pass by copy
void SceneNode::addChildNode(Mesh mesh){
    RE_STUB("TODO: needs to check if buffers get destroyed due to pass by copy");
    if(child == nullptr){ 
        child = std::shared_ptr<SceneNode>(new SceneNode(mesh, nodeDepth + 1, true));
    }
    else{
        child->addChildNode(mesh);
    }
}
// void SceneNode::addChildNodeAtDepth(){}