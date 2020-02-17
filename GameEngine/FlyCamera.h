#pragma once
#include "Camera.h"
#include "glfw3.h"

class FlyCamera :
	public Camera
{
public:
	FlyCamera(const glm::vec3 v3Position,
		const glm::vec3 v3LookAt,
		const float fAspectRatio /* = 16.0 / 9.0f*/,
		const float fFOV_Y /* = 3.14159f * 0.5f */,
		const float fNear/*  = 0.5f*/,
		const float fFar /*= 100.0f */);



	void Update(float fDeltaTime);
	void SetSpeed(float fSpeed);

private:
	float m_fSpeed;
	float m_fAngularSpeed;
	glm::vec3 m_fUp;


};

