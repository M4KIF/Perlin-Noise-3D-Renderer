#include "ChunkMesh.h"

ChunkMesh::ChunkMesh(void)
{
}

ChunkMesh::~ChunkMesh(void)
{
}


void ChunkMesh::PushSouth(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f)));
}

void ChunkMesh::PushTop(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y+1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z-1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z-1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z-1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y+1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y+1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
}


void ChunkMesh::PushNorth(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x-1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x-1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x-1.0f, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
}

void ChunkMesh::PushWest(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
}

void ChunkMesh::PushEast(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z+1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z+1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f)));
}

void ChunkMesh::PushBottom(glm::vec3 lowerleft)
{
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_Mesh.push_back(Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f)));
}

/*
* Those are to be used with the Persistently mapped buffer
*/

Vertex* ChunkMesh::PushSouthToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	*(BufferPointer + 1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	*(BufferPointer + 2) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, -1.0f));
	return (BufferPointer + 6);
}

Vertex* ChunkMesh::PushTopToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z - 1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 2) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z - 1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z - 1.0f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	return (BufferPointer + 6);
}


Vertex* ChunkMesh::PushNorthToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer+1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer+2) = Vertex(glm::vec3(lowerleft.x - 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x - 1.0f, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x - 1.0f, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return (BufferPointer + 6);
}

Vertex* ChunkMesh::PushWestToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 2) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return (BufferPointer + 6);
}

Vertex* ChunkMesh::PushEastToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 2) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x, lowerleft.y + 1.0f, lowerleft.z + 1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	return (BufferPointer + 6);
}

Vertex* ChunkMesh::PushBottomToBuffer(glm::vec3 lowerleft, Vertex* BufferPointer)
{
	*BufferPointer = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 1) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 2) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 3) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z + 1.0f), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 4) = Vertex(glm::vec3(lowerleft.x + 1.0f, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	*(BufferPointer + 5) = Vertex(glm::vec3(lowerleft.x, lowerleft.y, lowerleft.z), glm::vec3(0.5f, 0.2f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f));
	return (BufferPointer + 6);
}

void ChunkMesh::BuildBruteMesh(Chunk* chunk)
{
	int how_much = 0;

	std::vector<Block> MeshData = chunk->GetBlockMatrix();
	glm::vec2 ChunkPos(0.0f);
	ChunkPos = chunk->GetChunkPosition();

	if (!chunk->MeshCreated() && chunk->ChunkCreated()) {
		for (uint8_t i = 0; i < CHUNK_HEIGHT; i++)
		{

			for (uint8_t j = 0; j < CHUNK_SIDE; j++)
			{

				for (uint8_t k = 0; k < CHUNK_SIDE; k++)
				{

					if (MeshData[CHUNK_AREA * i + CHUNK_SIDE * j + k].GetType() != BlockType::Air)
					{
						PushSouth(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						PushWest(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						PushEast(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						PushNorth(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						PushTop(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						PushBottom(glm::vec3(ChunkPos.x + (float)j, (float)i, ChunkPos.y - (float)k));
						how_much += 6 * 4 * 3;
					}

				}

			}

		}
		std::cout << "How much bytes: " << how_much << " | " << "megabytes: " << (float)how_much/(float)1000000 << '\n';

		chunk->ActivateMeshCreated();
		chunk->SetMeshMatrix(m_Mesh);
		m_Mesh.clear();
	}
}

void ChunkMesh::BuildMesh(Chunk* chunk)
{

	/*
	* ---------------------------------
	* Light algorithm for culling faces
	* and creating a lighter mesh than
	* the totally naive method
	-----------------------------------
	*/

	/*Variable for calculating size*/

	int how_much = 0;

	/*
	* For each face lets see, what can be added
	* and what cannot;
	*/

	uint8_t Faces = 6;
	uint8_t i, j, k, l;

	std::vector<Block> Blocks = chunk->GetBlockMatrix();
	glm::vec2 Position = chunk->GetChunkPosition();

	/*
	* Filling the north side of the chunk
	*/

	for (i = CHUNK_HEIGHT-2; i>0;i--)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/


				PushNorth(glm::vec3(Position.x + (float)(j+1), (float)i, Position.y));
				how_much += 6 * 4 * 3;

				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j + 1].GetType() == BlockType::Air) {

						PushEast(glm::vec3(Position.x + (float)(j+1), (float)i, Position.y));
						how_much += 6 * 4 * 3;
						continue;
					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j - 1].GetType() == BlockType::Air) {

						PushWest(glm::vec3(Position.x + (float)(j), (float)i, Position.y));
						how_much += 6 * 4 * 3;
						continue;
					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + 0 * CHUNK_WIDTH + j].GetType() == BlockType::Air) {

						PushTop(glm::vec3(Position.x + (float)(j), (float)i, Position.y+1.0f));
						how_much += 6 * 4 * 3;
						continue;
					}

				}

			}

		}

	}

	/*
	* Filling the South side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				PushSouth(glm::vec3(Position.x + (float)(j), (float)i, Position.y+CHUNK_WIDTH));
				how_much += 6 * 4 * 3;

				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j + 1].GetType() == BlockType::Air) {

						PushEast(glm::vec3(Position.x+(float)(j+1), (float)i, Position.y + (CHUNK_WIDTH - 1)));
						how_much += 6 * 4 * 3;
						continue;
					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j - 1].GetType() == BlockType::Air) {

						PushWest(glm::vec3(Position.x + (float)(j), (float)i, Position.y + (CHUNK_WIDTH-1)));
						how_much += 6 * 4 * 3;
						continue;
					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j].GetType() == BlockType::Air) {

						PushTop(glm::vec3(Position.x + (float)(j), (float)i, Position.y + (CHUNK_WIDTH)));
						how_much += 6 * 4 * 3;
						continue;
					}

				}
				if (j == CHUNK_WIDTH - 1)
				{
					PushEast(glm::vec3(Position.x + (float)(j + 1), (float)i, Position.y + (CHUNK_WIDTH - 1)));
					how_much += 6 * 4 * 3;
					continue;
				}

			}

		}

	}

	/*
	* Filling the West side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + j * CHUNK_WIDTH + 0].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				PushWest(glm::vec3(Position.x, (float)i, Position.y + j));
				how_much += 6 * 4 * 3;

				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH].GetType() == BlockType::Air) {

						PushNorth(glm::vec3(Position.x+1.0f, (float)i, Position.y + (j+1)));
						how_much += 6 * 4 * 3;
						continue;

					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH].GetType() == BlockType::Air) {

						PushSouth(glm::vec3(Position.x, (float)i, Position.y + (j)));
						how_much += 6 * 4 * 3;
						continue;

					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH].GetType() == BlockType::Air) {

						PushTop(glm::vec3(Position.x, (float)i, Position.y + (j + 1)));
						how_much += 6 * 4 * 3;
						continue;

					}

				}

			}

		}

	}

	/*
	* Filling the East side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + j * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				PushEast(glm::vec3(Position.x+CHUNK_WIDTH, (float)i, Position.y + (j)));
				how_much += 6 * 4 * 3;

				if (j > 0) {

					if (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						PushNorth(glm::vec3(Position.x + CHUNK_WIDTH, (float)i, Position.y + (j)));
						how_much += 6 * 4 * 3;
						continue;

					}
				}
				if (j < CHUNK_WIDTH - 1) {
					if (Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						PushSouth(glm::vec3(Position.x-1.0f + CHUNK_WIDTH, (float)i, Position.y + (j+1)));
						how_much += 6 * 4 * 3;
						continue;

					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						PushTop(glm::vec3(Position.x - 1.0f + CHUNK_WIDTH, (float)i, Position.y + (j+1)));
						how_much += 6 * 4 * 3;
						continue;

					}

				}

			}

		}

	}

	/*
	* Filling the rest of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{
		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			for (k = 0; k < CHUNK_WIDTH; k++)
			{

				/*
				* For each cube I shall now check whether It is surrounded by air
				*/
				if (Blocks[(i)*CHUNK_AREA + j * CHUNK_WIDTH + k].GetType() != BlockType::Air) {

					if (i < CHUNK_HEIGHT - 1 && Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH + k].GetType() == BlockType::Air) {

						PushTop(glm::vec3(Position.x + k, i, Position.y + (j + 1)));
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (j < CHUNK_WIDTH - 1 && Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH + k].GetType() == BlockType::Air) {

						PushSouth(glm::vec3(Position.x + (k), i, Position.y + (j + 1)));
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (j > 0 && (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH + k].GetType() == BlockType::Air)) {
						PushNorth(glm::vec3(Position.x + (k + 1), i, Position.y + (j)));
						how_much += 6 * 4 * 3;

					}
					if (k < CHUNK_WIDTH - 1 && Blocks[i * CHUNK_AREA + (j)*CHUNK_WIDTH + (k + 1)].GetType() == BlockType::Air) {

						PushEast(glm::vec3(Position.x + (k + 1), i, Position.y + (j)));
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (k > 0 && Blocks[i * CHUNK_AREA + (j)*CHUNK_WIDTH + (k - 1)].GetType() == BlockType::Air) {

						PushWest(glm::vec3(Position.x + (k), i, Position.y + (j)));
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
				}

			}

		}
	}

	//std::cout << "How much bytes: " << how_much << " | " << "megabytes: " << (float)how_much / (float)1000000 << '\n';

	chunk->ActivateMeshCreated();
	chunk->SetMeshMatrix(m_Mesh);
	m_Mesh.clear();
}

void ChunkMesh::BuildMeshToBuffer(Chunk* chunk, Vertex* BufferPointer)
{

	/*
	* ---------------------------------
	* Light algorithm for culling faces
	* and creating a lighter mesh than
	* the totally naive method
	-----------------------------------
	*/

	/*Variable for calculating size*/

	int how_much = 0;

	/*
	* For each face lets see, what can be added
	* and what cannot;
	*/

	uint8_t Faces = 6;
	uint8_t i, j, k, l;

	std::vector<Block> Blocks = chunk->GetBlockMatrix();
	glm::vec2 Position = chunk->GetChunkPosition();

	/*
	* Filling the north side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/


				BufferPointer = PushNorthToBuffer(glm::vec3(Position.x + (float)(j + 1), (float)i, Position.y), BufferPointer);
				how_much += 6 * 4 * 3;

				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j + 1].GetType() == BlockType::Air) {

						BufferPointer = PushEastToBuffer(glm::vec3(Position.x + (float)(j + 1), (float)i, Position.y), BufferPointer);
						how_much += 6 * 4 * 3;
					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + 0 * CHUNK_WIDTH + j - 1].GetType() == BlockType::Air) {

						BufferPointer = PushWestToBuffer(glm::vec3(Position.x + (float)(j), (float)i, Position.y), BufferPointer);
						how_much += 6 * 4 * 3;
					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + 0 * CHUNK_WIDTH + j].GetType() == BlockType::Air) {

						BufferPointer = PushTopToBuffer(glm::vec3(Position.x + (float)(j), (float)i, Position.y + 1.0f), BufferPointer);
						how_much += 6 * 4 * 3;
					}

				}

			}

		}

	}

	/*
	* Filling the South side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				BufferPointer = PushSouthToBuffer(glm::vec3(Position.x + (float)(j), (float)i, Position.y + CHUNK_WIDTH), BufferPointer);
				how_much += 6 * 4 * 3;
				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j + 1].GetType() == BlockType::Air) {

						BufferPointer = PushEastToBuffer(glm::vec3(Position.x + (float)(j + 1), (float)i, Position.y + (CHUNK_WIDTH - 1)), BufferPointer);
						how_much += 6 * 4 * 3;
					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j - 1].GetType() == BlockType::Air) {

						BufferPointer = PushWestToBuffer(glm::vec3(Position.x + (float)(j), (float)i, Position.y + (CHUNK_WIDTH - 1)), BufferPointer);
						how_much += 6 * 4 * 3;
					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + (CHUNK_WIDTH - 1) * CHUNK_WIDTH + j].GetType() == BlockType::Air) {

						BufferPointer = PushTopToBuffer(glm::vec3(Position.x + (float)(j), (float)i, Position.y + (CHUNK_WIDTH)), BufferPointer);
						how_much += 6 * 4 * 3;
					}

				}
				if (j == CHUNK_WIDTH - 1)
				{
					BufferPointer = PushEastToBuffer(glm::vec3(Position.x + (float)(j + 1), (float)i, Position.y + (CHUNK_WIDTH - 1)), BufferPointer);
					how_much += 6 * 4 * 3;
				}

			}

		}

	}

	/*
	* Filling the West side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + j * CHUNK_WIDTH + 0].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				BufferPointer = PushWestToBuffer(glm::vec3(Position.x, (float)i, Position.y + j), BufferPointer);
				how_much += 6 * 4 * 3;

				if (j < CHUNK_WIDTH - 1) {

					if (Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH].GetType() == BlockType::Air) {

						BufferPointer = PushNorthToBuffer(glm::vec3(Position.x + 1.0f, (float)i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;

					}
				}
				if (j > 0) {
					if (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH].GetType() == BlockType::Air) {

						BufferPointer = PushSouthToBuffer(glm::vec3(Position.x, (float)i, Position.y + (j)), BufferPointer);
						how_much += 6 * 4 * 3;

					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH].GetType() == BlockType::Air) {

						BufferPointer = PushTopToBuffer(glm::vec3(Position.x, (float)i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;

					}

				}

			}

		}

	}

	/*
	* Filling the East side of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{

		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			if (Blocks[i * CHUNK_AREA + j * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() != BlockType::Air)
			{

				/*Filling in the north side with all of its side dents*/

				BufferPointer = PushEastToBuffer(glm::vec3(Position.x + CHUNK_WIDTH, (float)i, Position.y + (j)), BufferPointer);
				how_much += 6 * 4 * 3;

				if (j > 0) {

					if (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						BufferPointer = PushNorthToBuffer(glm::vec3(Position.x + CHUNK_WIDTH, (float)i, Position.y + (j)), BufferPointer);
						how_much += 6 * 4 * 3;

					}
				}
				if (j < CHUNK_WIDTH - 1) {
					if (Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						BufferPointer = PushSouthToBuffer(glm::vec3(Position.x - 1.0f + CHUNK_WIDTH, (float)i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;

					}
				}
				if (i < CHUNK_HEIGHT - 1)
				{

					if (Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH + (CHUNK_WIDTH - 1)].GetType() == BlockType::Air) {

						BufferPointer = PushTopToBuffer(glm::vec3(Position.x - 1.0f + CHUNK_WIDTH, (float)i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;

					}

				}

			}

		}

	}

	/*
	* Filling the rest of the chunk
	*/

	for (i = 0; i < CHUNK_HEIGHT; i++)
	{
		for (j = 0; j < CHUNK_WIDTH; j++)
		{

			for (k = 0; k < CHUNK_WIDTH; k++)
			{

				/*
				* For each cube I shall now check whether It is surrounded by air
				*/
				if (Blocks[(i)*CHUNK_AREA + j * CHUNK_WIDTH + k].GetType() != BlockType::Air) {

					if (i < CHUNK_HEIGHT - 1 && Blocks[(i + 1) * CHUNK_AREA + j * CHUNK_WIDTH + k].GetType() == BlockType::Air) {

						BufferPointer = PushTopToBuffer(glm::vec3(Position.x + k, i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (j < CHUNK_WIDTH - 1 && Blocks[i * CHUNK_AREA + (j + 1) * CHUNK_WIDTH + k].GetType() == BlockType::Air) {

						BufferPointer = PushSouthToBuffer(glm::vec3(Position.x + (k), i, Position.y + (j + 1)), BufferPointer);
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (j > 0 && (Blocks[i * CHUNK_AREA + (j - 1) * CHUNK_WIDTH + k].GetType() == BlockType::Air)) {
						BufferPointer = PushNorthToBuffer(glm::vec3(Position.x + (k + 1), i, Position.y + (j)), BufferPointer);
						how_much += 6 * 4 * 3;

					}
					if (k < CHUNK_WIDTH - 1 && Blocks[i * CHUNK_AREA + (j)*CHUNK_WIDTH + (k + 1)].GetType() == BlockType::Air) {

						BufferPointer = PushEastToBuffer(glm::vec3(Position.x + (k + 1), i, Position.y + (j)), BufferPointer);
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
					if (k > 0 && Blocks[i * CHUNK_AREA + (j)*CHUNK_WIDTH + (k - 1)].GetType() == BlockType::Air) {

						BufferPointer = PushWestToBuffer(glm::vec3(Position.x + (k), i, Position.y + (j)), BufferPointer);
						how_much += 6 * 4 * 3;
						/*std::cout << i << '\n';*/

					}
				}

			}

		}
	}

	std::cout << "How much bytes: " << how_much << " | " << "megabytes: " << (float)how_much / (float)1000000 << '\n';

	chunk->ActivateMeshCreated();
	chunk->SetMeshMatrix(m_Mesh);
	m_Mesh.clear();
}

