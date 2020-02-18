#include "Mesh.h"
#include "gl_core_4_5.h"
#include <vector>
#include "Shader.h"
#include "Primitives.h"


Mesh::Mesh()
{
	m_nTriCount = 0;
	m_nVao = 0;
	m_nVbo = 0;
	m_nIbo = 0;


	m_m4Rotation = glm::mat4(1);
	m_v3Position = glm::vec3(0);
	glGenBuffers(1, &m_nVbo);
	glGenVertexArrays(1, &m_nVao);
	glGenBuffers(1, &m_nIbo);



	
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_nVao);
	glDeleteBuffers(1, &m_nVbo);
	glDeleteBuffers(1, &m_nIbo);
}

void Mesh::InitializeQuad()
{
	//check that the mesh is already initialized
	//assert(vao == 0);
	
	Primitives::Shape shape = Primitives::GetInstance()->GenerateSphere(1,100,100);
	m_av3Verts = shape.m_av3Verts;
	m_anIndex_buffer = shape.m_anIndicies;

	////generate buffers
	//glGenBuffers(1,&vbo);
	//glGenVertexArrays(1, &vao);
	//glGenBuffers(1,&ibo);


	//glClearColor(0,0,0,1);

	//bind
	glBindVertexArray(m_nVao);
	glBindBuffer(GL_ARRAY_BUFFER, m_nVbo);
 	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_av3Verts.size(), m_av3Verts.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_nIbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_anIndex_buffer.size(), m_anIndex_buffer.data(), GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	m_nTriCount = shape.m_anIndicies.size() / 3;
	
	

}

void Mesh::Draw(Shader* pShader)
{
	pShader->Draw(m_m4Model,m_nVao,m_anIndex_buffer.size());
}

void Mesh::SetPos(glm::vec3 v3Pos)
{
	m_m4Model[3] = glm::vec4(v3Pos,1);
}

glm::vec3 Mesh::GetPos()
{
	return m_m4Model[3];
}

void Mesh::Rotate(float fRadians,glm::vec3 v3Axis)
{
	//Get Rotation
	m_m4Rotation = glm::mat4(1);
	m_m4Rotation = glm::rotate(m_m4Rotation,fRadians,v3Axis);

	//Apply rotation to the transform
	m_m4Model *= m_m4Rotation;
}


glm::mat4 Mesh::GetRot()
{
	return m_m4Rotation;
}

void Mesh::Update(float fDeltaTime)
{
	glm::mat4 m4Rot;
	glm::mat4 m4Pos;
	glm::mat4 m4Scale;



	m_m4Model = m4Pos * m4Rot;
}

