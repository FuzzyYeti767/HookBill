
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera();

    void SetPerspective(float fov_deg, float aspect_ratio, float near_plane, float far_plane);
    void LookAt(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up);

    const glm::mat4& GetViewMatrix() const;
    const glm::mat4& GetProjectionMatrix() const;

private:
    glm::mat4 view;
    glm::mat4 projection;
};
