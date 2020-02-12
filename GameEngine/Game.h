#pragma once

class Mesh;

class Game
{
public:
	Game();
	~Game();
	void Update(float deltaTime);
	void Draw();
private:
	
	
	Mesh* m_pMesh;

};

