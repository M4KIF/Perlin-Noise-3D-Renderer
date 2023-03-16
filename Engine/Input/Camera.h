#pragma once

/*
* Custom 3D Libraries
*/

#include<glad/glad.h>
#include<glfw3.h>
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>

/*
* My part
*/

#include<Engine/Input/MouseInput.h>


class Camera
{
protected:
	/*
	* The window pointer
	*/

	GLFWwindow* m_Window;

	/*
	* model * view * projection matrix parts
	*/

	glm::mat4 m_Model;
	glm::mat4 m_View;
	glm::mat4 m_Proj;
	glm::vec3 m_Translation;

	/*
	* Variables in charge of creating the view matrix
	*/
	glm::vec3 m_CameraTarget;
	glm::vec3 m_CameraDirection;

	glm::vec3 m_CameraPosition;
	glm::vec3 m_CameraFront;
	glm::vec3 m_CameraUp;
	glm::vec3 m_CameraRight;

	glm::mat4 ProjView = glm::mat4(0.0f);
	glm::mat4 MVP;

	/*
	* Settings specifific variables
	*/

	float m_Fov;
	float m_AspectRatio;
	float m_zNear;
	float m_zFar;

	/*
	* Object in charge of the input
	*/

	MouseInput m_Mouse;

	/*
	* Booleans
	*/

	bool m_IsMoving;

public:

	/*
	* Contructor/Destructor
	*/

	Camera(void);
	Camera(GLFWwindow* window);
	~Camera(void) {};

	/*
	* Setters and getters
	*/

	//Set config
	void SetWindow(GLFWwindow* window);
	void SetCameraPosition(glm::vec3 CameraPosition);
	void SetCameraFront(glm::vec3 CameraFront);
	void SetCameraUp(glm::vec3 CameraUp);
	void SetFov(float fov) { m_Fov = fov; }
	void SetAspectRatio(float AspectRatio) { m_AspectRatio = AspectRatio; }
	void SetFarPlane(float FarPlane) { m_zFar = FarPlane; };
	void SetNearPlane(float NearPlane) { m_zNear = NearPlane; };

	//Get config
	GLFWwindow* const GetWindow(void);
	glm::vec3 const GetCameraPosition(void);
	glm::vec3 const GetCameraFront(void);
	glm::vec3 const GetCameraUp(void);
	inline float const GetFov(void) { return m_Fov; }
	inline float const GetAspectRatio(void) { return m_AspectRatio; }
	inline float GetFarPlane(void) { return m_zFar; };
	inline float GetNearPlane(void) { return m_zNear; };
	glm::vec3 GetCameraRight(void);
	glm::mat4 GetViewProj(void) { return ProjView; }
	glm::mat4 GetMVP(void) { return MVP; }
	glm::mat4 GetModel(void) { return m_Model; };

	//Movement
	inline void SetMouseSensitivity(float value) { m_Mouse.SetMouseSensitivity(value); };
	inline void SetAccelerationVector(float value) { m_Mouse.SetAccelerationVector(value); };
	inline float const GetMouseSensitivity(void) { return m_Mouse.GetMouseSensitivity(); };
	inline float const GetAccelerationVector(void) { return m_Mouse.GetAccelerationVector(); };

	/*Setup and getting the results*/

	void GetInput(void);
	glm::mat4 CalculateModelViewProjection(void);
	bool IsMoving(void) { return m_IsMoving; };

};

