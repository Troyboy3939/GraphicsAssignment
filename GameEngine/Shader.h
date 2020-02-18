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
	void Draw(glm::mat4 m4Model, unsigned int nVAO, int nIndexSize);


	void Update(FlyCamera* pCamera);
private:
	void Vertex();
	void Fragment();
	void Link();


	GLint m_nSuccess;

	std::string m_shaderData;

	//Paths to shaders
	std::stringstream m_vertexPath;
	std::stringstream m_fragmentPath;


	std::stringstream m_vertexStringStream;
	std::stringstream m_fragStringStream;


	const char* data;


	unsigned int m_nVertexShaderID = 0;
	unsigned int m_nFragmentShaderID = 0;
	unsigned int m_nShaderProgramID = 0;
};

