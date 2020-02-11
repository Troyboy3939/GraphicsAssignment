#include "Mesh.h"
#include "gl_core_4_5.h"
#include <vector>
Mesh::Mesh()
{
	triCount = 0;
	vao = 0;
	vbo = 0;
	ibo = 0;


	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &ibo);


	//glClearColor(0, 0, 0, 1);

	////bind
	//glBindVertexArray(vao);
	////glBindBuffer(GL_ARRAY_BUFFER, vbo);
	////glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * verts.size(), verts.data(), GL_STATIC_DRAW);
	////glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	////glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_buffer), index_buffer.data(), GL_STATIC_DRAW);

	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), 0);

	//glBindVertexArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void Mesh::initializeQuad()
{
	//check that the mesh is already initialized
	//assert(vao == 0);
	

	verts = std::vector<glm::vec3>({

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

	index_buffer =
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
	}	;


	////generate buffers
	//glGenBuffers(1,&vbo);
	//glGenVertexArrays(1, &vao);
	//glGenBuffers(1,&ibo);


	//glClearColor(0,0,0,1);

	//bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * verts.size(), verts.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * index_buffer.size(), index_buffer.data(), GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	triCount = index_buffer.size() / 3;
	
	

	


}

void Mesh::draw()
{
	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, index_buffer.size(), GL_UNSIGNED_INT, 0);
}

