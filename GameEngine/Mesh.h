#pragma once
#include "glm.hpp"
#include "ext.hpp"
#include <Vector>
#include <String>


class Shader;

class Mesh
{
public:

	enum Type
	{
		CUBE,
		PLANE
	};

	Mesh(Type eType);
	virtual ~Mesh();

	Mesh(const char* szFileName, bool bLoadTextures, bool bFlipTextureV);
	Mesh(float fSphereRadius, int nSectors, int nStacks);


	


	struct Vertex
	{
		glm::vec4 m_v4Position;
		glm::vec4 m_v4Normal;
		glm::vec2 m_v2TexCoord;
		glm::vec4 m_v4Tangent;
	};

	class Material
	{
	public:
		Material() : m_v3Ambient(1), m_v3Diffuse(1), m_v3Specular(0), m_fSpecularPower(1), m_fOpacity(1),m_v3Emmisive(glm::vec3(1)) {};
		~Material();

		glm::vec3 m_v3Ambient;
		glm::vec3 m_v3Diffuse;
		glm::vec3 m_v3Specular;
		glm::vec3 m_v3Emmisive;


		float m_fSpecularPower;
		float m_fOpacity;
	};



	virtual void Draw(Shader* pShader);
	
	void SetPos(glm::vec3 v3Pos);
	glm::vec3 GetPos();


	void Rotate(float fRadians,glm::vec3 v3Axis);
	glm::mat4 GetRot();

	void Update(float fDeltaTime);

	size_t GetMaterialCount();
	Material& GetMaterial(size_t index);
protected:
	//Functions for OBJ loading
	bool LoadModel(const char* szFileName, bool bLoadTextures = true, bool bFlipTextureV = false);
	void DrawModel(Shader* pShader, bool bUsePatches = false);
	std::string& GetFileName();
	void CalculateTangents(std::vector<Vertex>& av3Verts, std::vector<unsigned int>& anIndicies);


	struct MeshChunk
	{
		unsigned int m_nVao, m_nVbo, m_nIbo;
		unsigned int m_nIndexCount;
		int  m_nMaterialID;
	};




	std::string m_sFileName;
	std::vector<MeshChunk> m_aMeshChunks;
	std::vector<Material> m_aMaterials;



	void InitializeQuad(Type eType);
	void InitializeQuad(float fRadius, int nSectors,int nStacks);
	glm::mat4 m_m4Model = glm::mat4(1);
	glm::mat4 m_m4Rotation;
	glm::vec3 m_v3Position;



	std::vector<unsigned int> m_anIndex_buffer;
	std::vector<glm::vec3> m_av3Verts;


	unsigned int m_nTexture;
	int m_nX, m_nY, m_nN;

	unsigned int m_nTriCount;
	unsigned int m_nVao;
	unsigned int m_nVbo;
	unsigned int m_nIbo;

	bool m_bLoadedModel;


};

