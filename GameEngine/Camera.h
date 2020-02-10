#pragma once
#include "glm.hpp"
#include "ext.hpp"


class Camera
{
public:
	virtual void update(float deltaTime) = 0;
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from,glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	glm::mat4 GetView();
	glm::vec4 GetView(int index);
	glm::mat4 GetProjection();
	glm::mat4 GetProjectionView();

	glm::mat4 GetWorld();
	glm::vec4 GetWorld(int index);
	Camera();

protected:
	void updateProjectionView();


	glm::mat4 worldTransform;
	glm::mat4 viewTransform;
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;


};

