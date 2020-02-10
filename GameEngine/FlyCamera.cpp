#include "FlyCamera.h"


FlyCamera::FlyCamera(const glm::vec3 position, const glm::vec3 lookAt, const float aspectRatio, const float FOV_Y, const float near, const float far) : Camera::Camera()
{
	up = glm::vec3(0,1,0);
	speed = 1;
	angularSpeed = 0.5f;
	setPerspective(FOV_Y, aspectRatio, near, far);
	setLookAt(position, lookAt,up);
}

void FlyCamera::update(float deltaTime)
{
	auto glfwWindow = glfwGetCurrentContext();
	bool inputFlag = false;


	glm::vec3  displacement = glm::vec3(0,0,0);


	/* CLASSIC WASD */
	// Forward
	if (glfwGetKey(glfwWindow, GLFW_KEY_W))
	{
		//displacement -= glm::vec3(0,0,1);
		displacement -= glm::vec3(GetWorld(2));
		inputFlag = true;
	}
	// Backward
	if (glfwGetKey(glfwWindow, GLFW_KEY_S))
	{
		//displacement += glm::vec3(0, 0, 1);
		displacement += glm::vec3(GetWorld(2));
		inputFlag = true;
	}
	// Left
	if (glfwGetKey(glfwWindow, GLFW_KEY_A))
	{
		
		displacement -= glm::vec3(GetWorld(0));
		inputFlag = true;
	}
	// Right
	if (glfwGetKey(glfwWindow, GLFW_KEY_D))
	{
		displacement += glm::vec3(GetWorld(0));
		inputFlag = true;
	}
	// Up
	if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_CONTROL))
	{
		displacement -= glm::vec3(0.0f, 1.0f, 0.0f);
		inputFlag = true;
	}
	// Down
	if (glfwGetKey(glfwWindow, GLFW_KEY_SPACE))
	{
		displacement += glm::vec3(0.0f, 1.0f, 0.0f);
		inputFlag = true;
	}

	//If there was input, apply the scaled translation

	if (inputFlag)
	{
		setPosition(GetWorld(3) + (glm::vec4(displacement,0.0f) * speed * deltaTime));

	}


	/* MOUSE LOOK */
	double cursor_position_x;
	double cursor_position_y;
	// Aquire the current cursor position
	glfwGetCursorPos(glfwWindow, &cursor_position_x, &cursor_position_y);
	// TODO - STORE Resolution of the camera

	// Calculate the offset from the screens centre this frame
	double delta_x = cursor_position_x - (1280 * 0.5);
	double delta_y = cursor_position_y - (720 * 0.5);
	// Move the cursor back to the centre of the render / window
	// TODO glfwSetInputMode(window , glfw_cursor_disabled)
	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(glfwWindow, 1280 * 0.5, 720 * 0.5);

	// If either input is non-zero, apply the rotation
	if (delta_x || delta_y)
	{
		// Identity matrix to accumulate rotation
		auto rotation = glm::mat4(1.0f);
		// Left / Right rotation
		rotation = glm::rotate(rotation, float(angularSpeed * deltaTime * -delta_x), glm::vec3(GetView(1)));
		// Up / Down rotation
		rotation = glm::rotate(rotation, float(angularSpeed * deltaTime * -delta_y), glm::vec3(1.0f, 0.0f, 0.0f));

		// Apply the rotation to the camera
		worldTransform = worldTransform * rotation;
		// Preserve the inverse
		viewTransform = glm::inverse(worldTransform);
		// Update PxV
	}

	updateProjectionView();
}

void FlyCamera::SetSpeed(float speed)
{
}

