#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "masterInclude.hpp"

class Camera{
private:
    bool cameraUpdated;
    bool projectionSettingsUpdated;
    float nearClippingPlane;
    float farClippingPlane;
    float fov;
    float aspectRatio;

    glm::vec3 position;
    glm::vec3 rotation;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    glm::mat4 screenSpaceMatrix;

    void updateViewMatrix();
    void updateProjectionMatrix();
public:
    Camera();
    void setPosition(const glm::vec3& newPosition);
    void translate(const glm::vec3& translation);
    void setRotation(const glm::vec3& newRotation);
    void rotate(const glm::vec3& rotated);
    void setNearClippingPlane(float newClippingDistance);
    void setFarClippingPlane(float newClippingDistance);
    void setCameraAspectRatio(float width, float height);
    void setCameraFovY(float fovY);
    void setCameraFovX(float fovY);
    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();
};


#endif //CAMERA_HPP