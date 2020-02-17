#include "Game.h"
#include "Mesh.h"
#include "OBJMesh.h"
#include "Shader.h"


Game::Game()
{
	m_pMesh = new Mesh();
	m_pMesh->InitializeQuad();
	


	

}

Game::~Game()
{
	delete m_pMesh;
	m_pMesh = nullptr;


}

void Game::Update(float deltaTime)
{
	m_pMesh->SetPos(m_pMesh->GetPos() + (glm::vec3(1,0,0) * deltaTime));
}

void Game::Draw(Shader* pShader)
{
	m_pMesh->Draw(pShader);
}
