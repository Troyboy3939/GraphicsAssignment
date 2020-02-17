#pragma once
#include <Vector>
#include "glm.hpp"
#include "ext.hpp"

class Primitives
{
public:

	struct Shape
	{
		std::vector<glm::vec3> m_av3Verts;
		std::vector<unsigned int> m_anIndicies;
	};


	
	Shape GenerateCube();
	Shape GenerateGrid(int nVerticies);
	Shape GeneratePlane(float fX, float fZ);
	Shape GenerateSphere(float fRadius);

	static void Create();
	static void Destroy();
	static Primitives* GetInstance();


private:
	Primitives();


	Shape m_Prim;
	static Primitives* m_pInstance;
};
