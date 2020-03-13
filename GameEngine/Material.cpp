#include "Material.h"

Material::Material (GLenum eID, glm::vec3 v3Ambient, glm::vec3 v3Diffuse, glm::vec3 v3Specular, float fSpecularPower, glm::vec3 v3Emisive)
{
	m_v3Ambient = v3Ambient;
	m_v3Diffuse = v3Diffuse;
	m_v3Specular = v3Specular;
	m_v3Emisive = v3Emisive;
	m_fSpecularPower = fSpecularPower;

	m_pDiffuse = new Texture(eID);
	m_pSpecular = nullptr;
	m_pNormal = new Texture(eID + 1);
}


glm::vec3 Material::GetAmbient()
{
	return m_v3Ambient;
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

void Material::SetAmbient(glm::vec3 v3Ambient)
{
	m_v3Ambient = v3Ambient;
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
