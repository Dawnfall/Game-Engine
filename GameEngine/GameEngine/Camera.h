#pragma once

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Transform.h"
#include "InputManager.h"

#define PI 3.14159265f

class Camera
{
public:
	Camera(InputManager* inputManager = nullptr, const glm::vec3& pos = glm::vec3(0, 0, 5), const glm::quat& rot = glm::quat(1, 0, 0, 0), const glm::vec3& dir = glm::vec3(0, 0, -1), const glm::vec3& up=glm::vec3(0,1,0), float fov = 70.0f, float mouseSpeed = 0.01, float speed = 0.02, float zNear = 0.1f, float zFar = 1000.0f); //change speed values!

	void haha(){};
	virtual void Input();
	virtual void Update();

	void RecalculateOrientation();

	void Rotate(float angle, const glm::vec3& axis);

	inline glm::vec3 GetDirection(){ return m_direction; }

	inline void CalculateVPMatrix(){ m_VPMatrix = glm::perspective(m_fov, 4.0f / 3.0f, m_zNear, m_zFar) * glm::lookAt(m_pos, m_pos + m_direction, m_up); }
	inline glm::mat4 &GetVPMatrix(){ return m_VPMatrix; }

	//******setters
	inline void SetPos(const glm::vec3& pos){ m_pos = pos; }
	inline void SetFOV(float fov){ m_fov = fov; }
	inline void SetMouseSpeed(float mouseSpeed){ m_mouseSpeed = mouseSpeed; }
	inline void SetSpeed(float speed){ m_speed = speed; }
	inline void setZNear(float zNear){ m_zNear = zNear; }
	inline void setZFar(float zFar){ m_zFar = zFar; }
	inline void SetInputManager(InputManager* inputManager){ m_inputManager = inputManager; }
	//***********

	~Camera(){};

protected:

private:
	//MVP matrix
	glm::mat4 m_VPMatrix;

	//camera orientation
	glm::vec3 m_direction;
	glm::vec3 m_right;
	glm::vec3 m_up;

	//***camera params
	glm::vec3 m_pos;
	glm::quat m_rot;
	float m_fov;
	float m_zNear;
	float m_zFar;
	float m_speed; //for movement
	float m_mouseSpeed;//for rotation

	InputManager* m_inputManager;
};