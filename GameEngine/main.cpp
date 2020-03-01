#include "Application.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_pApplication = new Application();

	glClearColor(1, 1, 1, 1);

	//Game loop
	while (glfwWindowShouldClose(m_pApplication->GetWindow()) == false && glfwGetKey(m_pApplication->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glEnable(GL_DEPTH_TEST); //Enables depth buffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_pApplication->Update();
		m_pApplication->Draw();
	}
	delete m_pApplication;
	m_pApplication = nullptr;

	return 0;
}