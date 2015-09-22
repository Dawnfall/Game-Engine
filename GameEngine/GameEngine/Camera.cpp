#include "Camera.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include "Utilities.h"

Camera::Camera(InputManager* inputManager, const glm::vec3& pos, const glm::quat& rot, const glm::vec3& dir, const glm::vec3& up, float fov, float mouseSpeed, float speed, float zNear, float zFar) :
m_inputManager{ inputManager },
m_rot{ rot },
m_pos{ pos },
m_direction{ dir },
m_up{ up },
m_fov{ fov },
m_speed{ speed },
m_mouseSpeed{ mouseSpeed },
m_zNear{ zNear },
m_zFar{ zFar }
{
	std::cerr << m_direction.x << " : " << m_direction.y << " : " << m_direction.z << std::endl;
	RecalculateOrientation();
	CalculateVPMatrix();
}

void Camera::Update()
{
	Input(); //TODO: delete 

	CalculateVPMatrix();
}



void Camera::Rotate(float angle, const glm::vec3& axis)
{

	glm::quat q{ glm::cos(glm::radians(m_mouseSpeed*angle)), glm::sin(glm::radians(m_mouseSpeed*angle))*axis };
	m_rot = q;

	RecalculateOrientation();
}

void Camera::RecalculateOrientation()
{

	glm::mat3 m{ glm::mat3_cast(m_rot) };

	m_direction = m*m_direction;
	m_up = m*m_up;
	m_right = glm::cross(m_direction, m_up);

}

void Camera::Input()
{
	if (m_inputManager->m_keys[87])//w
	{
		m_pos += m_speed * m_direction;
	}
	if (m_inputManager->m_keys[83])//s
	{
		m_pos -= m_speed * m_direction;
	}
	if (m_inputManager->m_keys[65])//a
	{
		m_pos -= m_speed * m_right;
	}
	if (m_inputManager->m_keys[68])//d
	{
		m_pos += m_speed * m_right;
	}

	if (m_inputManager->m_offsetX != 0)
	{
		Rotate(m_inputManager->m_offsetX, m_up);
	}
	if (m_inputManager->m_offsetY != 0)
	{
		Rotate(m_inputManager->m_offsetY, m_right);
	}
}