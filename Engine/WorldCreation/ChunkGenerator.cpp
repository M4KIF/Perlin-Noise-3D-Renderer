#include "ChunkGenerator.h"

#define INDESTRUCTIBLE_LEVEL 2
#define MORE_CAVES 1
#define OVERWORLD 2

ChunkGenerator::ChunkGenerator(void)
	:m_Generator(0.01f, 3.844131f, 6.82f, 1.0f/5.5f)
{
	m_Seed = rand();
}

void ChunkGenerator::CreateChunkHeightMap() 
{
	/*
	* Using the noise code from OpenSimplex
	*/

	glm::vec2 UpperLeft = m_ChunkUpperLeft;
	m_HeightMap.clear();

	for (int i = CHUNK_SIDE-1; i >= 0; i--)
	{
		std::vector<uint8_t> Temp;
		Temp.clear();
		for (int j = CHUNK_SIDE-1; j >= 0; j--)
		{
			/*
			* Using fractal noise to create the world structure
			*/

			uint8_t height = (float)((m_Generator.fractal((size_t)5, UpperLeft.x + j, UpperLeft.y - i)) * 10.0f + 40.0f);
			Temp.push_back(height);

		}

		std::reverse(Temp.begin(), Temp.end());
		m_HeightMap.push_back(Temp);
		UpperLeft.x = m_ChunkUpperLeft.x;

	}

}

void ChunkGenerator::Create(Chunk* chunk)
{

	m_BlockMatrix.clear();
	m_HeightMap.clear();

	/*
	* Setting important variables
	*/

	m_ChunkUpperLeft = chunk->GetChunkPosition();
	m_BlockMatrix.reserve(CHUNK_VOLUME);

	/*
	* Creating the height map
	*/

	this->CreateChunkHeightMap();

	/*
	* Create the chunk itself
	*/

	for (uint8_t i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (uint8_t j = 0; j < CHUNK_SIDE; j++)
		{

			for (uint8_t k = 0; k < CHUNK_SIDE; k++)
			{

				if (i < 3)
				{
					(m_BlockMatrix).push_back(Block(BlockType::Indestructible, i));
				}
				else if (i <= m_HeightMap[j][k])
				{
					/*
					* Above 100 create air
					*/

					if (i > 136)
					{
						(m_BlockMatrix).push_back(Block(BlockType::Air, i));
					}

					/*
					* Above 65 create Dirt only
					*/

					if (i > 55 && i <= 136)
					{
						(m_BlockMatrix).push_back(Block(BlockType::Grass, i));
					}

					/*
					* Bellow 65 and above 60 create Desert
					*/

					if (i <= 55 && i > 40)
					{
						(m_BlockMatrix).push_back(Block(BlockType::Sand, i));
					}

					/*
					* Bellow 60 create Stone*/

					if (i <= 40)
					{
						(m_BlockMatrix).push_back(Block(BlockType::Stone, i));
					}
				}
				else
				{
					(m_BlockMatrix).push_back(Block(BlockType::Air, i));
				}

			}

		}

	}

	chunk->SetBlockMatrix(m_BlockMatrix);
	chunk->ActivateChunkCreated();
}


