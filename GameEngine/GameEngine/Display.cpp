#include "Display.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>

Display::Display()
{

}

bool Display::Init(const std::string& title,int width,int height)
{
	m_title = title;
	m_width = width;
	m_height = height;

	//1.glfw initialization
	if (glfwInit() == false)
	{
		std::cerr << "Error! GLFW initialization failure! " << std::endl;
		return false;
	}

	//2. window creation
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!m_window)
	{
		std::cerr << "Error! Window creation failure! " << std::endl;
		return false;
	}

	//3.context creation
	glfwMakeContextCurrent(m_window);

	//4. handle events 
	glfwSetWindowSizeCallback(m_window, windowResize);

	return true;
}

Display::~Display()
{
	glfwTerminate();
}

void Display::Update()
{
	glfwPollEvents();

	glfwGetFramebufferSize(m_window, &m_width, &m_height);

	glfwSwapBuffers(m_window);
}

void windowResize(GLFWwindow* window, int height, int width)
{
	glViewport(0, 0, height, width);
}