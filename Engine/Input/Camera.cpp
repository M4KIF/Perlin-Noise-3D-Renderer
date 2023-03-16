#include "Camera.h"
#include<iostream>

Camera::Camera(void)
	:m_Mouse()
{
	m_Mouse.SetMouseSensitivity(0.1f);
	m_Mouse.SetAccelerationVector(0.1f);

	/*Those are only the base values, to be changed by the world config and generation*/


	m_CameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	m_CameraFront = glm::vec3(-1.0f, 0.0f, 1.0f);
	m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	m_Model = glm::mat4(1.0f);
	m_View = glm::mat4(1.0f);
	m_Proj = glm::mat4(1.0f);

	m_Fov = 75.0f;
	m_AspectRatio = 16.0 / 9.0;
	m_zNear = 0.01f;
	m_zFar = 1000.0f;

	m_Window = nullptr;

	m_CameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::Camera(GLFWwindow* window)
	:m_Window(window), m_Mouse(window)
{
	m_Mouse.SetMouseSensitivity(0.1f);
	m_Mouse.SetAccelerationVector(0.1f);

	/*Those are only the base values, to be changed by the world config and generation*/

	m_CameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	m_Model = glm::mat4(1.0f);
	m_View = glm::mat4(1.0f);
	m_Proj = glm::mat4(1.0f);

	m_CameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

	m_Fov = 75.0f;
	m_AspectRatio = 16.0 / 9.0;
}

void Camera::SetCameraPosition(glm::vec3 CameraPosition)
{
	m_CameraPosition = CameraPosition;
	m_Mouse.SetCameraPosition(CameraPosition);
}

void Camera::SetCameraFront(glm::vec3 CameraFront)
{
	m_CameraFront = CameraFront;
	m_Mouse.SetCameraFront(CameraFront);
}

void Camera::SetCameraUp(glm::vec3 CameraUp)
{
	m_CameraUp = CameraUp;
	m_Mouse.SetCameraUp(CameraUp);
}

void Camera::SetWindow(GLFWwindow* window)
{
	m_Window = window;
	m_Mouse.SetActiveWindow(m_Window);
}

glm::vec3 const Camera::GetCameraPosition(void)
{
	return m_Mouse.GetCameraPosition();
}

glm::vec3 const Camera::GetCameraFront(void)
{
	return m_Mouse.GetCameraFront();
}

glm::vec3 const Camera::GetCameraUp(void)
{
	return m_Mouse.GetCameraUp();
}

GLFWwindow* const Camera::GetWindow(void)
{
	return m_Mouse.GetActiveWindow();
}

glm::vec3 Camera::GetCameraRight(void)
{
	m_CameraRight = glm::normalize(glm::cross(m_Mouse.GetCameraUp(), m_Mouse.GetCameraFront()));

	return m_CameraRight;
}

void Camera::GetInput(void)
{
	m_Mouse.Input();
}

glm::mat4 Camera::CalculateModelViewProjection(void)
{
	/*
	* Getting the input
	*/

	m_Mouse.SetActiveWindow(m_Window);
	m_Mouse.Input();

	/*
	* Preparing the variables 
	* for creating the MVP matrix
	*/

	//Calculating the camera components
	m_CameraFront = m_Mouse.GetCameraFront();
	m_CameraPosition = m_Mouse.GetCameraPosition();
	m_CameraUp = m_Mouse.GetCameraUp();

	//calculating the submatrices
	m_Model = glm::translate(glm::mat4(1.0f), m_Translation);
	m_View = glm::lookAt(m_CameraPosition, m_CameraPosition + m_CameraFront, m_CameraUp);
	m_Proj = glm::perspective(glm::radians(m_Fov), m_AspectRatio, m_zNear, m_zFar);

	//Needed for frustum culling
	ProjView = m_Proj * m_View;

	//Calculating the main matrix itself
	MVP =  m_Proj * m_View * m_Model;

	return MVP;
}


