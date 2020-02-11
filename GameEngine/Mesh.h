#pragma once
#include "glm.hpp"
#include "ext.hpp"
#include <Vector>

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

	void initializeQuad();
	virtual void draw();
	


protected:

	std::vector<unsigned int> index_buffer;
	std::vector<glm::vec3> verts;
	unsigned int triCount;
	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;
	

};

