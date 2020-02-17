#pragma once
#include "glm.hpp"
#include "ext.hpp"


class Camera
{
public:
	virtual void Update(float fDeltaTime) = 0;
	void SetPerspective(float fFieldOfView, float fAspectRatio, float fNear, float fFar);
	void SetLookAt(glm::vec3 v3From,glm::vec3 v3To, glm::vec3 v3Up);
	void SetPosition(glm::vec3 v3Position);
	glm::mat4 GetView();
	glm::vec4 GetView(int nIndex);
	glm::mat4 GetProjection();
	glm::mat4 GetProjectionView();

	glm::mat4 GetWorld();
	glm::vec4 GetWorld(int nIndex);
	Camera();

protected:
	void UpdateProjectionView();


	glm::mat4 m4WorldTransform;
	glm::mat4 m4ViewTransform;
	glm::mat4 m4ProjectionTransform;
	glm::mat4 m4ProjectionViewTransform;


};

