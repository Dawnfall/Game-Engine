#include "Shader.h"

#include <gl/glew.h>
#include <iostream>
#include <string>
#include <fstream>

#include "LoadUtil.h"
#include "Camera.h"
#include "Transform.h"

Shader::Shader(const std::string& fileName)
{
	CreateShader(GL_VERTEX_SHADER, fileName + ".vs");
	CreateShader(GL_GEOMETRY_SHADER, fileName + ".gs");
	CreateShader(GL_FRAGMENT_SHADER, fileName + ".fs");

	CreateProgram();
}

void Shader::CreateShader(GLenum shaderType, const std::string& fileName)
{
	//load data from file
	std::string fileShaderData = LoadUtil::LoadShader(fileName);
	if (fileShaderData == "")
	{
		return;
	}

	const GLchar* shaderData[1];
	GLint shaderDataLength[1];
	shaderData[0] = fileShaderData.c_str();
	shaderDataLength[0] = fileShaderData.length();

	//create shader
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0)
		std::cerr << "Error: Shader creation failure!" << std::endl;

	//upload shader
	glShaderSource(shader, 1, shaderData, shaderDataLength);
	glCompileShader(shader);

	m_shaderList.push_back(shader);

	//check for errors
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failure! : " + fileName);
}

void Shader::CreateProgram()
{
	//create program and apply shaders
	m_program = glCreateProgram();
	for each (GLuint shader in m_shaderList)
		glAttachShader(m_program, shader);

	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");
	glBindAttribLocation(m_program, 2, "normal");

	//link,validate and check for errors
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failure");
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program validation failure");

	//delete shaders
	for each(GLuint shader in m_shaderList)
	{
		glDetachShader(m_program, shader);
		glDeleteShader(shader);
	}
}

void Shader::AddUniform(const std::string& uniform)
{
	GLuint uniLocation = glGetUniformLocation(m_program, uniform.c_str());
	std::cerr << uniLocation << std::endl;

	if (uniLocation == 0xFFFFFFFF)
	{
		std::cerr << "Error: " << uniform << " uniform cannot be found" << std::endl;
	}

	m_uniformMap.insert(std::make_pair(uniform, uniLocation));
}




void Shader::Bind()
{
	glUseProgram(m_program);
}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

void Shader::CheckShaderError(GLuint obj, GLuint flag, bool type, const std::string& message)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (type == true)
		glGetProgramiv(obj, flag, &success);
	else if (type == false)
		glGetShaderiv(obj, flag, &success);

	if (success == GL_FALSE)
	{
		if (type == true)
			glGetProgramInfoLog(obj, sizeof(error), NULL, error);
		else if (type == false)
			glGetShaderInfoLog(obj, sizeof(error), NULL, error);

		std::cerr << message << " : " << error << " ' " << std::endl;
	}
}