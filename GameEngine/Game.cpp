#include "Game.h"
#include "Mesh.h"
#include "Shader.h"


Game::Game()
{
	m_pMesh = new Mesh(1,100,100);
	m_pDragon = new Mesh("..//Models//Dragon.obj",false,false);
	
	
	

}

Game::~Game()
{
	delete m_pMesh;
	m_pMesh = nullptr;

	delete m_pDragon;
	m_pDragon = nullptr;
}

void Game::Update(float fDeltaTime)
{
	
	m_pMesh->Rotate(0.1f  * fDeltaTime, glm::vec3(0, 1, 0));
}


void Game::Draw(Shader* pShader)
{
	m_pMesh->Draw(pShader);
	m_pDragon->Draw(pShader);

}
