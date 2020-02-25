#include "Primitives.h"

//Singleton bullshit
Primitives* Primitives::m_pInstance = nullptr;

Primitives::Primitives()
{
	m_Prim = new Shape();
}

Primitives::~Primitives()
{
	delete m_Prim;
	m_Prim = nullptr;
}

void Primitives::ClearPrim()
{
	m_Prim->m_anIndicies.clear();
	m_Prim->m_av3Verts.clear();
}



Primitives::Shape Primitives::GenerateCube()
{
	ClearPrim();

	//Old Cube with 8 verts
	//m_Prim->m_av3Verts =
	//{
	//	//Cube
	//		glm::vec3(1 , 1 , -1 ),  //0
	//		glm::vec3(1 , -1 , -1 ), //1
	//		glm::vec3(-1 , -1 , -1 ),//2
	//		glm::vec3(-1 , 1 , -1 ), //3
	//				   
	//		glm::vec3(1 , 1 , 1 ),   //4
	//		glm::vec3(1 , -1 , 1 ),  //5
	//		glm::vec3(-1 , -1 , 1 ), //6
	//		glm::vec3(-1 , 1 , 1 ),  //7
	//};


	//No Indicies anymore
	//m_Prim->m_anIndicies =
	//{
	//	0, 1, 3,   // front first triangle  
	//	1, 2, 3,   // front second triangle  

	//	4, 5, 7,   // back first triangle    
	//	5, 6, 7,   // back second triangle   

	//	4, 5, 1,   // right first triangle   
	//	1, 0, 4,   // right second triangle  

	//	3, 2, 6,   // left first triangle    
	//	6, 7, 3,   // left second triangle   

	//	0, 3, 7,   // top first triangle     
	//	7, 4, 0,   // top second triangle    

	//	1, 2, 6,   // bottom first triangle  
	//	6, 5, 1,    // bottom second triangle


	//};

	m_Prim->m_av3Verts =
	{
		//Front Face
		Vertex{glm::vec4(-0.5f,-0.5f,-0.5f,1) ,glm::vec4(0,0,-1,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) }, //BL
		Vertex{glm::vec4(-0.5f,0.5f,-0.5f,1) ,glm::vec4(0,0,-1,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) }, //TL
		Vertex{glm::vec4(0.5f,0.5f,-0.5f,1) ,glm::vec4(0,0,-1,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) }, //TR
		Vertex{glm::vec4(0.5f,-0.5f,-0.5f,1) ,glm::vec4(0,0,-1,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) }, //BR

		//Back Face
		Vertex{glm::vec4(-0.5f,-0.5f,0.5f,1) ,glm::vec4(0,0,1,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,0.5f,0.5f,1) ,glm::vec4(0,0,1,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,0.5f,0.5f,1) ,glm::vec4(0,0,1,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,-0.5f,0.5f,1) ,glm::vec4(0,0,1,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) },

		//Left Face
		Vertex{glm::vec4(-0.5f,-0.5f,-0.5f,1) ,glm::vec4(-1,0,0,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,0.5f,-0.5f,1) ,glm::vec4(-1,0,0,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,0.5f,0.5f,1) ,glm::vec4(-1,0,0,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,-0.5f,0.5f,1) ,glm::vec4(-1,0,0,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) },

		//Right Face
		Vertex{glm::vec4(0.5f,-0.5f,-0.5f,1) ,glm::vec4(1,0,0,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,0.5f,-0.5f,1) ,glm::vec4(1,0,0,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,0.5f,0.5f,1) ,glm::vec4(1,0,0,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,-0.5f,0.5f,1) ,glm::vec4(1,0,0,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) },

		//Top Face
		Vertex{glm::vec4(-0.5f,0.5f,-0.5f,1) ,glm::vec4(0,1,0,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,0.5f,0.5f,1) ,glm::vec4(0,1,0,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,0.5f,0.5f,1) ,glm::vec4(0,1,0,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,0.5f,-0.5f,1) ,glm::vec4(0,1,0,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) },

		Vertex{glm::vec4(-0.5f,-0.5f,-0.5f,1) ,glm::vec4(0,-1,0,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(-0.5f,-0.5f,0.5f,1) ,glm::vec4(0,-1,0,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,-0.5f,0.5f,1) ,glm::vec4(0,-1,0,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{glm::vec4(0.5f,-0.5f,-0.5f,1) ,glm::vec4(0,-1,0,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) }

	};


	m_Prim->m_anIndicies =
	{
		//Front
		0,1,2,
		2,3,0,

		//Back
		4,5,6,
		6,7,4,

		//left
		8,9,10,
		10,11,8,

		//right
		12,13,14,
		14,15,12,

		//top
		16,17,18,
		18,19,16,

		//bottom
		20,21,22,
		22,23,20,


	};


	return *m_Prim;
}

Primitives::Shape Primitives::GenerateGrid(int nVerticies)
{
	ClearPrim();

	//Generate Grid



	return Shape();
}

Primitives::Shape Primitives::GeneratePlane()
{
	ClearPrim();
	m_Prim->m_av3Verts =
	{
		Vertex{ glm::vec4(0.0f, 0.0f, 0.0f,1) ,glm::vec4(0,0,0,1) ,glm::vec2(0,0),glm::vec4(0,0,0,1) },
		Vertex{ glm::vec4(1.0f, 0.0f, 0.0f,1) ,glm::vec4(0,0,0,1) ,glm::vec2(0,1),glm::vec4(0,0,0,1) },
		Vertex{ glm::vec4(1.0f, 0.0f, 1.0f,1) ,glm::vec4(0,0,0,1) ,glm::vec2(1,0),glm::vec4(0,0,0,1) },
		Vertex{ glm::vec4(0.0f, 0.0f, 1.0f,1) ,glm::vec4(0,0,0,1) ,glm::vec2(1,1),glm::vec4(0,0,0,1) }
	};


	return *m_Prim;
}

Primitives::Shape  Primitives::GenerateSphere(float fRadius, int nSectors, int nStacks)
{

	ClearPrim();

	float fPI = 3.14159265359f;


	float fX,fY,fZ,fXy;										//Vertex position
	float fNx, fNy, fNz, fLengthInv = 1.0f / fRadius;		//vertex normal
	float fS, fT;											//vertex texCoord

	float fSectorStep = 2 * fPI / nSectors;
	float fStackStep = fPI / nStacks;
	float fSectorAngle, fStackAngle;

	//Generate Vertex positions, normal position and texCoord
	for (int i = 0; i <= nStacks; i++)
	{
		fStackAngle = fPI / 2 - i * fStackStep; // Starting from pi / 2 to -pi/2
		fXy = fRadius * cosf(fStackAngle); //r * cos(u)
		fZ = fRadius * sinf(fStackAngle);//r * sin(u)

		for (int j = 0; j <= nSectors; j++)
		{
			fSectorAngle = j * fSectorStep;

			//Vertex Position (x,y,z)
			fX = fXy * cosf(fSectorAngle);
			fY = fXy * sinf(fSectorAngle);
			
			//Normalised Vertex normal (nx,ny,nz)

			fNx = fX * fLengthInv;
			fNy = fY * fLengthInv;
			fNz = fZ * fLengthInv;
			//Add normals to array here



			//Vertex tex coord
			fS = (float)j / nSectors;
			fT = (float)i / nStacks;
			//Add st to array
			m_Prim->m_av3Verts.push_back(Vertex{ glm::vec4(fX, fY, fZ,1) ,glm::vec4(fNx,fNy,fNz,1) ,glm::vec2(fS,fT),glm::vec4(0,0,0,1) });
		}
	}


	int nK1, nK2;
	//Generate Indicies
	for (int i = 0; i < nSectors; i++)
	{
		nK1 = i * (nSectors + 1);
		nK2 = nK1 + nSectors + 1;

		for (int j = 0; j < nSectors; j++, nK1++, nK2++)
		{
			if (i != 0)
			{
				m_Prim->m_anIndicies.push_back(nK1);
				m_Prim->m_anIndicies.push_back(nK2);
				m_Prim->m_anIndicies.push_back(nK1 + 1);
			}

			if (i != (nStacks - 1))
			{
				m_Prim->m_anIndicies.push_back(nK1 + 1);
				m_Prim->m_anIndicies.push_back(nK2);
				m_Prim->m_anIndicies.push_back(nK2 + 1);
			}
		}
	}
	
	return *m_Prim;
}

void Primitives::Create()
{
	m_pInstance = new Primitives();
}

void Primitives::Destroy()
{
	

	delete m_pInstance;
	m_pInstance = nullptr;


}

Primitives* Primitives::GetInstance()
{
	return m_pInstance;
}

