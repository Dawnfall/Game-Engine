#pragma once

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <string>

#include "obj_loader.h"

class Mesh
{
public:
	Mesh(const std::string& fileName);

	void Draw();

	~Mesh();
protected:

private:
	void Init(const IndexedModel& model);

	enum
	{
		VB_POSITIONS,
		VB_TEXCOORDS,
		VB_NORMALS,

		VB_INDICES,

		VB_NUMBER
	};
	GLuint m_vbo[VB_NUMBER];
	GLuint m_vao;

	unsigned m_drawCount;


};