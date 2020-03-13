#include "Texture.h"
#include <sstream>



//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLenum Texture::m_eAmount = GL_TEXTURE0;

Texture::Texture(GLenum eID)
{
	m_eID = eID;
	
}

unsigned char* Texture::GetData()
{
	return m_szData;
}

const char* Texture::GetPath()
{
	return m_szPath.c_str();
}

unsigned int Texture::GetHandle()
{
	return m_nTextureHandle;
}

GLenum Texture::GetID()
{
	return m_eID;
}

void Texture::Load(std::string szFileName, bool bFlipV)
{
	std::string szFolder = "../Textures/";
	std::stringstream ss;
	ss << szFolder << szFileName;
	m_szPath = ss.str();

	auto a = m_eID;
	
	const char* c = m_szPath.c_str();

	glGenTextures(1, &m_nTextureHandle);
	glBindTexture(GL_TEXTURE_2D, m_nTextureHandle);
	stbi_set_flip_vertically_on_load(bFlipV);
	m_szData = stbi_load(c, &m_nX, &m_nY, &m_nN, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_nX, m_nY, 0, GL_RGB, GL_UNSIGNED_BYTE, m_szData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	stbi_image_free(m_szData);
}
