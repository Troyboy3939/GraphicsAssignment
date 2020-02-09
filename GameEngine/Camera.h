#pragma once
#include "glm.hpp"


class Camera
{
public:
	virtual void update() = 0;
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from,glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	glm::mat4 GetView();
	glm::mat4 GetProjection();
	glm::mat4 GetProjectionView();


private:
	void updateProjectionView();


	glm::mat4 worldTransform;
	glm::mat4 viewTransform;
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;


};

