#pragma once

/*
* My part
*/

#include<Engine/Input/KeyboardInput.h>

class MouseInput: public KeyboardInput
{
protected:
	/*Config variables*/

	float m_Sensitivity;

	/*Timing variables*/

	double m_LastX, m_LastY;

	/*View angles, pitch, yaw*/

	float m_Pitch;
	float m_Yaw;

	glm::vec3 m_Direction;

public:
	/*Constr/Destruct*/

	MouseInput(void);
	MouseInput(GLFWwindow* window);
	~MouseInput(void);

	/*Sensitivity setter/getter*/

	inline void SetActiveWindow(GLFWwindow* window) { m_Window = window; };
	inline void SetMouseSensitivity(float value) { m_Sensitivity = value; };
	inline float const GetMouseSensitivity(void) { return m_Sensitivity; };
	glm::vec3 const GetDirectionVector(void) { return m_Direction; };

	/*Input getting method*/

	bool Input(void);

};

