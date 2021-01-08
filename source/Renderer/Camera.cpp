#include "Camera.hpp"

Camera::Camera(){

}

void Camera::calculateCameraMatrix(){
    cameraMatrix = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1,0,0))
                 * glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0,1,0)) * glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0,0,1));
    
    cameraMatrix = glm::inverse(cameraMatrix);
    cameraUpdated = false;
}

void Camera::calculateProjectionMatrix(){
    projectionMatrix = glm::perspective(fov, aspectRatio, nearClippingPlane, farClippingPlane);
    projectionSettingsUpdated = false;
}

glm::mat4 Camera::getScreenSpaceMatrix(){
    if(cameraUpdated || projectionSettingsUpdated){
        if(cameraUpdated){
            calculateCameraMatrix();
        }
        if(projectionSettingsUpdated){
            calculateProjectionMatrix();
        }

        screenSpaceMatrix = cameraMatrix * screenSpaceMatrix;
    }

    return screenSpaceMatrix;
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

void Camera::setCameraAspectRatio(float width, float height){
    aspectRatio = static_cast<float>(width / height);
    projectionSettingsUpdated = true;
}

void Camera::setCameraFovY(float fovY){
    fov = fovY;
    projectionSettingsUpdated = true;
}

void Camera::setCameraFovX(float fovX){
    fov = 2 * glm::atan(glm::tan(fovX / 2) * aspectRatio);
    projectionSettingsUpdated = true;
}