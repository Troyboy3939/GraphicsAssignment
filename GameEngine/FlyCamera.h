#pragma once
#include "Camera.h"
#include "glfw3.h"

class FlyCamera :
	public Camera
{
public:
	FlyCamera(const glm::vec3 position,
		const glm::vec3 lookAt,
		const float aspectRatio /* = 16.0 / 9.0f*/,
		const float FOV_Y /* = 3.14159f * 0.5f */,
		const float Near/*  = 0.5f*/,
		const float Far /*= 100.0f */);



	void update(float deltaTime);
	void SetSpeed(float speed);

private:
	float speed;
	float angularSpeed;
	glm::vec3 up;


};

