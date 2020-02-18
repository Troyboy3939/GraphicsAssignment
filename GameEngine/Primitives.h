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
	Shape GeneratePlane();
	Shape GenerateSphere(float fRadius, int nSectors, int nStacks);

	static void Create();
	static void Destroy();
	static Primitives* GetInstance();


private:
	Primitives();
	~Primitives();
	void ClearPrim();

	Shape* m_Prim;
	static Primitives* m_pInstance;
};
