#include "Shader.h"
#include "Camera.h"

Shader::Shader(std::string vertex, std::string fragment)
{
	success = GL_FALSE;

	//Path to where shaders should be found
	std::string path = "..\\Shaders\\";

	
	//add filename to the path
	vertexPath << path << vertex;
	fragmentPath << path << fragment;
	


	//Create shaders
	Vertex();
	Fragment();
	Link();
}

unsigned int Shader::GetVertexShader()
{
	return VertexShaderID;
}

unsigned int Shader::GetFragmentShader()
{
	return fragmentShaderID;
}

unsigned int Shader::GetShaderProgram()
{
	return shaderProgramID;
}

void Shader::Update(Camera* camera, glm::mat4 model)
{
	glm::vec4 color = glm::vec4(0.5f);

	glUseProgram(shaderProgramID);
	auto uniform_location = glGetUniformLocation(shaderProgramID, "projection_view_matrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(camera->GetProjectionView()));
	uniform_location = glGetUniformLocation(shaderProgramID, "model_matrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(model));
	uniform_location = glGetUniformLocation(shaderProgramID, "color");
	glUniform4fv(uniform_location, 1, glm::value_ptr(color));



	
}

void Shader::Vertex()
{

	std::ifstream inFileStream(vertexPath.str(),std::ifstream::in);

	//std::ofstream testOutput()

	if (inFileStream.is_open())
	{
		vertexStringStream << inFileStream.rdbuf();
		shaderData = vertexStringStream.str();
		inFileStream.close();
	}
	else
	{
		printf("Vertex Shader not found, place in Shaders folder");
	}


	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	data = shaderData.c_str();

	glShaderSource(VertexShaderID, 1, (const GLchar**)&data, 0);
	glCompileShader(VertexShaderID);

	success = GL_FALSE;
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &success);

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


}

void Shader::Fragment()
{

	std::ifstream inFileStream(fragmentPath.str(), std::ifstream::in);


	if (inFileStream.is_open())
	{
		fragStringStream << inFileStream.rdbuf();
		shaderData = fragStringStream.str();
		inFileStream.close();
	}
	else
	{
		printf("Fragment Shader not found, place in Shaders folder");
	}


	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	 data = shaderData.c_str();

	glShaderSource(fragmentShaderID, 1, (const GLchar**)&data, 0);
	glCompileShader(fragmentShaderID);

	success = GL_FALSE;

	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		printf("Vertex Shader Failed");

		GLint maxlength = 0;

		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector<GLchar> errorlog(maxlength);

		glGetShaderInfoLog(fragmentShaderID, maxlength, NULL, &errorlog[0]);

		for (int i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i];
		}
	}

}

void Shader::Link()
{
	shaderProgramID = glCreateProgram();

	glAttachShader(shaderProgramID, VertexShaderID);
	glAttachShader(shaderProgramID, fragmentShaderID);

	glLinkProgram(shaderProgramID);


	success = GL_FALSE;

	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);

	if (success == GL_FALSE)
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
}
