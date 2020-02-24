#pragma once
class Mesh;
class Shader;

class Game
{
public:
	Game();
	~Game();
	void Update(float deltaTime);
	void Draw(Shader* pShader);
private:

	Mesh* m_pCube;
};

