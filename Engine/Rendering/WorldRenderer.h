#pragma once

/*
* My Part
*/

#include<Engine/Rendering/Frustum.h>
#include<Engine/Input/Camera.h>
#include<Engine/WorldCreation/ChunkManager.h>
#include<Engine/WorldCreation/ChunkMesh.h>
#include<Engine/BackEnd/Logger.h>

/*
* Here is the struct that is used for creating
* the draw commands list
*/

typedef struct DrawArraysIndirectCommand
{
	/*
	* Needed for the GPU to realise what to do
	* and what to draw to the screen
	*/

	unsigned int count;
	unsigned int primCount;
	unsigned int first;

	// Set by default to zero, according to the documentation
	unsigned int baseInstance = 0;

	/*
	* Constructors and an destructor
	*/

	DrawArraysIndirectCommand() :count(0), primCount(0), first(0), baseInstance(0) {};
	DrawArraysIndirectCommand(unsigned int Count, unsigned int PrimitiveCount, unsigned int Offset, unsigned int BaseInstance)
		: DrawArraysIndirectCommand()
	{
		count = Count;
		primCount = 1;
		first = Offset;
		baseInstance = 0;
	}
	~DrawArraysIndirectCommand() {};
};


class WorldRenderer: public ChunkManager
{
private:

	/*
	* AZDO persistent mapping components
	* and Indirect drawing components
	*/

	std::vector<DrawArraysIndirectCommand> Commands;
	Vertex* BufferPointer;
	std::vector<Vertex*> PartitionPointers;

	/*
	* The window
	*/

	GLFWwindow* m_Window;

	/*
	* Buffers
	*/

	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IndirectBufferObject;

	/*
	* Uniforms
	*/

	glm::mat4 m_MVP;

	/*
	* Obejct needed for drawing
	*/
	
	Camera m_Camera;
	ChunkMesh m_ChunkMesh;
	Frustum m_Frustum;
	Shader m_Shader;

	/*
	* Booleans
	*/

	bool m_FlushNeeded = false;
	bool m_MovementDetected = false;

public:

	/*
	* Constructor/Destructor
	*/

	WorldRenderer(void);
	WorldRenderer(uint16_t BucketCount);
	WorldRenderer(GLFWwindow* window, uint8_t RenderDistance);
	~WorldRenderer(void);

	/*
	* Setup
	*/
	
	void SetWindow(GLFWwindow* window) { m_Window = window; m_Camera.SetWindow(m_Window); };
	void CreatePipeline(uint8_t renderdistance);
	void PrepareCamera(void);

	/*
	* Running methods
	*/

	void PrepareMeshes(void);
	void PushCommands(void);
	void UpdateCommandsBuffer(void);
	void Flush(void);
	void Render(void);

	/*
	* Debug
	*/

	friend std::ostream& operator<<(std::ostream& os, glm::vec3& vector);
	friend std::ostream& operator<<(std::ostream& os, glm::vec4& vector);
};

