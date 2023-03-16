#pragma once

#include<Engine/WorldCreation/Chunk.h>
#include<Engine/WorldCreation/ChunkGenerator.h>
#include<Engine/WorldCreation/ChunkMesh.h>

#define SPAWN_SIDE 4
#define SPAWN_AREA 16

/*Quick to make the view direction easy to distinguish*/

enum class Direction {
	North = 1, //1
	South, //2
	West, //3
	East, //4
	NorthWest, //5
	NorthEast, //6
	SouthWest, //7
	SouthEast //8
};

class ChunkManager
{
protected:
	/*The chunk map in 1D*/

	std::vector<std::vector<Chunk>> m_ChunkMap;
	std::vector<std::vector<Chunk>> m_ChunkCache;

	/*The map rendering options*/

	//4 is the lowest number
	uint8_t m_RenderDistance = 8;

	//Maximum map index

	uint8_t m_MaximumMapIndex = 2 * m_RenderDistance - 1;

	//Spawn/Player coordinates. At first set random, after that, set from the player input
	glm::vec3 m_CurrentPlayerCoordinates = glm::vec3(0.0f);
	glm::vec3 m_EarlierPlayerCoordinates = glm::vec3(0.0f);

	//The difference between Coordinates
	float m_DifferenceX = 0.0f;
	float m_DifferenceZ = 0.0f;

	/*Player view directions, to help with frustem culling*/

	Direction m_PlayerLookingDirection = Direction::North;
	Direction m_PlayerMovingDirection = Direction::North;

	/*Flags*/

	bool m_OnlySpawnReady;

	/*Other elements used for world generation*/

	ChunkGenerator m_ChunkBuilder;

	ChunkMesh m_MeshBuilder;

public:
	/*Defauilt constructor and a one setting render distance and an destructor*/

	ChunkManager(void);
	ChunkManager(uint8_t RenderDistance);
	~ChunkManager(void);

	/*Setters and getters*/

	inline std::vector<std::vector<Chunk>>* GetChunkMap(void) { return &m_ChunkMap; };
	inline void SetChunkMap(std::vector<std::vector<Chunk>>& ChunkMap) { m_ChunkMap = ChunkMap; };
	inline std::vector<std::vector<Chunk>> const GetChunkCache(void) { return m_ChunkCache; };
	inline void SetChunkCache(std::vector<std::vector<Chunk>>& ChunkCache) { m_ChunkCache = ChunkCache; };
	inline uint8_t const GetRenderDistance(void) { return m_RenderDistance; };
	inline void SetRenderDistance(uint8_t RenderDistance) { m_RenderDistance = RenderDistance; (m_ChunkMap).reserve((2 * m_RenderDistance) * (2 * m_RenderDistance)); };
	inline glm::vec3 const GetPlayerCoordinates(void) { return m_CurrentPlayerCoordinates; };
	inline void SetPlayerCoordinates(glm::vec3 CurrentPlayerCoordinates) { m_CurrentPlayerCoordinates = CurrentPlayerCoordinates; };
	inline Direction const GetPlayerMovingDirection(void) { return m_PlayerMovingDirection; };
	inline void SetPlayerMovingDirection(Direction PlayerMovingDirection) { m_PlayerMovingDirection = PlayerMovingDirection; };
	inline Direction const GetPlayerLookingDirection(void) { return m_PlayerLookingDirection; };
	inline void GetPlayerLookingDirection(Direction PlayerLookingDirection) { m_PlayerLookingDirection = PlayerLookingDirection; };


	glm::mat4& GetViewProj(void);
	glm::mat4& GetModel(void);


	/*Map setup methods*/

	void CreateChunkMap(void);
	bool SearchSpawnPoint(void); //This just check on which hight can a playert on certain x and z coordinates spawned
	void CreateSpawnArea(void);

	/*Map running methods*/

	bool UpdateMap(void);
	bool ManageCachedChunks(void);

	/*Player position methods*/

	Chunk* WhereIsThePlayer(void);

	/*Meshes methods*/

	bool UpdateChunkMesh();

	/*Debug*/

	void DrawMapCoordinates(void);
	void ReadyMesh(void);
	void BuildMeshes(void);
	void Draw(void);

	bool ReadyCalled = false;

	friend std::ostream& operator<<(std::ostream& os, glm::vec3& vector);
	friend std::ostream& operator<<(std::ostream& os, glm::vec4& vector);
};

