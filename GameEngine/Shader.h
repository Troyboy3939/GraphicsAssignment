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
#include "Light.h"


class Shader
{
public:

	Shader(std::string vertex, std::string fragment, FlyCamera* pCamera);
	unsigned int GetVertexShader();
	unsigned int GetFragmentShader();
	unsigned int GetShaderProgram();
	FlyCamera* GetCamera();
	void DrawMesh(glm::mat4 m4Model, unsigned int nVAO, int nIndexSize);
	void BindLights();

	void Update();
	glm::vec3 m_v3Ambient;
private:

	void Vertex();
	void Fragment();
	void Link();


	GLint m_nSuccess;

	FlyCamera* m_pCamera;

	
	std::vector<Light*> m_aLights;

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

