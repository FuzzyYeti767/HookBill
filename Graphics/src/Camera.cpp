#include "Camera.h"

Camera::Camera()
{
    // 기본값 설정: 45도 FOV, 4:3 종횡비, near 0.1, far 100
    SetPerspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    LookAt(glm::vec3(0.0f, 0.0f, 3.0f),   // 카메라 위치
        glm::vec3(0.0f, 0.0f, 0.0f),   // 바라보는 지점
        glm::vec3(0.0f, 1.0f, 0.0f));  // 업벡터
}

void Camera::SetPerspective(float fov_deg, float aspect_ratio, float near_plane, float far_plane)
{
    projection = glm::perspective(glm::radians(fov_deg), aspect_ratio, near_plane, far_plane);
}

void Camera::LookAt(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up)
{
    view = glm::lookAt(position, target, up);
}

const glm::mat4& Camera::GetViewMatrix() const
{
    return view;
}

const glm::mat4& Camera::GetProjectionMatrix() const
{
    return projection;
}
