#include "Shader.h"
#include "Camera.h"

Shader::Shader(std::string vertex, std::string fragment)
{
	m_nSuccess = GL_FALSE;

	//Path to where shaders should be found
	std::string path = "..\\Shaders\\";

	
	//add filename to the path
	m_vertexPath << path << vertex;
	m_fragmentPath << path << fragment;
	


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

void Shader::Draw(glm::mat4 m4Model, unsigned int nVAO, int nIndexSize)
{
	auto uniform_location = glGetUniformLocation(m_nShaderProgramID, "m4ModelMatrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(m4Model));

	glBindVertexArray(nVAO);
	glDrawElements(GL_TRIANGLES,nIndexSize , GL_UNSIGNED_INT, 0);
}

void Shader::Update(FlyCamera* pCamera)
{
	glm::vec4 color = glm::vec4(0.5f);

	glUseProgram(m_nShaderProgramID);
	auto uniform_location = glGetUniformLocation(m_nShaderProgramID, "m4PVM");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(pCamera->GetProjectionView()));
	/*uniform_location = glGetUniformLocation(m_nShaderProgramID, "model_matrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(m4Model));*/
	uniform_location = glGetUniformLocation(m_nShaderProgramID, "color");
	glUniform4fv(uniform_location, 1, glm::value_ptr(color));

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
