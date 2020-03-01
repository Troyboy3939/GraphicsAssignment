#include "Application.h"
#include <iostream>
#include "Primitives.h"


Application::Application()
{
	//Initialize hooks to windows.
	if (glfwInit() == false)
		return;

	m_pWindow = glfwCreateWindow(1280, 720, "GameEngine", nullptr, nullptr);

	//Window stuff initialised


	m_nReturnValue = InitializeWindow();
	if (m_nReturnValue == -1)
	{
		printf("GLFWint() failed");
		return;
	}
	else if (m_nReturnValue == -3)
	{
		printf("ogl_LOAD_FAILED");
		return;
	}
	else if (m_nReturnValue == -2)
	{
		printf("Window pointer was null, window not being created");
		return;
	}
	else
	{

		m_nMajor = ogl_GetMajorVersion();
		m_nMinor = ogl_GetMinorVersion();

		printf("GL: %i.%i\n", m_nMajor, m_nMinor);

		//DeltaTime stuff initialised
		m_fCurrentFrame = glfwGetTime();
		m_fDeltaTime = 0;
		m_fLastFrame = 0;

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Other stuff initialised

		//Primitives must come before game!!!
		Primitives::Create();
		m_pGame = new Game();
		m_pCamera = new FlyCamera(glm::vec3(0, 0, 1), glm::vec3(0), 16.0f / 9.0f, 3.14159f * 0.25f, 0.01f, 10000000.0f);
		//m_pShader = new Shader("vert.shader", "colour.shader");
		m_pShader = new Shader("vert.shader", "colour.shader");

	}


}

Application::~Application()
{
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();

	m_pWindow = nullptr;

	delete m_pGame;
	m_pGame = nullptr;

	delete m_pShader;
	m_pShader = nullptr;

	delete m_pCamera;
	m_pCamera = nullptr;

	Primitives::Destroy();
}

void Application::Update()
{
	m_fCurrentFrame = glfwGetTime();
	m_fDeltaTime = m_fCurrentFrame - m_fLastFrame;
	m_fLastFrame = m_fCurrentFrame;

	m_pGame->Update(m_fDeltaTime);
	m_pCamera->Update(m_fDeltaTime);
	m_pShader->Update(m_pCamera);

}

void Application::Draw()
{
	m_pGame->Draw(m_pShader);
	

	glfwSwapBuffers(m_pWindow);

	glfwPollEvents();
	
}

GLFWwindow* Application::GetWindow()
{
	return m_pWindow;
}

int Application::GetMajor()
{
	return m_nMajor;
}

int Application::GetMinor()
{
	return m_nMinor;
}


int Application::InitializeWindow()
{
	

	//Create the window
	

	if (m_pWindow == nullptr)
	{
		glfwTerminate();

		return -2;
	}

	glfwMakeContextCurrent(m_pWindow);

	//Testing the OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();

		return -3;
	}

	glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

}
