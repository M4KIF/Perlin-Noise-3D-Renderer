#include "WorldRenderer.h"

#include<Libraries/GLM/ext/matrix_transform.hpp>
#include<functional>
#include<iomanip>

/*This debugging code is inspired on TheCherno OpenGL Tutorial series*/

#define ASSERT(x) if (!(x)) __debugbreak();  //This part is not portable to other platforms

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall())
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) 

void GLClearError(void)
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	if (GLenum error = glGetError()) //// It waits for an error, and if it catches it, it then enters the statement
	{
		std::cout << "[OpenGL Error] (" << error << ") " << "\nFunction: " << function << "\n" << file << " : " << line << std::endl;
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, glm::vec3& vector)
{
	os << "Wektor: " << vector.x << ", " << vector.y << ", " << vector.z;
	return os;
}

std::ostream& operator<<(std::ostream& os, glm::vec4& vector)
{
	os << "Wektor: " <<  vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w;
	return os;
}


WorldRenderer::WorldRenderer(void)
	: m_Frustum(m_Camera.GetViewProj()), m_Shader("Shaders/Basic.shader")
{

}

WorldRenderer::WorldRenderer(uint16_t ChunkArea)
	: m_Frustum(m_Camera.GetViewProj()), m_Shader("Shaders/Basic.shader")
{	
	/*
	* Preparing the buffers
	*/

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IndirectBufferObject);
	Commands.reserve(256);
	glBindVertexArray(0);
}

WorldRenderer::WorldRenderer(GLFWwindow* window, uint8_t RenderDistance)
	: m_Frustum(m_Camera.GetViewProj()), m_Shader("Shaders/Basic.shader"), WorldRenderer::ChunkManager(8)
{
	/*
	* Setting the current window context
	*/

	m_Window = window;
	m_Camera.SetWindow(window);

	/*
	* Preparing the buffers
	*/

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IndirectBufferObject);
	glBindVertexArray(0);

	Commands.reserve(512);
}

WorldRenderer::~WorldRenderer(void)
{
}

void WorldRenderer::CreatePipeline(uint8_t renderdistance)
{

	GLCall(glBindVertexArray(m_VAO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexAttribFormat(2, 3, GL_FLOAT, GL_FALSE, 0);

	glVertexBindingDivisor(0, 0);
	glVertexBindingDivisor(1, 0);
	glVertexBindingDivisor(2, 0);

	glVertexAttribBinding(0, 0);
	glVertexAttribBinding(1, 1);
	glVertexAttribBinding(2, 2);

	glBindVertexBuffer(0, m_VBO, offsetof(Vertex, m_Position), sizeof(Vertex));		//Internal Offset vs. Full Offset
	glBindVertexBuffer(1, m_VBO, offsetof(Vertex, m_Color), sizeof(Vertex));
	glBindVertexBuffer(2, m_VBO, offsetof(Vertex, m_Normal), sizeof(Vertex));

	//Important bits which determine how our persistently mapped buffer will work

	const GLbitfield flag = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT;

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));

	GLCall(glBindVertexArray(m_VAO));
	GLCall(glBindBuffer(GL_DRAW_INDIRECT_BUFFER, m_IndirectBufferObject));
	GLCall(glBufferData(GL_DRAW_INDIRECT_BUFFER, 256 * sizeof(DrawArraysIndirectCommand), nullptr, GL_STATIC_DRAW));

	/*
	* Here I tell OpenGL to give a buffer that has 256 Mb of storage for my needs.
	* I haven't seen a chunk takeup more than 1 Mb, so I will partition It every 2Mb.
	*/

	GLCall(glNamedBufferStorage(m_VBO, 512000000, nullptr, flag));


	/*
	* I then have a whole 1D matrix of pointers that can contain the needed mesh data.
	* The thing doesnt even have to be half full, as the usage will be determined by indirect draw commands.
	* And determining the data should be as simple as asigning the void* pointer to the mesh selected by the frustum culler.
	*/

	/*
	* Mapping the whole buffer and accessing the pointer to the memory space
	*/

	BufferPointer = (Vertex*)glMapNamedBufferRange(m_VBO, 0, 512000000, flag);

	for (int i = 0; i < 256; i++)
	{
		if(i!=0) PartitionPointers.push_back(PartitionPointers[i-1] + CHUNK_VOLUME);
		else PartitionPointers.push_back(BufferPointer + i * CHUNK_VOLUME);
	}

	for (int i = 0; i < PartitionPointers.size(); i++)
	{
		std::cout << PartitionPointers[i] << "\n";
	}

	GLCall(glUnmapBuffer(GL_ARRAY_BUFFER));
}

void WorldRenderer::PrepareMeshes(void)
{
	/*
	* Here We do the procedures that involve 
	* calculating whether the chunks need to be loaded 
	* or not. Also, after that comes the meshing if needed
	* and If yes, then the FlushNeeded flag turns true, because We have loaded new chunks that need to be displayed.
	*/

	this->SetPlayerCoordinates(m_Camera.GetCameraPosition());
	this->UpdateMap();

	//Here We mesh the chunks
	if (this->UpdateChunkMesh()) m_FlushNeeded = true;
}

void WorldRenderer::PushCommands(void)
{
	if (m_MovementDetected)
	{
		Flush();
		//Gets the whole chunkmap up to our disposal
		std::vector<std::vector<Chunk>>* Pointer = this->GetChunkMap();

		//Updates the Viewing frustum according to our current view
		m_Frustum.UpdateFrustum(m_Camera.GetViewProj());

		//For adding the draw commands to the draw queue
		int ile = 0;

		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));

		for (int i = 0; i < (2 * m_RenderDistance); i++)
		{
			for (int j = 0; j < (2 * m_RenderDistance); j++)
			{

				glm::vec2 temp = (*Pointer)[i][j].GetChunkPosition();
				if (m_Frustum.IsBoxVisible(glm::vec3(temp.x, 0.0f, temp.y), glm::vec3(temp.x + 16.0f, 128.0f, temp.y + 16.0f)))
				{
					/*
					* Here I should omit the step of saving to a temporary memory and just put the mesh straight into the buffer
					*/

					std::vector<Vertex>* Mesh = (*Pointer)[i][j].GetMeshMatrix();
					std::copy(Mesh->begin(), Mesh->end(), PartitionPointers[ile]);
					Commands.push_back(DrawArraysIndirectCommand(Mesh->size(), 1, ile * CHUNK_VOLUME, 0));
					ile++;

					//In this case, buffer subdata would have been faster.
				}

			}

		}

	}
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void WorldRenderer::UpdateCommandsBuffer(void)
{
	if (Commands.size() != 0)
	{
		GLCall(glBindVertexArray(m_VAO));
		GLCall(glBindBuffer(GL_DRAW_INDIRECT_BUFFER, m_IndirectBufferObject));
		GLCall(glBufferSubData(GL_DRAW_INDIRECT_BUFFER, 0, Commands.size() * sizeof(DrawArraysIndirectCommand), &Commands[0]));
	}
}

void WorldRenderer::Flush(void)
{
	/*
	* Flushes only if the map has been updated
	*/

	if (m_FlushNeeded)
	{
		for (int i = 0; i < Commands.size(); i++)
		{
			for (int j = 0; j < Commands[i].count; j++)
			{

				BufferPointer[Commands[i].first + j] = Vertex();

			}

		}

		m_FlushNeeded = false;

	}		
	
	Commands.clear();
	this->ManageCachedChunks();

}

void WorldRenderer::PrepareCamera(void)
{
	/*
	* Setting up the camera
	*/

	m_Camera.SetAccelerationVector(150.0f);
	m_Camera.SetMouseSensitivity(0.5f);
}

void WorldRenderer::Render(void)
{
	/*
	* Flushing the screen
	*/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor((float)135/255.0f, (float)206 / 255.0f, (float)235 / 255.0f, 1.f); //Code for a color called "Sky Blue"

	/*
	* Checking for movement and getting the mvp for drawing
	*/

	glm::mat4 mvp_last = m_Camera.GetMVP();
	glm::mat4 mvp = m_Camera.CalculateModelViewProjection();

	//Without the movement We do not bother with updating the position
	if (mvp == mvp_last) m_MovementDetected = false;
	else
	{
		m_MovementDetected = true;
		this->SetPlayerCoordinates(m_Camera.GetCameraPosition());
	}
	
	/*
	* Preparing the m_Shader for drawing
	*/

	m_Shader.Bind();
	//
	m_Shader.SetUniformMat4f("mvp", mvp);

	/*
	* Preparing the Buffers for drawing
	*/

	GLCall(glBindVertexArray(m_VAO));
	GLCall(glBindBuffer(GL_DRAW_INDIRECT_BUFFER, m_IndirectBufferObject));

	//Additional settings

	/*
	* This has caused the overall delay and the stagnation of the project.
	* I was having bugs regarding the drawing such as the mesh not displaying correctly.
	* It had some sort of weird, unpredicted and unwanted transparency in it.
	*/

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//It currently has a bug called Z_Buffer_Figthing. Which stands for the flickering that We can see on the screen

	/*
	* Drawing with an easy fail-safe
	*/

	std::cout << Commands.size() << std::endl;

	if (Commands.size() != 0)
	{
		GLCall(glMultiDrawArraysIndirect(GL_TRIANGLES, NULL, Commands.size(), 0));
	}

	//ending procedure
	GLCall(glBindVertexArray(0));
	GLCall(glBindBuffer(GL_DRAW_INDIRECT_BUFFER, 0));
	m_Shader.Unbind();
}
