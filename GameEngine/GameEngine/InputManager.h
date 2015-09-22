#pragma once

#include <glfw/glfw3.h>
#include "Utilities.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

class InputManager
{
public:
	InputManager();

	void Init(GLFWwindow* window);

	void Update();
	void SetWindow(GLFWwindow* window);

	~InputManager();

	//keyboard
	bool m_keys[256];

	//mouse
	double m_mousePosX;
	double m_mousePosY;
	float m_offsetX;
	float m_offsetY;

	bool m_mouseButtons[3];

protected:

private:

	GLFWwindow *m_window;
};