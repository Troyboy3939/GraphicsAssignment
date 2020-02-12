#include "Application.h"
#include <iostream>



Application::Application()
{
	//Initialize hooks to windows.
	if (glfwInit() == false)
		return;

	window = glfwCreateWindow(1280, 720, "GameEngine", nullptr, nullptr);

	//Window stuff initialised


	returnValue = InitializeWindow();
	if (returnValue == -1)
	{
		printf("GLFWint() failed");
		return;
	}
	else if (returnValue == -3)
	{
		printf("ogl_LOAD_FAILED");
		return;
	}
	else if (returnValue == -2)
	{
		printf("Window pointer was null, window not being created");
		return;
	}
	else
	{

		major = ogl_GetMajorVersion();
		minor = ogl_GetMinorVersion();

		printf("GL: %i.%i\n", major, minor);

		//DeltaTime stuff initialised
		currentFrame = glfwGetTime();
		deltaTime = 0;
		lastFrame = 0;


		//Other stuff initialised
		m_pGame = new Game();
		m_pCamera = new FlyCamera(glm::vec3(0, 0, 1), glm::vec3(0), 16.0f / 9.0f, 3.14159f * 0.25f, 0.01f, 10000000.0f);
		m_pShader = new Shader("vert.shader", "colour.shader");
		model = glm::mat4(1);

	}


}

Application::~Application()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	window = nullptr;

	delete m_pGame;
	m_pGame = nullptr;

	delete m_pShader;
	m_pShader = nullptr;

	delete m_pCamera;
	m_pCamera = nullptr;
}

void Application::Update()
{
	currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	m_pGame->Update(deltaTime);
	m_pCamera->update(deltaTime);
	m_pShader->Update(m_pCamera,model);

}

void Application::Draw()
{
	m_pGame->Draw();

	glfwSwapBuffers(window);

	glfwPollEvents();
	
}

GLFWwindow* Application::GetWindow()
{
	return window;
}

int Application::GetMajor()
{
	return major;
}

int Application::GetMinor()
{
	return minor;
}


int Application::InitializeWindow()
{
	

	//Create the window
	

	if (window == nullptr)
	{
		glfwTerminate();

		return -2;
	}

	glfwMakeContextCurrent(window);

	//Testing the OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();

		return -3;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

}
