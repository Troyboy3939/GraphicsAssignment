#include "Light.h"
#include <String>




Light::Light(glm::vec3 v3Dir, glm::vec3 v3Diffuse, glm::vec3 v3Specular)
{
	m_v3LightDirection = v3Dir;
	m_v3Diffuse = v3Diffuse;
	m_v3Specular = v3Specular;
}

glm::vec3 Light::GetDirection()
{
	return m_v3LightDirection;
}

glm::vec3 Light::GetDiffuseColour()
{
	return m_v3Diffuse;
}

glm::vec3 Light::GetSpecularColour()
{
	return m_v3Specular;
}

void Light::SetDirection(glm::vec3 v3Dir)
{
	m_v3LightDirection = v3Dir;
}

void Light::SetDiffuse(glm::vec3 v3Diffuse)
{
	m_v3Diffuse = v3Diffuse;
}

void Light::SetSpecular(glm::vec3 v3Specular)
{
	m_v3Specular = v3Specular;
}

void Light::BindUniforms(unsigned int nProgramId, unsigned int nLightNumber)
{

	std::string ArrayName = "aLights[";
	ArrayName += std::to_string(nLightNumber);
	ArrayName += "]";

	//Diffuse
	auto nUniformLocation = glGetUniformLocation(nProgramId, (ArrayName + ".v3Id").c_str());
	glUniform3fv(nUniformLocation,1,glm::value_ptr(m_v3Diffuse));

	//Specular
	nUniformLocation = glGetUniformLocation(nProgramId, (ArrayName + ".v3Is").c_str());
	glUniform3fv(nUniformLocation, 1, glm::value_ptr(m_v3Specular));

	//LightDirection
	nUniformLocation = glGetUniformLocation(nProgramId, (ArrayName + ".v3LightDirection").c_str());
	glUniform3fv(nUniformLocation, 1, glm::value_ptr(m_v3LightDirection));

}
