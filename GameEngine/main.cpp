#include "glm.hpp"
#include "ext.hpp"
#include "gl_core_4_5.h"
#include "glfw3.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

void Printm4(glm::mat4 value)
{
	float* data = glm::value_ptr(value);
	for (int i = 0; i < 16; ++i) {
		if (i != 0 && (i % 4) == 0)printf("\n");
		printf("%.2f ", data[i]);
	}
	printf("\n"); printf("\n"); printf("\n");
}


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
	

	glm::vec3 verticies[] =
	{
		//Plane 1
		glm::vec3(0.1f, 0.1f, -0.1f),  
		glm::vec3(0.1f, -0.1f, -0.1f), 
		glm::vec3(-0.1f, -0.1f, -0.1f),
		glm::vec3(-0.1f, 0.1f, -0.1f), 

		//Plane 2
		glm::vec3(0.1f, 0.1f, 0.1f),   
		glm::vec3(0.1f, -0.1f, 0.1f),	
		glm::vec3(-0.1f, -0.1f, 0.1f),	
		glm::vec3(-0.1f, 0.1f, 0.1f),	
	};

	unsigned int index_buffer[] = {
		0, 1, 3,   // front first triangle        
		1, 2, 3,   // front second triangle          
		4, 5, 7,   // back first triangle         
		5, 6, 7,   // back second triangle         
		4, 5, 1,   // right first triangle        
		1, 0, 4,   // right second triangle         
		3, 2, 6,   // left first triangle        
		6, 7, 3,   // left second triangle         
		0, 3, 7,   // top first triangle        
		7, 4, 0,   // top second triangle         
		1, 2, 6,   // bottom first triangle        
		6, 5, 1    // bottom second triangle    
	};


	
	glm::mat4 projection = glm::perspective(1.507f, 16 / 9.0f, 0.5f, 5.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 model = glm::mat4(1);


	unsigned int VAO;
	unsigned int VBO;
	UINT IBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);



	glClearColor(0, 0, 0, 1);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_buffer), index_buffer, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	unsigned int VertexShaderID = 0;
	unsigned int fragmentShaderID = 0;
	unsigned int shaderProgramID = 0;

	//---------------------------------------------------------------------------------------------------
	//Vertex Shader
	//---------------------------------------------------------------------------------------------------


	std::string shader_data;
	std::ifstream in_file_stream("..\\Shaders\\vert.shader",std::ifstream::in);


	std::stringstream string_stream;
	if (in_file_stream.is_open())
	{
		string_stream << in_file_stream.rdbuf();
		shader_data = string_stream.str();
		in_file_stream.close(); 
	}

	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* data = shader_data.c_str();

	glShaderSource(VertexShaderID,1,(const GLchar**)&data,0);
	glCompileShader(VertexShaderID);

	GLint success = GL_FALSE;
	glGetShaderiv(VertexShaderID,GL_COMPILE_STATUS,&success);
	
	if (success == GL_FALSE)
	{
		printf("Vertex Shader Failed");
		
		GLint maxlength = 0;

		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetShaderInfoLog(VertexShaderID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}
	}


	//---------------------------------------------------------------------------------------------------
	//Fragment Shader
	//---------------------------------------------------------------------------------------------------


	std::ifstream inFileStreamFrag("..\\Shaders\\colour.shader",std::ifstream::in);
	std::stringstream fragStringStream;

	if (inFileStreamFrag.is_open())
	{
		fragStringStream << inFileStreamFrag.rdbuf();
		shader_data = fragStringStream.str();
		inFileStreamFrag.close();
	}

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	data = shader_data.c_str();

	glShaderSource(fragmentShaderID, 1, (const GLchar**)&data, 0);
	glCompileShader(fragmentShaderID);

	success = GL_FALSE;
	glGetShaderiv(fragmentShaderID,GL_COMPILE_STATUS,&success);




	if (success == GL_FALSE)
	{
		printf("Fragment Shader Failed");
		GLint maxlength = 0;

		glGetShaderiv(fragmentShaderID,GL_INFO_LOG_LENGTH,&maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetShaderInfoLog(fragmentShaderID,maxlength,NULL,&errorlog[0]);

		for (int i =0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}
	}

	//---------------------------------------------------------------------------------------------------
	// Shader Linking
	//---------------------------------------------------------------------------------------------------


	shaderProgramID = glCreateProgram();

	glAttachShader(shaderProgramID,VertexShaderID);
	glAttachShader(shaderProgramID,fragmentShaderID);

	glLinkProgram(shaderProgramID);
	

	success = GL_FALSE;

	glGetProgramiv(shaderProgramID,GL_LINK_STATUS,&success);

	if (!success)
	{
		printf("Suprise! Your shader is fucked lol");
		std::cout << std::endl;

		GLint maxlength = 0;

		glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetProgramInfoLog(shaderProgramID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}

		std::cout << std::endl;
	}



	//Keeps the window open until the escape key is pressed.
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glEnable(GL_DEPTH_TEST); //Enables depth buffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model = glm::rotate(model, 0.01f, glm::vec3(1, 1, 0));

		glm::mat4 pv = projection * view ;

		glm::vec4 color = glm::vec4(0.5f);

		glUseProgram(shaderProgramID);
		auto uniform_location = glGetUniformLocation(shaderProgramID,"projection_view_matrix");
		glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(pv));
		uniform_location = glGetUniformLocation(shaderProgramID, "model_matrix");
		glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(model));
		uniform_location = glGetUniformLocation(shaderProgramID, "color");
		glUniform4fv(uniform_location, 1, glm::value_ptr(color));
		


		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);

		glfwSwapBuffers(window);

		glfwPollEvents();
;

	}

	glDeleteBuffers(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}