#include "Primitives.h"

//Singleton bullshit
Primitives* Primitives::m_pInstance = nullptr;

Primitives::Primitives()
{
}



Primitives::Shape Primitives::GenerateCube()
{

	m_Prim.m_av3Verts =
	{
		//Cube
			glm::vec3(1 , 1 , -1 ),  //0
			glm::vec3(1 , -1 , -1 ), //1
			glm::vec3(-1 , -1 , -1 ),//2
			glm::vec3(-1 , 1 , -1 ), //3
					   
			glm::vec3(1 , 1 , 1 ),   //4
			glm::vec3(1 , -1 , 1 ),  //5
			glm::vec3(-1 , -1 , 1 ), //6
			glm::vec3(-1 , 1 , 1 ),  //7
	};

	m_Prim.m_anIndicies =
	{
		0, 1, 3,   // front first triangle  
		1, 2, 3,   // front second triangle  
		4, 5, 7,   // back first triangle    
		5, 6, 7,   // back second triangle   
		4, 5, 1,   // right first triangle   
		1, 0, 4,   // right second triangle  
		3, 2, 6,   // left first triangle    
		6, 7, 3,   // left second triangle   
		0, 3, 7,   // top first triangle     
		7, 4, 0,   // top second triangle    
		1, 2, 6,   // bottom first triangle  
		6, 5, 1,    // bottom second triangle


	};
	return m_Prim;
}

Primitives::Shape Primitives::GenerateGrid(int nVerticies)
{
	return Shape();
}

Primitives::Shape Primitives::GeneratePlane(float fX, float fZ)
{
	m_Prim.m_av3Verts =
	{
		glm::vec3(0.0f, 0.0f, 0.0f),  //8
		glm::vec3(100.0f, 0.0f, 0.0f),   //9
		glm::vec3(100.0f, 0.0f, 100.0f), //10
		glm::vec3(0.0f, 0.0f, 100.0f)    //11
	};

	m_Prim.m_anIndicies =
	{
		8, 10, 9,  //floor triangle 1 
		8, 11, 10   //floor triangle 2
	};



	return Shape();
}

Primitives::Shape  Primitives::GenerateSphere(float fRadius)
{
	return Shape();
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

