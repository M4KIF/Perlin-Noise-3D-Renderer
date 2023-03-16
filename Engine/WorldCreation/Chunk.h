#pragma once

#include<glm.hpp>
#include<Libraries/GLM/gtc/matrix_transform.hpp>

#include<Engine/WorldCreation/Block.h>
#include<iostream>
#include<vector>
#include<deque>

#define CHUNK_SIDE 16
#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 192
#define CHUNK_AREA CHUNK_SIDE * CHUNK_SIDE
#define CHUNK_VOLUME CHUNK_SIDE * CHUNK_SIDE * CHUNK_HEIGHT

/*
* Creating the interleaved data format
*/

struct Vertex
{
	/*
	* The needed data for sending to the buffer
	*/

	glm::vec3 m_Position;
	glm::vec3 m_Color;
	glm::vec3 m_Normal;

	/*Constructors*/

	Vertex(void) {};
	Vertex(glm::vec3 Pos, glm::vec3 Col, glm::vec3 Nor) : m_Position(Pos), m_Color(Col), m_Normal(Nor){};
	~Vertex() {};
};

class Chunk
{
protected:

	/*
	* Chunk position vector, contains the upper left vertex and lower right vertex, when looking from the top
	*/

	std::vector<glm::vec2> m_ChunkPosition;

	/*
	* A single dimension matrix containing all the needed blocks
	*/

	std::vector<Block> m_BlockMatrix;

	/*
	* Chunk Mesh components
	*/

	std::vector<Vertex> m_Mesh;

	/*
	* Adjacenency flags, so that I could implement something like greedy area meshing
	*/

	bool m_AdjacentNorth = false;
	bool m_AdjacentSouth = false;
	bool m_AdjacentWest = false;
	bool m_AdjacentEast = false;

	/*
	* Chunk state flags
	*/
	
	//Chunk
	bool m_ChunkCreated = false;
	bool m_ChunkUpdated = false;

	//Mesh
	bool m_MeshCreated = false;
	bool m_MeshPropertiesFilled = false;
	bool m_MeshBeingDrawn = false;

public:

	/*
	* Constructor, both default and the one that sets the chunk postion and an desturctor
	*/

	Chunk();
	Chunk(glm::vec2 ChunkPosition);
	~Chunk();

	/*
	* Chunk data getters and setters
	*/

	inline Chunk* GetChunkPointer(void) { return this; };
	inline std::vector<Block>& const GetBlockMatrix(void) { return m_BlockMatrix; };
	inline void SetBlockMatrix(std::vector<Block> BlockMatrix) { m_BlockMatrix = BlockMatrix; }
	inline glm::vec2& GetChunkPosition(void) { return m_ChunkPosition[0]; };
	void SetChunkPosition(glm::vec2 ChunkPosition);

	//Used by the event system
	BlockType GetBlock(glm::vec3 BlockPosition);
	void SetBlock(glm::vec3 BlockPosition, BlockType BlockType);

	/*
	* Mesh data getters and setters
	*/

	inline std::vector<Vertex>* GetMeshMatrix(void) { return &m_Mesh; };
	inline std::vector<Vertex> GetMesh(void) { return m_Mesh; };
	inline void SetMeshMatrix(std::vector<Vertex> ChunkMesh) { m_Mesh = ChunkMesh; };
	inline int GetMeshSize(void) { return m_Mesh.size(); };


	/*
	* Flags getters and setters
	*/

	inline bool const CheckNorthAdjacency(void) {return m_AdjacentNorth; };
	inline void ActivateNorthAdjacency(void) { m_AdjacentNorth = true; };
	inline void DisactivateNorthAdjacency(void) { m_AdjacentNorth = false; };
	inline bool const CheckSouthAdjacency(void) { return m_AdjacentSouth; };
	inline void ActivateSouthAdjacency(void) { m_AdjacentSouth = true; };
	inline void DisactivateSouthAdjacency(void) { m_AdjacentSouth = false; };
	inline bool const CheckWestAdjacency(void) { return m_AdjacentWest; };
	inline void ActivateWestAdjacency(void) { m_AdjacentWest = true; };
	inline void DisactivateWestAdjacency(void) { m_AdjacentWest = false; };
	inline bool const CheckEastAdjacency(void) { return m_AdjacentEast; };
	inline void ActivateEastAdjacency(void) { m_AdjacentEast = true; };
	inline void DisactivateEastAdjacency(void) { m_AdjacentEast = false; };

	/*
	* State flags
	*/

	//Chunk
	inline bool const ChunkCreated(void) { return m_ChunkCreated; };
	inline void ActivateChunkCreated(void) { m_ChunkCreated = true; };
	inline void DisactivateChunkCreated(void) { m_ChunkCreated = false; };

	//Mesh
	inline bool const MeshCreated(void) { return m_MeshCreated; };
	inline void ActivateMeshCreated(void) { m_MeshCreated = true; };
	inline void DisactivateMeshCreated(void) { m_MeshCreated = false; };

	//Others
	inline bool const MeshBeingDrawn(void) { return m_MeshBeingDrawn; };
	inline void ActivateMeshBeingDrawn(void) { m_MeshBeingDrawn = true; };
	inline void DisactivateMeshBeingDrawn(void) { m_MeshBeingDrawn = false; };

	/*
	* Collision checking methods
	*/

	bool CheckCollisionPerpendicular(std::vector<glm::vec3> CoordinatesAABB);
	bool CheckCollisionAdjacent(std::vector<glm::vec3> CoordinatesAABB);
	bool CheckCollision(glm::vec3 Coordinates);

	/*
	* Others
	*/

	void CopyMeshToBuffer(Vertex* BufferPointer);
	void DrawChunksToConsole(void);
	void CheckIfBelongs(glm::vec3);
};

