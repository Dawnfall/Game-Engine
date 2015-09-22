#pragma once

#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3& newTrans = glm::vec3(0, 0, 0), glm::quat rot = glm::quat(1, 0, 0, 0), const glm::vec3& newScale = glm::vec3(1, 1, 1)) :
		m_trans{ newTrans },
		m_rot{ rot },
		m_scale{ newScale }
	{}

	inline glm::vec3& GetTrans() { return m_trans; }
	inline glm::quat& GetRot() { return m_rot; }
	inline glm::vec3& GetScale() { return m_scale; }

	inline glm::mat4 GetModelMatrix() const
	{
		//translation
		glm::mat4 transMatrix = glm::translate(m_trans);

		glm::mat4 a = glm::mat4_cast(m_rot);

		//rotation around different axis

		glm::mat4 rotMatrix = glm::mat4_cast(m_rot);

		//scale
		glm::mat4 scaleMatrix = glm::scale(m_scale);

		//final matrix
		return transMatrix*rotMatrix*scaleMatrix;
	}

	~Transform(){};

protected:

private:
	glm::vec3 m_trans;
	glm::quat m_rot;
	glm::vec3 m_scale;
};