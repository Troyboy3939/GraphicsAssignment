#include "Game.h"
#include "Mesh.h"
#include "Shader.h"


Game::Game()
{

	m_pDragon = new Mesh("..\\Models\\Dragon.obj",false,false);
	m_pBunny = new Mesh("..\\Models\\Bunny.obj",false,false);
	
	
	m_pBunny->SetPos( (glm::vec3(0,10,0) ));

}

Game::~Game()
{


	delete m_pDragon;
	m_pDragon = nullptr;

	delete m_pBunny;
	m_pBunny = nullptr;
}

void Game::Update(float fDeltaTime)
{
	

	m_pDragon->Rotate(0.5f * fDeltaTime, glm::vec3(0,1,0));

}


void Game::Draw(Shader* pShader)
{

	m_pDragon->Draw(pShader);
	m_pBunny->Draw(pShader);

}
