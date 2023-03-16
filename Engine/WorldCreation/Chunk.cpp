#include "Chunk.h"

Chunk::Chunk(void)
{
	m_ChunkPosition.push_back(glm::vec2(0.0f));
	m_ChunkPosition.push_back(glm::vec2(0.0f));

	//The block matrix has reserved memory because the block count is constant per chunk*/
	m_BlockMatrix.reserve(CHUNK_VOLUME);

	//Here I Take a bet, that the chunk will never be enormous
	m_Mesh.reserve(CHUNK_VOLUME);
}

Chunk::Chunk(glm::vec2 ChunkPosition)
{
	//The block matrix has reserved memory because the block count is constant per chunk*/
	m_BlockMatrix.reserve(CHUNK_VOLUME);

	//Setting the position
	m_ChunkPosition.push_back(ChunkPosition); //Top Left
	m_ChunkPosition.push_back(glm::vec2(ChunkPosition.y - CHUNK_SIDE, ChunkPosition.y + CHUNK_SIDE)); //Lower Right
}

Chunk::~Chunk(void)
{

}

void Chunk::SetChunkPosition(glm::vec2 ChunkPosition)
{
	m_ChunkPosition[0] = ChunkPosition;
	m_ChunkPosition[1] = glm::vec2(ChunkPosition.y - CHUNK_SIDE, ChunkPosition.y + CHUNK_SIDE);
}

bool Chunk::CheckCollision(glm::vec3 Coordinates)
{
	for (uint16_t i = 0; i < (m_BlockMatrix).size(); i++)
	{

	}
	return false;
}

void Chunk::DrawChunksToConsole(void)
{
	uint8_t yAxis = 0;
	uint8_t xAxis = 0;
	uint8_t zAxis = 0;

	for (uint8_t i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (uint8_t j = 0; j < CHUNK_SIDE; j++)
		{

			for (uint8_t k = 0; k < CHUNK_SIDE; k++)
			{

				std::cout << (int)(m_BlockMatrix)[CHUNK_AREA * i + CHUNK_SIDE * j + k].GetType() << " ";

			}
			std::cout << '\n';

		}
		std::cout << "\n\n";

	}

}

void Chunk::CheckIfBelongs(glm::vec3)
{
	for (uint8_t i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (uint8_t j = 0; j < CHUNK_SIDE; j++)
		{

			for (uint8_t k = 0; k < CHUNK_SIDE; k++)
			{

				std::cout << (int)(m_BlockMatrix)[CHUNK_AREA * i + CHUNK_SIDE * j + k].GetType() << " ";

			}
			std::cout << '\n';

		}
		std::cout << "\n\n";

	}
}

void Chunk::CopyMeshToBuffer(Vertex* BufferPointer)
{
	for (int i = 0; i < m_Mesh.size(); i++)
	{
		*(BufferPointer + i) = m_Mesh[i];
	}
}

