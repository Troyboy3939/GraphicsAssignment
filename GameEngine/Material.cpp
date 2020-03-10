#include "Material.h"

Material::Material (glm::vec3 v3Ambient, glm::vec3 v3Diffuse, glm::vec3 v3Specular, float fSpecularPower, glm::vec3 v3Emisive)
{
	m_v3Diffuse = v3Diffuse;
	m_v3Specular = v3Specular;
	m_v3Emisive = v3Emisive;
	m_fSpecularPower = fSpecularPower;

	m_pDiffuse = new Texture();
	m_pSpecular = new Texture();
	m_pNormal = new Texture();
}


glm::vec3 Material::GetDiffuse()
{
	return m_v3Diffuse;
}

glm::vec3 Material::GetSpecular()
{
	return m_v3Specular;
}

glm::vec3 Material::GetEmisive()
{
	return m_v3Emisive;
}

float Material::GetSpecularPower()
{
	return m_fSpecularPower;
}

Texture* Material::GetDiffuseTexture()
{
	return m_pDiffuse;
}

Texture* Material::GetSpecularTexture()
{
	return m_pSpecular;
}

Texture* Material::GetNormalTexture()
{
	return m_pNormal;
}

void Material::SetDiffuse(glm::vec3 v3Diffuse)
{
	m_v3Diffuse = v3Diffuse;
}

void Material::SetSpecular(glm::vec3 v3Specular)
{
	m_v3Specular = v3Specular;
}

void Material::SetEmisive(glm::vec3 v3Emisive)
{
	m_v3Emisive	 = v3Emisive;
}

void Material::SetSpecularPower(float fSpecularPower)
{
	m_fSpecularPower = fSpecularPower;
}
