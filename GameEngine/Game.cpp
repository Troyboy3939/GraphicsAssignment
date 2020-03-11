#include "Game.h"
#include "Mesh.h"
#include "Shader.h"


Game::Game()
{

	m_pDragon = new Mesh("..\\Models\\meshSwordShield.obj",false,false);
	
	

}

Game::~Game()
{


	delete m_pDragon;
	m_pDragon = nullptr;


}

void Game::Update(float fDeltaTime)
{
	

	m_pDragon->Rotate(0.5f * fDeltaTime, glm::vec3(0,1,0));

}


void Game::Draw(Shader* pShader)
{

	m_pDragon->Draw(pShader);

}
