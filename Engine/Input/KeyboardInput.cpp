#include "KeyboardInput.h"

KeyboardInput::KeyboardInput(void)
	:m_Window(nullptr), m_CameraPosition(glm::vec3(0.0f, 0.0f, 0.0f)), m_CameraFront(glm::vec3(-1.0f, 0.0f, 1.0f)), m_CameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	m_MovementSpeed(0.0f), m_deltaTime(0.0f), m_lastFrame(0.0f)
{
	/*Those values can be later replaced to enable world loading from a file, co the camera will be
created right where we left earlier*/
}

KeyboardInput::~KeyboardInput(void)
{
}

bool KeyboardInput::KeyInput(void)
{
	/*Code that synchronises the input with the frametime*/

	m_deltaTime = 0.0f;
	float currentFrame = glfwGetTime();
	m_deltaTime = currentFrame - m_lastFrame;
	if (m_deltaTime == 0) return false;
	m_lastFrame = currentFrame;

	/*Shift movement speed*/

	/*Main input code*/

	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS) m_CameraPosition += (m_MovementSpeed / 5.0f * m_deltaTime) * m_CameraFront;
	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)  m_CameraPosition -= (m_MovementSpeed / 5.0f * m_deltaTime) * m_CameraFront;
	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS) m_CameraPosition -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * (m_MovementSpeed / 5.0f * m_deltaTime);
	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)  m_CameraPosition += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * (m_MovementSpeed / 5.0f * m_deltaTime);
	if (glfwGetKey(m_Window, GLFW_KEY_SPACE) == GLFW_PRESS)  m_CameraPosition += m_CameraUp * (m_MovementSpeed * m_deltaTime);
	if (glfwGetKey(m_Window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)  m_CameraPosition -= m_CameraUp * (m_MovementSpeed * m_deltaTime);
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  exit(0);

	return true;
}
