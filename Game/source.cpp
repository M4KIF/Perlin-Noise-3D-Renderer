#define _CRT_SECURE_NO_WARNINGS

#include<thread>
#include<mutex>

#include<glad/glad.h>
#include<glfw3.h>


#include<Engine/WorldCreation/ChunkManager.h>
#include<Engine/WorldCreation/ChunkMesh.h>
#include<Engine/Rendering/WorldRenderer.h>
#include<Engine/BackEnd/Logger.h>


int main(void)
{
    //For logging purposes
    Logger Log;

    /*
    * Variable for containing the window with the currently opened context
    */

    GLFWwindow* window;

    /*Threads variables*/

    std::thread ThreadOne, ThreadTwo;

    /*
    * Initializing the glfw context
    */

    //Logging
    Log.Log("Preparing the glfw and opengl context\n");

    //
    if (!glfwInit())
        return -1;

    //Setting up the OpenGL mode that I want
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /*
    * Create a windowed mode window and its OpenGL context
    */

    window = glfwCreateWindow(1280, 720, "PhySphere", NULL, NULL);
    //Error check
    if (!window)
    {

        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */

    glfwMakeContextCurrent(window);

    // Validate the context
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    glViewport(0, 0, 1280, 720);

    //ImitaRenderer the vsync turned on, limits the framerate in this case to 144hz. IMPORTANT
    glfwSwapInterval(1); 
    
    //Setting the input mode
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    /*Rendering pipeline setup*/

    //Logging
    Log.Log("Setting up the rendering pipeline\n");

    //Creating needed variables
    WorldRenderer Renderer(window, 8);
    Log.Log("The renderer has been created\n");

    //Creating the chunkmap
    Renderer.CreateChunkMap();
    //Creating the terrain for the spawn area
    Renderer.CreateSpawnArea();
    //Creating the rendering pipeline
    Renderer.CreatePipeline(8);
    //Making the pipeline ready
    Renderer.PrepareCamera();

    while (!glfwWindowShouldClose(window))
    {
        while (glGetError() != GL_NO_ERROR);

        /*Thread 1*/
        Renderer.PrepareMeshes();
        /*Thread 2*/
        Renderer.PushCommands();
        Renderer.UpdateCommandsBuffer();
        /*Thread 1*/
        Renderer.Render();

        glEnd();

        /*
        * Swap front and back buffers
        */

        glfwSwapBuffers(window);

        /*
        * Poll for and process events
        */

        glfwPollEvents();
    }
    
    /*Closing the glfw instance before exiting*/
    glfwTerminate();

    return 0;
}
