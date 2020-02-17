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

	FlyCamera* m_pCamera;
	Shader* m_pShader;
private:
	int InitializeWindow();


	//Window Stuff
	GLFWwindow* m_pWindow;
	int m_nMajor;
	int m_nMinor;
	int m_nReturnValue;

	//DeltaTime stuff
	float m_fCurrentFrame;
	float m_fDeltaTime;
	float m_fLastFrame;

	//Other stuff
	Game* m_pGame;
};

