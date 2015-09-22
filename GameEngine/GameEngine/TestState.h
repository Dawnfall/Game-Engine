#pragma once

#include "Shader.h"
#include "Mesh.h"

#include <vector>
#include "GameState.h"
#include "InputManager.h"
#include "Transform.h"
#include "Texture.h"


class TestState :public GameState
{
public:
	TestState(InputManager* inputManager) :GameState(inputManager), m_texture("./res/bricks.jpg")
	{
		Init();
	};

	void Init()
	{
		LoadContent();
	};
	void LoadContent()
	{
		AddMesh("./res/monkey3.obj", "monkey");
		AddShaderProgram("./res/basicShader", "basicShader");

		m_shaderMap.at("basicShader")->AddUniform("MVPtransform");
		m_shaderMap.at("basicShader")->AddUniform("gSampler");

		m_camera.SetInputManager(GetInputManager());

		m_shaderMap.at("basicShader")->setUniformi("gSampler", 0);
	};
	void Update()
	{
		m_camera.Update();
		//**************************
		m_shaderMap.at("basicShader")->setUniformMat4("MVPtransform", m_camera.GetVPMatrix()*m_transform.GetModelMatrix());


		//*************************
	};

	void Render()
	{
		m_shaderMap.at("basicShader")->Bind();
		m_texture.Bind(0);
		m_meshMap.at("monkey")->Draw();;
	}

	~TestState(){};

private:

	Camera m_camera;
	Transform m_transform;
	Texture m_texture;




};