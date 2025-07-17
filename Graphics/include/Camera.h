#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
        : m_Position(position), m_Target(target), m_WorldUp(up)
    {
        UpdateCameraVectors();
    }

    glm::mat4 GetViewMatrix() const
    {
        return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
    }

    void SetPosition(const glm::vec3& position)
    {
        m_Position = position;
        UpdateCameraVectors();
    }

    void SetTarget(const glm::vec3& target)
    {
        m_Target = target;
        UpdateCameraVectors();
    }

    void Move(const glm::vec3& offset)
    {
        m_Position += offset;
        m_Target += offset;
        UpdateCameraVectors();
    }

    const glm::vec3& GetPosition() const { return m_Position; }
    const glm::vec3& GetFront() const { return m_Front; }

private:
    glm::vec3 m_Position;
    glm::vec3 m_Target;
    glm::vec3 m_WorldUp;

    glm::vec3 m_Front;
    glm::vec3 m_Right;
    glm::vec3 m_Up;

    void UpdateCameraVectors()
    {
        m_Front = glm::normalize(m_Target - m_Position);
        m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
        m_Up = glm::normalize(glm::cross(m_Right, m_Front));
    }
};
