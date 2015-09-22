#include "Texture.h"

#include <gl/glew.h>
#include <string>
#include <iostream>
#include <cassert>

#include "stb_image.h"

Texture::Texture(const std::string& fileName)
{
	int width, height, numComponents;
	unsigned char* imageData;
	try
	{
		imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

		if (imageData == NULL)
			throw 20;
	}
	catch (int e)
	{
		std::cerr << "Error: Loading texture failure! : " << fileName << std::endl;
	}
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, GL_FALSE, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

void Texture::Bind(unsigned unit)
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_ID);
}
