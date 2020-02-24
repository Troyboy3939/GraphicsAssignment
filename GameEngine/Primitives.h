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
		std::vector<glm::vec2> m_av2TexCoord;
	};


	struct Vertex
	{
		glm::vec4 m_v4Position;
		glm::vec4 m_v4Normal;
		glm::vec2 m_v2TexCoord;
		glm::vec4 m_v4Tangent;
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
	std::vector<Vertex> m_Shape;
	static Primitives* m_pInstance;
};
