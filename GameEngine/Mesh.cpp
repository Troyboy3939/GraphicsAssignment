#include "Mesh.h"
#include "gl_core_4_5.h"
#include <vector>
#include "Shader.h"
Mesh::Mesh()
{
	m_nTriCount = 0;
	m_nVao = 0;
	m_nVbo = 0;
	m_nIbo = 0;


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
	

	m_av3Verts = std::vector<glm::vec3>(
		{

		//Cube
		glm::vec3(0.1f, 0.1f, -0.1f),  //0
		glm::vec3(0.1f, -0.1f, -0.1f), //1
		glm::vec3(-0.1f, -0.1f, -0.1f),//2
		glm::vec3(-0.1f, 0.1f, -0.1f), //3
									   
		glm::vec3(0.1f, 0.1f, 0.1f),   //4
		glm::vec3(0.1f, -0.1f, 0.1f),  //5
		glm::vec3(-0.1f, -0.1f, 0.1f), //6
		glm::vec3(-0.1f, 0.1f, 0.1f),  //7
		


		//Ground
		glm::vec3(0.0f ,0.0f ,0.0f),  //8
		glm::vec3(100.0f ,0.0f ,0.0f),   //9
		glm::vec3(100.0f ,0.0f ,100.0f), //10
		glm::vec3(0.0f ,0.0f ,100.0f)    //11

		});

	m_anIndex_buffer =
	{
		0, 1, 3,   // front first triangle  
		1, 2, 3,   // front second triangle  
		4, 5, 7,   // back first triangle    
		5, 6, 7,   // back second triangle   
		4, 5, 1,   // right first triangle   
		1, 0, 4,   // right second triangle  
		3, 2, 6,   // left first triangle    
		6, 7, 3,   // left second triangle   
		0, 3, 7,   // top first triangle     
		7, 4, 0,   // top second triangle    
		1, 2, 6,   // bottom first triangle  
		6, 5, 1,    // bottom second triangle

		8, 10, 9,  //floor triangle 1 
		8, 11, 10   //floor triangle 2
	};


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

	m_nTriCount = m_anIndex_buffer.size() / 3;
	
	

}

void Mesh::Draw(Shader* pShader)
{
	auto uniform_location = glGetUniformLocation(pShader->GetShaderProgram(), "model_matrix");
	glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(m_m4Model));

	glBindVertexArray(m_nVao);
	glDrawElements(GL_TRIANGLES, m_anIndex_buffer.size(), GL_UNSIGNED_INT,0);
}

void Mesh::SetPos(glm::vec3 v3Pos)
{
	m_m4Model[3] = glm::vec4(v3Pos,1);
}

glm::vec3 Mesh::GetPos()
{
	return m_m4Model[3];
}

