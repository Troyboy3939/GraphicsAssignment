#pragma once
#include "gl_core_4_5.h"
#include "glfw3.h"
#include "Shader.h"
#include "glm.hpp"
#include "ext.hpp"
#include "FlyCamera.h"
#include "Game.h"


class Application
{
public:
	Application();
	~Application();
	void Update();
	void Draw();
	GLFWwindow* GetWindow();
	int GetMajor();
	int GetMinor();

private:
	int InitializeWindow();


	//Window Stuff
	GLFWwindow* window;
	int major;
	int minor;
	int returnValue;

	//DeltaTime stuff
	float currentFrame;
	float deltaTime;
	float lastFrame;

	//Other stuff
	Shader* m_pShader;
	FlyCamera* m_pCamera;
	Game* m_pGame;
	glm::mat4 model;
};

