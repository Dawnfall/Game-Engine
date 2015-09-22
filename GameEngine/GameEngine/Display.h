#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>

void windowResize(GLFWwindow* window, int width, int height);

class Display
{
public:
	Display();
	
	bool Init(const std::string& title, int width, int height);

	void Update();

	inline bool GetIsClosed(){ return glfwWindowShouldClose(m_window) == 1; }

	inline int& GetWidth(){ return m_width; }
	inline int& GetHeight(){ return m_height; }

	inline GLFWwindow* GetWindow(){ return m_window; }

	~Display();

private:

protected:

private:

	//window specs
	GLFWwindow* m_window;
	std::string m_title;
	int m_width, m_height;
};