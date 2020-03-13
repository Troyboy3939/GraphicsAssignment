#pragma once
#include "gl_core_4_5.h"
#include <string>

class Texture
{
public:
	Texture(GLenum eID);
	unsigned char* GetData();
	const char* GetPath();
	unsigned int GetHandle();
	GLenum GetID();
	
	void Load(std::string szFileName, bool bFlipV);
private: 
	unsigned char* m_szData;
	std::string m_szPath;
	unsigned int m_nTextureHandle;
	int m_nX;
	int m_nY;
	int m_nN;
	GLenum m_eID;
	static GLenum m_eAmount;
};

