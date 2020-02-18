#pragma once
#include "glm.hpp"
#include "ext.hpp"
#include <Vector>


class Shader;

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	//struct Vertex
	//{
	//	glm::vec4 position;
	//	//glm::vec4 normal;
	//	//glm::vec2 texCoord;
	//};

	void InitializeQuad();
	virtual void Draw(Shader* pShader);
	
	void SetPos(glm::vec3 v3Pos);
	glm::vec3 GetPos();


	void Rotate(float fRadians,glm::vec3 v3Axis);
	glm::mat4 GetRot();

	void Update(float fDeltaTime);

protected:
	glm::mat4 m_m4Model = glm::mat4(1);


	glm::mat4 m_m4Rotation;
	glm::vec3 m_v3Position;



	std::vector<unsigned int> m_anIndex_buffer;
	std::vector<glm::vec3> m_av3Verts;
	unsigned int m_nTriCount;
	unsigned int m_nVao;
	unsigned int m_nVbo;
	unsigned int m_nIbo;


};

