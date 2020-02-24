#include "Game.h"
#include "Mesh.h"
#include "Shader.h"


Game::Game()
{

	m_pCube = new Mesh(Mesh::CUBE);
	
	
	

}

Game::~Game()
{


	delete m_pCube;
	m_pCube = nullptr;
}

void Game::Update(float fDeltaTime)
{
	

	m_pCube->Rotate(0.1f * fDeltaTime, glm::vec3(1,1,0));
}


void Game::Draw(Shader* pShader)
{

	m_pCube->Draw(pShader);

}
