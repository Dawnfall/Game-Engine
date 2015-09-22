#include "InputManager.h"

#include <iostream>
#include <GLFW/glfw3.h>
//#include "Utilities.h"

void scroll_callback(GLFWwindow* window, double scrollOffsetX, double scrollOffsetY)
{

}

InputManager::InputManager()
{

}

void InputManager::Init(GLFWwindow* window) //TODO: other options for input
{
	SetWindow(window);

	if (m_window != nullptr)
	{
		glfwSetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS, 1);
		glfwSetScrollCallback(m_window, scroll_callback);
	}
	int w, h;
	glfwGetWindowSize(m_window, &w, &h);
	glfwSetCursorPos(m_window, (double)w / 2, (double)h / 2);
}

void InputManager::Update()
{
	glfwPollEvents();

	//******keyboard stuff*******************
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		m_keys[27] = true;
	}
	else
		m_keys[27] = false;

	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		m_keys[87] = true;
	else
		m_keys[87] = false;

	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		m_keys[83] = true;
	else
		m_keys[83] = false;

	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		m_keys[65] = true;
	else
		m_keys[65] = false;

	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		m_keys[68] = true;
	else
		m_keys[68] = false;

	if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
		m_keys[32] = true;
	else
		m_keys[32] = false;

	if (glfwGetKey(m_window, GLFW_KEY_ENTER) == GLFW_PRESS)
		m_keys[13] = true;
	else
		m_keys[13] = false;
	//*******************************

	//*****mouse stuff***************
	glfwGetCursorPos(m_window, &m_mousePosX, &m_mousePosY); //for cursor coords
	int w, h;
	glfwGetWindowSize(m_window, &w, &h);
	m_offsetX = (double)w / 2 - m_mousePosX;
	m_offsetY = (double)h / 2 - m_mousePosY;
	glfwSetCursorPos(m_window, (double)w / 2, (double)h / 2);

	if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		m_mouseButtons[0] = true;
	else
		m_mouseButtons[0] = false;

	if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
		m_mouseButtons[1] = true;
	else
		m_mouseButtons[1] = false;

	if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		m_mouseButtons[2] = true;
	else
		m_mouseButtons[2] = false;
	//*****************************
}

void InputManager::SetWindow(GLFWwindow* window)
{
	m_window = window;
}

InputManager::~InputManager()
{

}
