#pragma once

#include<Engine/Input/Camera.h>
#include<Engine/BackEnd/Shader.h>
#include<Engine/WorldCreation/Chunk.h>
#include<Libraries/GLM/glm.hpp>
#include<vector>
#include<cstdlib>

enum class BlockSide
{
	NORTH = 0, 
	SOUTH, 
	WEST, 
	EAST,
	TOP,
	BOTTOM
};

class ChunkMesh
{
protected:
	/*
	* The mesh itself
	*/

	std::vector<Vertex> m_Mesh;

	/*
	* Methods for pushing the faces into the mesh
	* Lower left when standing in front of the said face
	*/

	void PushSouth(glm::vec3 lowerleft); 
	void PushTop(glm::vec3 lowerleft); 
	void PushNorth(glm::vec3 lowerleft); 
	void PushWest(glm::vec3 lowerleft); 
	void PushEast(glm::vec3 lowerleft); 
	void PushBottom(glm::vec3 lowerleft); 

	/*
	* Methods used to push into the buffer, propably will be used later
	*/

	Vertex* PushSouthToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);
	Vertex* PushTopToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);
	Vertex* PushNorthToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);
	Vertex* PushWestToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);
	Vertex* PushEastToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);
	Vertex* PushBottomToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer);

public:

	/*
	*Constructor / Destructor
	*/

	ChunkMesh(void);
	~ChunkMesh(void);

	/*
	*Meshing algorythms
	*/

	void BuildBruteMesh(Chunk* chunk);
	void BuildMesh(Chunk* chunk);
	void BuildMeshToBuffer(Chunk* chunk, Vertex* BufferPointer);

};

