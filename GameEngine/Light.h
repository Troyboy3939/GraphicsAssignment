#pragma once
#include "glm.hpp"
#include "ext.hpp"
#include "gl_core_4_5.h"


class Light
{
public:
	Light(glm::vec3 v3Dir, glm::vec3 v3Diffuse, glm::vec3 v3Specular);

	//Get
	glm::vec3 GetDirection();
	glm::vec3 GetDiffuseColour();
	glm::vec3 GetSpecularColour();


	//Set
	void SetDirection(glm::vec3 v3Dir);
	void SetDiffuse(glm::vec3 v3Diffuse);
	void SetSpecular(glm::vec3 v3Specular);


	//Bind Light Uniforms
	void BindUniforms(unsigned int nProgramId, unsigned int nLightNumber);


private:

	glm::vec3 m_v3LightDirection;
	glm::vec3 m_v3Diffuse;
	glm::vec3 m_v3Specular;
};

