#pragma once

#include "Libraries/SIMPLEX/SimplexNoise.h"
#include<Engine/WorldCreation/Chunk.h>

#define CHUNK_SIDE 16
#define CHUNK_AREA CHUNK_SIDE * CHUNK_SIDE

class ChunkGenerator
{
protected:
	/*For every world it remains constant*/

	int32_t m_Seed;

	/*Values set per every chunk building*/

	std::vector<std::vector<uint8_t>> m_HeightMap;
	std::vector<Block> m_BlockMatrix;
	glm::vec2 m_ChunkUpperLeft = glm::vec2(0.0f);
	uint8_t m_CurrentHeight = 0;


	SimplexNoise m_Generator;

public:

	/*Constructor and an desturctor*/

	ChunkGenerator(void);
	~ChunkGenerator(void) {};

	/*Layer creation method*/

	void Create(Chunk* chunk);
	void CreateChunkHeightMap();

};

