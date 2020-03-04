#include "Shader.h"
#include "Camera.h"

Shader::Shader(std::string vertex, std::string fragment, FlyCamera* pCamera)
{
	m_nSuccess = GL_FALSE;

	//Path to where shaders should be found
	std::string path = "..\\Shaders\\";

	
	//add filename to the path
	m_vertexPath << path << vertex;
	m_fragmentPath << path << fragment;
	
	//Set lighting values
	m_Light.m_v3Diffuse = {1,1,0};
	m_Light.m_v3Specular = {1,1,1};
	m_v3AmbientLight = glm::vec3(0.25f);

	//Give Shader class pointer to camera
	m_pCamera = pCamera;


	//Create shaders
	Vertex();
	Fragment();
	Link();
}

unsigned int Shader::GetVertexShader()
{
	return m_nVertexShaderID;
}

unsigned int Shader::GetFragmentShader()
{
	return m_nFragmentShaderID;
}

unsigned int Shader::GetShaderProgram()
{
	return m_nShaderProgramID;
}


void Shader::DrawMesh(glm::mat4 m4Model, unsigned int nVAO, int nIndexSize)
{
	
	glm::vec4 colour = glm::vec4(0.5f);


	//Give Shader PV
	auto uniform_location = glGetUniformLocation(m_nShaderProgramID, "m4PV");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(m_pCamera->GetProjectionView()));

	//float* data = ;
 	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3CameraPos");
	glUniform3fv(uniform_location, 1, glm::value_ptr(glm::vec3(m_pCamera->GetWorld()[3])));


	//LightDirection
	m_Light.m_v3LightDirection = glm::vec3(1, 0, 0);// glm::normalize(glm::vec3(glm::cos(glfwGetTime() * 2), glm::sin(glfwGetTime() * 2), 0));


	//bind light direction
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3LightDirection");
	glUniform3fv(uniform_location, 1, glm::value_ptr(m_Light.m_v3LightDirection));



	//Bind Ambient light to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Ia");
	glUniform3fv(uniform_location, 1, glm::value_ptr(m_v3AmbientLight));

	//Bind Diffuse light to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Id");
	glUniform3fv(uniform_location, 1, glm::value_ptr(m_Light.m_v3Diffuse));

	//Bind Specular light to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Is");
	glUniform3fv(uniform_location, 1, glm::value_ptr(m_Light.m_v3Specular));

	//Bind Specular Power
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "fSpecularPower");
	glUniform1f(uniform_location,32);

	//Bind Ambient Material Colour to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Ka");
	glUniform3fv(uniform_location, 1, glm::value_ptr(glm::vec3(1)));


	//Bind Diffuse Material Colour to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Kd");
	glUniform3fv(uniform_location, 1, glm::value_ptr(glm::vec3(1)));


	//Bind Specular Material Colour to shader
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "v3Ks");
	glUniform3fv(uniform_location, 1, glm::value_ptr(glm::vec3(1)));

	//Give Model Matrix
	  uniform_location = glGetUniformLocation(m_nShaderProgramID, "m4ModelMatrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(m4Model));


	//Give Normal Matrix
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "m3NormalMatrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(glm::inverseTranspose(glm::mat3(m4Model))));

	//Bind verts
	glBindVertexArray(nVAO);

	//Draw verts
	glDrawElements(GL_TRIANGLES,nIndexSize , GL_UNSIGNED_INT, 0);
}

void Shader::Update()
{


	glUseProgram(m_nShaderProgramID);



}

void Shader::Vertex()
{

	std::ifstream inFileStream(m_vertexPath.str(),std::ifstream::in);

	//std::ofstream testOutput()

	if (inFileStream.is_open())
	{
		m_vertexStringStream << inFileStream.rdbuf();
		m_shaderData = m_vertexStringStream.str();
		inFileStream.close();
	}
	else
	{
		printf("Vertex Shader not found, place in Shaders folder");
	}


	m_nVertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	data = m_shaderData.c_str();

	glShaderSource(m_nVertexShaderID, 1, (const GLchar**)&data, 0);
	glCompileShader(m_nVertexShaderID);

	m_nSuccess = GL_FALSE;
	glGetShaderiv(m_nVertexShaderID, GL_COMPILE_STATUS, &m_nSuccess);

	if (m_nSuccess == GL_FALSE)
	{
		printf("Vertex Shader Failed");

		GLint maxlength = 0;

		glGetShaderiv(m_nVertexShaderID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetShaderInfoLog(m_nVertexShaderID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}
	}


}

void Shader::Fragment()
{

	std::ifstream inFileStream(m_fragmentPath.str(), std::ifstream::in);


	if (inFileStream.is_open())
	{
		m_fragStringStream << inFileStream.rdbuf();
		m_shaderData = m_fragStringStream.str();
		inFileStream.close();
	}
	else
	{
		printf("Fragment Shader not found, place in Shaders folder");
	}


	m_nFragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	 data = m_shaderData.c_str();

	glShaderSource(m_nFragmentShaderID, 1, (const GLchar**)&data, 0);
	glCompileShader(m_nFragmentShaderID);

	m_nSuccess = GL_FALSE;

	glGetShaderiv(m_nFragmentShaderID, GL_COMPILE_STATUS, &m_nSuccess);

	if (m_nSuccess == GL_FALSE)
	{
		printf("Vertex Shader Failed");

		GLint maxlength = 0;

		glGetShaderiv(m_nFragmentShaderID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetShaderInfoLog(m_nFragmentShaderID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}
	}

}

void Shader::Link()
{
	m_nShaderProgramID = glCreateProgram();

	glAttachShader(m_nShaderProgramID, m_nVertexShaderID);
	glAttachShader(m_nShaderProgramID, m_nFragmentShaderID);

	glLinkProgram(m_nShaderProgramID);


	m_nSuccess = GL_FALSE;

	glGetProgramiv(m_nShaderProgramID, GL_LINK_STATUS, &m_nSuccess);

	if (m_nSuccess == GL_FALSE)
	{
		printf("Suprise! Your shader is fucked lol");
		std::cout << std::endl;

		GLint maxlength = 0;

		glGetProgramiv(m_nShaderProgramID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetProgramInfoLog(m_nShaderProgramID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}

		std::cout << std::endl;
	}
}
