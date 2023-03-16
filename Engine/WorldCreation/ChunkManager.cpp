#include "ChunkManager.h"
#include<iomanip>

ChunkManager::ChunkManager(void)
	:m_OnlySpawnReady(true)
{
	(m_ChunkMap).reserve((2 * m_RenderDistance) * (2 * m_RenderDistance));
}

ChunkManager::ChunkManager(uint8_t RenderDistance)
	:m_OnlySpawnReady(true)
{
	(m_ChunkMap).reserve((2 * m_RenderDistance) * (2 * m_RenderDistance));
	m_RenderDistance = RenderDistance;
}

ChunkManager::~ChunkManager(void)
{
	m_ChunkCache.clear();
	m_ChunkMap.clear();
}

void ChunkManager::CreateChunkMap(void)
{
	std::vector<Chunk> Temp;
	for (uint8_t i = 0; i < (2*m_RenderDistance); i++)
	{
		for (uint8_t j = 0; j < (2 * m_RenderDistance); j++)
		{
			/*
			* Pushes back the exact amount of chunks that is specified through render distance
			*/

			Temp.push_back(Chunk());
		}
		m_ChunkMap.push_back(Temp);
	}
}

void ChunkManager::CreateSpawnArea(void)
{

	/*
	* Creating the matching index for the spawn area
	*/

	uint8_t index = m_RenderDistance - SPAWN_SIDE/2;

	for (uint8_t i = 0; i < SPAWN_SIDE; i++)
	{
		glm::vec2 ChunkCoordinates(0.0f);
		/*
		* I can defintetely pass the upper left vertex coordinates for each chunk
		*/
		if (i == 0)
		{
			/*
			* The starting coordinates are upper left corner of the area
			*/

			ChunkCoordinates = glm::vec2(m_CurrentPlayerCoordinates.x - 2 * CHUNK_SIDE, m_CurrentPlayerCoordinates.z - 2 * CHUNK_SIDE);
		}
		else if (i == 1)
		{
			ChunkCoordinates = glm::vec2(m_CurrentPlayerCoordinates.x - 2 *CHUNK_SIDE, m_CurrentPlayerCoordinates.z - CHUNK_SIDE);
		}
		else if (i == 2)
		{
			ChunkCoordinates = glm::vec2(m_CurrentPlayerCoordinates.x - 2 * CHUNK_SIDE, m_CurrentPlayerCoordinates.z);
		}
		else if (i == 3)
		{
			ChunkCoordinates = glm::vec2(m_CurrentPlayerCoordinates.x - 2 * CHUNK_SIDE, m_CurrentPlayerCoordinates.z + CHUNK_SIDE);
		}

		std::cout << ChunkCoordinates.x << ' ' << ChunkCoordinates.y << '\n';

		for (uint8_t j = 0; j < SPAWN_SIDE; j++)
		{

			m_ChunkMap[index+i][index+j].SetChunkPosition(ChunkCoordinates);

			/*
			* Fill the chunk with block data
			*/

			m_ChunkBuilder.Create(m_ChunkMap[index + i][index + j].GetChunkPointer());

			/*
			* Set the important to the further proccessing flags
			*/

			ChunkCoordinates.x += CHUNK_SIDE;
		}

	}

	m_OnlySpawnReady = true;
}

Chunk* ChunkManager::WhereIsThePlayer(void)
{

	for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
	{
		for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
		{

			if ((m_ChunkMap)[i][j].ChunkCreated())
			{
				glm::vec2 UpperLeft = m_ChunkMap[i][j].GetChunkPosition();
				glm::vec2 LowerRight = glm::vec2(UpperLeft.x + CHUNK_SIDE, UpperLeft.y - CHUNK_SIDE);

				if (((m_CurrentPlayerCoordinates.x > LowerRight.x && m_CurrentPlayerCoordinates.x < UpperLeft.x)
					|| (m_CurrentPlayerCoordinates.x < LowerRight.x && m_CurrentPlayerCoordinates.x >UpperLeft.x))
					&& ((m_CurrentPlayerCoordinates.z > LowerRight.y && m_CurrentPlayerCoordinates.z < UpperLeft.y)
						|| (m_CurrentPlayerCoordinates.z < LowerRight.y && m_CurrentPlayerCoordinates.z >UpperLeft.y)))
				{
					return m_ChunkMap[i][j].GetChunkPointer();
				}
			}
		}
	}
	return nullptr;
}

bool ChunkManager::SearchSpawnPoint(void)
{
	/*
	* It has to check where the player can land on the ground
	*/

	Chunk* temp = WhereIsThePlayer();

	for (uint8_t i = 0; i < CHUNK_HEIGHT; i++)
	{
		if (!temp->CheckCollision(glm::vec3(m_CurrentPlayerCoordinates.x, (float)i, m_CurrentPlayerCoordinates.y)))
		{
			m_CurrentPlayerCoordinates.y = i;
			return true;
		}
	}

	return false;
}

bool ChunkManager::UpdateMap(void)
{
	/*
	* Checks whether It is the first run of the algorithm
	*/

	if (m_OnlySpawnReady)
	{
		/*
		* Here, the map will be loaded further. This will only be done on a single thread and the algorhythm will be of the "Brute-force" type
		*/

		glm::vec2 ChunkCoordinates;
		//
		ChunkCoordinates.x = m_CurrentPlayerCoordinates.x - m_RenderDistance * CHUNK_SIDE - CHUNK_SIDE;
		ChunkCoordinates.y = m_CurrentPlayerCoordinates.z - (m_RenderDistance * CHUNK_SIDE);

		for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
		{

			for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
			{

				ChunkCoordinates.x += CHUNK_SIDE;
				if (!m_ChunkMap[i][j].ChunkCreated())
				{
					m_ChunkMap[i][j].SetChunkPosition(ChunkCoordinates);

					/*
					* Fill the chunk with block data
					*/

					m_ChunkBuilder.Create(m_ChunkMap[i][j].GetChunkPointer());
				}
			}

			ChunkCoordinates.x = m_CurrentPlayerCoordinates.x - m_RenderDistance * CHUNK_SIDE - CHUNK_SIDE;

			ChunkCoordinates.y += CHUNK_SIDE;

		}

		m_OnlySpawnReady = false;

		return true;

	}
	else
	{
		/*
		* Here I have to push the chunks opposite to the moving direction,
		* then push the chunks that went out of bounce to the cache list
		* and then build new chunks in front. Iterating from the back to front,
		* so the first chunks i am iteratng over will get pushed to the list,
		* others will be reindexed, and the last ones will get their chunks newly built
		*/

		glm::vec3 Difference = m_CurrentPlayerCoordinates - m_EarlierPlayerCoordinates;
		m_EarlierPlayerCoordinates = m_CurrentPlayerCoordinates;
		m_DifferenceX += Difference.x;
		m_DifferenceZ += Difference.z;

		float DivisionX = m_DifferenceX / (float)CHUNK_SIDE;
		float DivisionZ = m_DifferenceZ / (float)CHUNK_SIDE;

		/*Front/Back movement*/

		if (DivisionZ <= -1.0f)
		{

			m_DifferenceZ = 0.0f;

			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
			{
				/*First index sets the cached chunks
				Those from 1 to 14 move the chunks to the back,
				and the 15th index is the one,where the chunk creation happens*/

				if (i == 0)
				{
					m_ChunkCache.push_back(m_ChunkMap[m_MaximumMapIndex]);
				}
				if (i < m_MaximumMapIndex)
				{
					m_ChunkMap[(m_MaximumMapIndex)-i] = m_ChunkMap[(m_MaximumMapIndex)-(i + 1)];
				}
				if (i == m_MaximumMapIndex)
				{
					/*I have to add a new row here, made completely, that means,
					the coordinates set, chunks generated, and the flags set correctly*/
					/*I wont be deleting the adress of the created chunk. That will be handled
					by the cache'ing handler. There I will just set to null the pointer and create another chunk*/

					glm::vec2 NewChunkUpperLeft = m_ChunkMap[0][0].GetChunkPosition();
					NewChunkUpperLeft.y -= CHUNK_SIDE;
					NewChunkUpperLeft.x -= CHUNK_SIDE;

					for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
					{
						NewChunkUpperLeft.x += CHUNK_SIDE;
						m_ChunkMap[0][j].SetChunkPosition(NewChunkUpperLeft);
						m_ChunkMap[0][j].DisactivateMeshCreated();
						m_ChunkBuilder.Create(m_ChunkMap[0][j].GetChunkPointer());
					}

				}

			}

		}
		else if (DivisionZ >= 1.0f)
		{

			m_DifferenceZ = 0.0f;

			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
			{
				/*First index sets the cached chunks
				Those from 1 to 14 move the chunks to the back,
				and the 15th index is the one,where the chunk creation happens*/

				if (i == 0)
				{
					m_ChunkCache.push_back(m_ChunkMap[0]);
				}
				if (i < m_MaximumMapIndex)
				{
					m_ChunkMap[i] = m_ChunkMap[i + 1];
				}
				if (i == m_MaximumMapIndex)
				{
					/*I have to add a new row here, made completely, that means,
					the coordinates set, chunks generated, and the flags set correctly*/
					/*I wont be deleting the adress of the created chunk. That will be handled
					by the cache'ing handler. There I will just set to null the pointer and create another chunk*/

					glm::vec2 NewChunkUpperLeft = m_ChunkMap[m_MaximumMapIndex][0].GetChunkPosition();
					NewChunkUpperLeft.y += CHUNK_SIDE;
					NewChunkUpperLeft.x -= CHUNK_SIDE;

					for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
					{
						NewChunkUpperLeft.x += CHUNK_SIDE;
						m_ChunkMap[m_MaximumMapIndex][j].SetChunkPosition(NewChunkUpperLeft);
						m_ChunkMap[m_MaximumMapIndex][j].DisactivateMeshCreated();
						m_ChunkBuilder.Create(m_ChunkMap[m_MaximumMapIndex][j].GetChunkPointer());

					}

				}

			}

		}

		/*Left/Right movement*/

		if (DivisionX <= -1.0f)
		{
			m_DifferenceX = 0.0f;

			std::vector<Chunk> temp;
			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
			{

				temp.push_back(m_ChunkMap[i][0]);

			}

			m_ChunkCache.push_back(temp);
			temp.erase(temp.begin(), temp.end());

			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++) {
				for (uint8_t j = 0; j < m_MaximumMapIndex; j++)
				{
					m_ChunkMap[i][(m_MaximumMapIndex)-j] = m_ChunkMap[i][(m_MaximumMapIndex)-(j + 1)];
				}
			}

			/*I have to add a new row here, made completely, that means,
			the coordinates set, chunks generated, and the flags set correctly*/
			/*I wont be deleting the adress of the created chunk. That will be handled
			by the cache'ing handler. There I will just set to null the pointer and create another chunk*/

			glm::vec2 NewChunkUpperLeft = m_ChunkMap[0][0].GetChunkPosition();
			NewChunkUpperLeft.x -= CHUNK_SIDE;

			for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
			{
				m_ChunkMap[j][0].SetChunkPosition(NewChunkUpperLeft);
				m_ChunkMap[j][0].DisactivateMeshCreated();
				m_ChunkBuilder.Create(m_ChunkMap[j][0].GetChunkPointer());

				NewChunkUpperLeft.y += CHUNK_SIDE;
			}
		}
		else if (DivisionX >= 1.0f)
		{

			m_DifferenceX = 0.0f;

			std::vector<Chunk> temp;
			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++)
			{

				temp.push_back(m_ChunkMap[i][m_MaximumMapIndex]);

			}

			m_ChunkCache.push_back(temp);
			temp.erase(temp.begin(), temp.end());

			for (uint8_t i = 0; i <= m_MaximumMapIndex; i++) {
				for (uint8_t j = 0; j < m_MaximumMapIndex; j++)
				{
					m_ChunkMap[i][j] = m_ChunkMap[i][j + 1];
				}
			}

			glm::vec2 NewChunkUpperLeft = m_ChunkMap[0][m_MaximumMapIndex].GetChunkPosition();
			NewChunkUpperLeft.x += CHUNK_SIDE;

			for (uint8_t j = 0; j <= m_MaximumMapIndex; j++)
			{
				m_ChunkMap[j][m_MaximumMapIndex].SetChunkPosition(NewChunkUpperLeft);
				m_ChunkMap[j][m_MaximumMapIndex].DisactivateMeshCreated();
				m_ChunkBuilder.Create(m_ChunkMap[j][m_MaximumMapIndex].GetChunkPointer());

				NewChunkUpperLeft.y += CHUNK_SIDE;
			}
		}
		else
		{
			/*Nothing has to be updated, best case scenario.
			Here I wont be dealing with the chunk block updating/placing. 
			This is a job for another method.*/
			return false;
		}
	}

	return true;
}

bool ChunkManager::ManageCachedChunks(void)
{
	/*
	* If the Chunk exceed the upper limit of cached chunks,
	* then it pops out the oldest ones
	*/

	if (m_ChunkCache.size() > 8)
	{
		for (uint8_t i = (uint8_t)m_ChunkCache.size() - 1; i >= 8; i--)
		{
			m_ChunkCache[i].erase(m_ChunkCache[i].begin(), m_ChunkCache[i].end());
		}
	}
	return false;
}

void ChunkManager::DrawMapCoordinates(void)
{
	std::cout << "CURRENT CHUNK MAP ELEMENTS COORDINATES\n\n";
	for (uint8_t i = 0; i < 2 * m_RenderDistance; i++)
	{
		for (uint8_t j = 0; j < 2*m_RenderDistance; j++)
		{
			glm::vec2 temp = m_ChunkMap[i][j].GetChunkPosition();
			std::cout << std::setw(5) << temp.x << "  " << std::setw(5) << temp.y << ' ';
		}
		std::cout << "\n";

	}
}

bool ChunkManager::UpdateChunkMesh()
{
	bool updated = false;
	for (int i = 0; i < 16; i++)
	{

		for (int j = 0; j < 16; j++)
		{
			if (!m_ChunkMap[i][j].MeshCreated())
			{
				m_MeshBuilder.BuildMesh(m_ChunkMap[i][j].GetChunkPointer());
				updated = true;
			}

		}

	}
	if (updated) return true;
	else return false;
}

