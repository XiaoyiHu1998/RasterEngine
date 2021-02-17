#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "masterInclude.hpp"

class Camera{
private:
    bool cameraUpdated;
    bool projectionSettingsUpdated;
    float fov;
    float nearClippingPlane;
    float farClippingPlane;
    float aspectRatio;

    glm::vec3 position;
    glm::vec3 rotation;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    glm::mat4 screenSpaceMatrix;
public:
    Camera(float fovyDegrees, float nearClippingPlane, float farClippingPlane, float aspectRatio, glm::vec3 pos, glm::vec3 rot);
    void setPosition(const glm::vec3& newPosition);
    void translate(const glm::vec3& translation);
    void setRotation(const glm::vec3& newRotation);
    void rotate(const glm::vec3& rotated);
    void setNearClippingPlane(float newClippingDistance);
    void setFarClippingPlane(float newClippingDistance);
    void setAspectRatio(float width, float height);
    void setFovY(float fovY);
    void setFovX(float fovY);
    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();
};


#endif //CAMERA_HPP