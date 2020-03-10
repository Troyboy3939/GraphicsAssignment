#pragma once
#include "glm.hpp"
#include "ext.hpp"
#include "Texture.h"


class Material
{
public:
	Material(glm::vec3 v3Ambient = glm::vec3(1), glm::vec3 v3Diffuse = glm::vec3(1), glm::vec3 v3Specular = glm::vec3(0), float fSpecularPower = 1.0f, glm::vec3 v3Emisive = glm::vec3(1));


	//Get
	glm::vec3 GetDiffuse();
	glm::vec3 GetSpecular();
	glm::vec3 GetEmisive();
	float GetSpecularPower();


	Texture* GetDiffuseTexture();
	Texture* GetSpecularTexture();
	Texture* GetNormalTexture();

	void SetDiffuse(glm::vec3 v3Diffuse);
	void SetSpecular(glm::vec3 v3Specular);
	void SetEmisive(glm::vec3 v3Emisive);
	void SetSpecularPower(float fSpecularPower);

private:
	glm::vec3 m_v3Diffuse;
	glm::vec3 m_v3Specular;
	glm::vec3 m_v3Emisive;

	float m_fSpecularPower;

	Texture* m_pDiffuse;
	Texture* m_pSpecular;
	Texture* m_pNormal;

	
};

