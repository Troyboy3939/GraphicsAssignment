#pragma once
#include "gl_core_4_5.h"


class Texture
{
public:
	Texture();
	unsigned char* GetData();
	const char* GetPath();
	unsigned int GetHandle();
	GLenum GetID();
	
	void Load(const char* szFileName, bool bFlipV);
private: 
	unsigned char* m_szData;
	const char* m_szPath;
	unsigned int m_nTextureHandle;
	int m_nX;
	int m_nY;
	int m_nN;
	GLenum m_eID;
	static GLenum m_eAmount;
};

