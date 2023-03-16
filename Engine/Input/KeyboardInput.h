#pragma once

/*
* Custom 3D Libraries
*/

#include<glad/glad.h>
#include<glfw3.h>
#include<glm.hpp>

class KeyboardInput
{
protected:
	/*The view matrix and window pointer*/

	GLFWwindow* m_Window;

	/*Variables in charge of creating the view matrix*/

	glm::vec3 m_CameraPosition;
	glm::vec3 m_CameraFront;
	glm::vec3 m_CameraUp;

	/*Config variables*/

	float m_MovementSpeed;

	/*Timing variables*/

	float m_deltaTime;
	float m_lastFrame;

public:

	/*Constr/Destr*/

	KeyboardInput(void);
	inline KeyboardInput(GLFWwindow* window) :m_Window(window) {};
	~KeyboardInput(void);

	/*Setters and getters*/
	//Set config
	inline void SetActiveWindow(GLFWwindow* window) { m_Window = window; };
	inline void SetCameraPosition(glm::vec3 Position) { m_CameraPosition = Position; };
	inline void SetCameraFront(glm::vec3 CameraFront) { m_CameraFront = CameraFront; };
	inline void SetCameraUp(glm::vec3 CameraUp) { m_CameraUp = CameraUp; };
	//Get config
	inline glm::vec3 GetCameraPosition(void) { return m_CameraPosition; };
	inline glm::vec3 GetCameraFront(void) { return m_CameraFront; };
	inline glm::vec3 GetCameraUp(void) { return m_CameraUp; };
	inline GLFWwindow* GetActiveWindow(void) { return m_Window; };
	//Movement variables
	inline void SetAccelerationVector(float value) { m_MovementSpeed = value; };
	inline float GetAccelerationVector(void) { return m_MovementSpeed; };

	/*Movement checking method*/

	bool KeyInput(void);

};

