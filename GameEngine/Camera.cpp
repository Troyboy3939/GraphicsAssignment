#include "Camera.h"

glm::mat4 Camera::GetWorld()
{
	return worldTransform;
}

glm::vec4 Camera::GetWorld(int index)
{
	return worldTransform[index];
}

Camera::Camera()
{
	worldTransform = glm::mat4(1);
	viewTransform = glm::mat4(1);
	projectionTransform = glm::mat4(1);
	projectionViewTransform = glm::mat4(1);
}


void Camera::setPerspective(float fieldOfView, float aspectRatio, float near , float far)
{
	 //projectionTransform = glm::perspective(1.507f, 16 / 9.0f, 0.5f, 5.0f);
	 projectionTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
	 updateProjectionView();

}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	//glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(0, 1, 0));
	viewTransform = glm::lookAt(from,to,up);
	worldTransform = glm::inverse(viewTransform);
	updateProjectionView();
}

void Camera::setPosition(glm::vec3 position)
{
	worldTransform[3] = glm::vec4(position,1);
	viewTransform = glm::inverse(worldTransform);
	updateProjectionView();
}

glm::mat4 Camera::GetView()
{
	return viewTransform; 
}

glm::vec4 Camera::GetView(int index)
{
	return viewTransform[index];
}

glm::mat4 Camera::GetProjection()
{
	return projectionTransform;
}

glm::mat4 Camera::GetProjectionView()
{
	return projectionViewTransform;
}


void Camera::updateProjectionView()
{
	projectionViewTransform = (projectionTransform * viewTransform);
}
