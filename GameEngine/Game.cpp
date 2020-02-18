#include "Game.h"
#include "Mesh.h"
#include "OBJMesh.h"
#include "Shader.h"


Game::Game()
{
	m_pMesh = new Mesh();
	
	m_pMesh->InitializeQuad();

	//m_pMesh->Rotate(90,glm::vec3(0,0,1));
	

}

Game::~Game()
{
	delete m_pMesh;
	m_pMesh = nullptr;


}

void Game::Update(float fDeltaTime)
{
	
	m_pMesh->Rotate(0.1  * fDeltaTime, glm::vec3(0, 1, 0));
}


void Game::Draw(Shader* pShader)
{
	m_pMesh->Draw(pShader);
}
