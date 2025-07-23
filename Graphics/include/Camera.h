#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 position, float yaw, float pitch,
        float fov, float aspectRatio, float nearClip, float farClip);

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;
    glm::mat4 GetViewProjectionMatrix() const;

    void SetPosition(const glm::vec3& pos);
    void SetYawPitch(float yaw, float pitch);
    void ProcessRotation(float deltaYaw, float deltaPitch);
    void SetPerspective(float fov, float aspect, float nearClip, float farClip);
    void ProcessMovement(const glm::vec3& direction, float deltaTime);
	glm::vec3 GetPosition() const { return m_Position; }
	glm::vec3 GetFront() const { return m_Front; }
private:
    void UpdateCameraVectors();

    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;

    float m_Yaw;
    float m_Pitch;

  
    float m_FOV;
    float m_Aspect;
    float m_Near;
    float m_Far;
};
