#include "Camera.hpp"

Camera::Camera(float fovyDegrees, float nearClippingPlane, float farClippingPlane, float aspectRatio, glm::vec3 pos, glm::vec3 rot):
    cameraUpdated{true},
    projectionSettingsUpdated{true},
    fov{fovyDegrees},
    nearClippingPlane{nearClippingPlane},
    aspectRatio{aspectRatio},
    position{pos},
    rotation{rot}
    {}

glm::mat4 Camera::getProjectionMatrix(){
    if(projectionSettingsUpdated){
        projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearClippingPlane, farClippingPlane);
        projectionSettingsUpdated = false;
    }

    return projectionMatrix;
}

glm::mat4 Camera::getViewMatrix(){
    if(cameraUpdated){
        viewMatrix = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1,0,0))
                 * glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0,1,0)) * glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0,0,1));
    
        viewMatrix = glm::inverse(viewMatrix);
        cameraUpdated = false;
    }

    return viewMatrix;
}

void Camera::setPosition(const glm::vec3& newPosition){
    position = newPosition;
    cameraUpdated = true;
}

void Camera::translate(const glm::vec3& translation){
    position += translation;
    cameraUpdated = true;
}

void Camera::setRotation(const glm::vec3& newRotation){
    rotation = newRotation;
    cameraUpdated = true;
}

void Camera::rotate(const glm::vec3& rotated){
    rotation += rotated;
    cameraUpdated = true;
}

void Camera::setNearClippingPlane(float newClippingDistance){
    nearClippingPlane = newClippingDistance;
    projectionSettingsUpdated = true;
}

void Camera::setFarClippingPlane(float newClippingDistance){
    farClippingPlane = newClippingDistance;
    projectionSettingsUpdated = true;
}

void Camera::setAspectRatio(float width, float height){
    aspectRatio = width / height;
    projectionSettingsUpdated = true;
}

void Camera::setFovY(float fovY){
    fov = fovY;
    projectionSettingsUpdated = true;
}

void Camera::setFovX(float fovX){
    fov = 2 * glm::atan(glm::tan(fovX / 2) * aspectRatio);
    projectionSettingsUpdated = true;
}