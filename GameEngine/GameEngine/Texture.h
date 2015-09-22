#pragma once

#include <string>
#include <gl/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	void Bind(unsigned unit);

	static GLint loadTexture(const std::string& fileName);

	~Texture();
private:
	GLuint m_ID;
};