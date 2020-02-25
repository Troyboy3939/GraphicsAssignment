#pragma once
#include <Vector>
#include "glm.hpp"
#include "ext.hpp"

class Primitives
{
public:

	struct Vertex
	{
		glm::vec4 m_v4Position;
		glm::vec4 m_v4Normal;
		glm::vec2 m_v2TexCoord;
		glm::vec4 m_v4Tangent;
	};

	struct Shape
	{
		std::vector<Primitives::Vertex> m_av3Verts;
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
