#pragma once
#include <String>
#include <sstream>
#include <fstream>
#include <fstream>
#include "gl_core_4_5.h"
#include "glfw3.h"
#include "glm.hpp"
#include "ext.hpp"
#include <Vector>
#include <iostream>
#include "FlyCamera.h"


class Shader
{
public:
	
	Shader(std::string vertex, std::string fragment);
	unsigned int GetVertexShader();
	unsigned int GetFragmentShader();
	unsigned int GetShaderProgram();

	void Update(FlyCamera* camera, glm::mat4 model);
private:
	void Vertex();
	void Fragment();
	void Link();


	GLint success;

	std::string shaderData;

	//Paths to shaders
	std::stringstream vertexPath;
	std::stringstream fragmentPath;


	std::stringstream vertexStringStream;
	std::stringstream fragStringStream;


	const char* data;


	unsigned int VertexShaderID = 0;
	unsigned int fragmentShaderID = 0;
	unsigned int shaderProgramID = 0;
};

