#include "Game.h"
#include "Mesh.h"


Game::Game()
{
	m_pMesh = new Mesh();
	m_pMesh->initializeQuad();
}

Game::~Game()
{
	delete m_pMesh;
	m_pMesh = nullptr;
}

void Game::Update(float deltaTime)
{
}

void Game::Draw()
{
	m_pMesh->draw();
}
