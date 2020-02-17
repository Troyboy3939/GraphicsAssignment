#include "Camera.h"

glm::mat4 Camera::GetWorld()
{
	return m4WorldTransform;
}

glm::vec4 Camera::GetWorld(int nIndex)
{
	return m4WorldTransform[nIndex];
}

Camera::Camera()
{
	m4WorldTransform = glm::mat4(1);
	m4ViewTransform = glm::mat4(1);
	m4ProjectionTransform = glm::mat4(1);
	m4ProjectionViewTransform = glm::mat4(1);
}


void Camera::SetPerspective(float fFieldOfView, float fAspectRatio, float fNear , float fFar)
{
	 //projectionTransform = glm::perspective(1.507f, 16 / 9.0f, 0.5f, 5.0f);
	 m4ProjectionTransform = glm::perspective(fFieldOfView, fAspectRatio, fNear, fFar);
	 UpdateProjectionView();

}

void Camera::SetLookAt(glm::vec3 v3From, glm::vec3 v3To, glm::vec3 v3Up)
{
	//glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(0, 1, 0));
	m4ViewTransform = glm::lookAt(v3From,v3To,v3Up);
	m4WorldTransform = glm::inverse(m4ViewTransform);
	UpdateProjectionView();
}

void Camera::SetPosition(glm::vec3 v3Position)
{
	m4WorldTransform[3] = glm::vec4(v3Position,1);
	m4ViewTransform = glm::inverse(m4WorldTransform);
	UpdateProjectionView();
}

glm::mat4 Camera::GetView()
{
	return m4ViewTransform; 
}

glm::vec4 Camera::GetView(int nIndex)
{
	return m4ViewTransform[nIndex];
}

glm::mat4 Camera::GetProjection()
{
	return m4ProjectionTransform;
}

glm::mat4 Camera::GetProjectionView()
{
	return m4ProjectionViewTransform;
}


void Camera::UpdateProjectionView()
{
	m4ProjectionViewTransform = (m4ProjectionTransform * m4ViewTransform);
}
