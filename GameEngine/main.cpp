#include "glm.hpp"
#include "ext.hpp"
#include "gl_core_4_5.h"
#include "glfw3.h"
#include "Shader.h"
#include "FlyCamera.h"
#include "Mesh.h"


int main()
{
	//Initialize hooks to windows.
	if (glfwInit() == false)
		return -1;

	//Create the window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "GameEngine", nullptr, nullptr);

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

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();

	printf("GL: %i.%i\n", major, minor);

	//DO STUFF
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	Mesh* m_pMesh = new Mesh();

	FlyCamera* camera = new FlyCamera(glm::vec3(0,0,1), glm::vec3(0), 16.0f / 9.0f, 3.14159f * 0.25f,  0.01f,  10000000.0f);
	
	
	glm::mat4 model = glm::mat4(1);
	

	m_pMesh->initializeQuad();

	glClearColor(0, 0, 0, 1);



	

	//Shaders
	Shader* shaders = new Shader("vert.shader","colour.shader");

	float currentFrame = glfwGetTime();
	float deltaTime = 0; 
	float lastFrame = 0;



	//Game loop
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glEnable(GL_DEPTH_TEST); //Enables depth buffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//model = glm::rotate(model, 0.01f, glm::vec3(1, 1, 0));
		
		


		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;


	
		camera->update(deltaTime);

		shaders->Update(camera,model);


		m_pMesh->draw();

		

		glfwSwapBuffers(window);

		glfwPollEvents();
;

	}

	

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}