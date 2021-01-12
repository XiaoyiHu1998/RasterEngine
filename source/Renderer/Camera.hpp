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

    glm::mat4 cameraMatrix;
    glm::mat4 projectionMatrix;
    glm::mat4 screenSpaceMatrix;

    void calculateCameraMatrix();
    void calculateProjectionMatrix();
    void calculateScreenSpaceMatrix();
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
    glm::mat4 getScreenSpaceMatrix();
};


#endif //CAMERA_HPP