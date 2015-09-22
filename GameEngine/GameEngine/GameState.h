#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include "GameObject.h"
#include "Shader.h"
#include "Mesh.h"
#include "Display.h"
#include "InputManager.h"
#include "Camera.h"

class GameState
{
public:
	GameState(InputManager* inputManager) { m_inputManager = inputManager; };

	virtual void Init() = 0;
	virtual void LoadContent() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	inline void AddShaderProgram(const std::string& shaderProgram, const std::string& key) { m_shaderMap.insert(std::make_pair(key, new Shader(shaderProgram))); }
	inline void AddMesh(const std::string& mesh, const std::string& key) { m_meshMap.insert(std::make_pair(key, new Mesh(mesh))); }

	inline void SetInputManager(InputManager* inputManager){ m_inputManager = inputManager; }
	inline InputManager* GetInputManager(){ return m_inputManager; }

	Shader* GetShader(const std::string& key){ return m_shaderMap.at(key); }
	Mesh* GetMesh(const std::string& key){ return m_meshMap.at(key); }

	~GameState() 
	{
		typedef std::unordered_map<std::string, Shader*>::iterator it_type;
		for (it_type iterator = m_shaderMap.begin(); iterator != m_shaderMap.end(); iterator++)
		{
			delete iterator->second;
		}
		typedef std::unordered_map<std::string, Mesh*>::iterator it_type1;
		for (it_type1 iterator = m_meshMap.begin(); iterator != m_meshMap.end(); iterator++)
		{
			delete iterator->second;
		}
	}

protected:
	std::unordered_map<std::string, Shader*> m_shaderMap;
	std::unordered_map<std::string, Mesh*> m_meshMap;

private:
	InputManager* m_inputManager;

};