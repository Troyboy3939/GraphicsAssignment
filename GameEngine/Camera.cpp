#include "Camera.h"

{
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float, float)
{
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
}

void Camera::setPosition(glm::vec3 position)
{
}

glm::mat4 Camera::GetView()
{
	return glm::mat4();
}

glm::mat4 Camera::GetProjection()
{
	return glm::mat4();
}

glm::mat4 Camera::GetProjectionView()
{
	return glm::mat4();
}

void Camera::updateProjectionView()
{
}
