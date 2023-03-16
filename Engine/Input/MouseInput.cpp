#include "MouseInput.h"

MouseInput::MouseInput(void)
	: KeyboardInput(), m_LastX(0.0f), m_LastY(0.0f)
{

}

MouseInput::MouseInput(GLFWwindow* window)
	: KeyboardInput(window), m_Sensitivity(0.1f), m_LastX(0.f), m_LastY(0.f), m_Pitch(0.f), m_Yaw(0.f)
{
}

MouseInput::~MouseInput(void)
{

}

bool MouseInput::Input(void)
{
	/*GEtting the keyboard input*/

	KeyInput();

	/*Getting the mouse input*/

	double x, y;
	glfwGetCursorPos(m_Window, &x, &y);

	/*Calculating the difference betweeen the previous input*/

	float x_offset, y_offset;
	x_offset = x - m_LastX;
	y_offset = y - m_LastY;

	m_LastX = x;
	m_LastY = y;
	x_offset *= m_Sensitivity;
	y_offset *= m_Sensitivity;

	/*Final result with correction checking*/

	m_Yaw += x_offset;
	m_Pitch += y_offset;
	if (m_Pitch > 90.0f) m_Pitch = 89.9f;
	if (m_Pitch < -90.0f) m_Pitch = -89.9f;
	//if (m_Yaw > 89.0f) m_Yaw = 89.0f;
	//if (m_Yaw < -89.0f) m_Yaw = -89.0f;

	/*Creating the CameraFront vector out of a few calculations with camera angle limits checking*/

	float result = sin(glm::radians(m_Pitch)) * cos(glm::radians(m_Pitch));

	if (fabs(result - 1.0f) < 0.001) m_Direction.y = 1.0f;
	else m_Direction.y = result;

	m_Direction.x =cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Direction.z =sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_CameraFront = glm::normalize(m_Direction);

	return true;
}
