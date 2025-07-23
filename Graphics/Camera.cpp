#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>

Camera::Camera(glm::vec3 position, float yaw, float pitch,
    float fov, float aspectRatio, float nearClip, float farClip)
    : m_Position(position), m_Yaw(yaw), m_Pitch(pitch),
    m_FOV(fov), m_Aspect(aspectRatio), m_Near(nearClip), m_Far(farClip),
    m_WorldUp(0.0f, 1.0f, 0.0f)
{
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::perspective(glm::radians(m_FOV), m_Aspect, m_Near, m_Far);
}

glm::mat4 Camera::GetViewProjectionMatrix() const
{
    return GetProjectionMatrix() * GetViewMatrix();
}

void Camera::SetPerspective(float fov, float aspect, float nearClip, float farClip)
{
    m_FOV = fov;
    m_Aspect = aspect;
    m_Near = nearClip;
    m_Far = farClip;
}

void Camera::SetPosition(const glm::vec3& pos)
{
    m_Position = pos;
}

void Camera::SetYawPitch(float yaw, float pitch)
{
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateCameraVectors();
}

void Camera::ProcessRotation(float deltaYaw, float deltaPitch)
{
    m_Yaw += deltaYaw;
    m_Pitch += deltaPitch;
    m_Pitch = glm::clamp(m_Pitch, -89.0f, 89.0f);
    UpdateCameraVectors();
}

void Camera::ProcessMovement(const glm::vec3& direction, float deltaTime)
{
    float speed = 2.5f * deltaTime;

    glm::vec3 offset = m_Right * direction.x +
        m_Up * direction.y +
        m_Front * direction.z;

    if (glm::length(offset) > 0.0f)
        m_Position += glm::normalize(offset) * speed;
}




void Camera::UpdateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}
