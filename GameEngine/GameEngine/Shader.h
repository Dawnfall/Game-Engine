#pragma once

#include <gl/glew.h>
#include <glm/glm.hpp>

#include <unordered_map>
#include <string>
#include <array>
#include <vector>

#include "Camera.h"
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void CreateShader(GLenum shaderType, const std::string& fileName);
	void CreateProgram();

	//uniforms
	void AddUniform(const std::string& uniform);
	inline void setUniformi(const std::string& uniformName, int newValue){ glUniform1i(m_uniformMap.at(uniformName), newValue); }
	inline void setUniformf(const std::string& uniformName, float newValue){ glUniform1f(m_uniformMap.at(uniformName), newValue); }
	inline void setUniformVec3(const std::string& uniformName,const glm::vec3& newValue){ glUniform3f(m_uniformMap.at(uniformName), newValue.x, newValue.y, newValue.z); }
	inline void setUniformMat4(const std::string& uniformName, const glm::mat4& newValue){ glUniformMatrix4fv(m_uniformMap.at(uniformName), 1, GL_FALSE, &newValue[0][0]); }

	void Bind();
	void Update(const glm::mat4& VPMatrix, const glm::mat4& modelMatrix);

	static void CheckShaderError(GLuint obj, GLuint flag, bool type, const std::string& message);

	~Shader();
protected:

private:
	unsigned m_numShaders;
	std::unordered_map<std::string, GLuint> m_uniformMap;
	std::vector<GLuint> m_shaderList;
	GLuint m_program;

};