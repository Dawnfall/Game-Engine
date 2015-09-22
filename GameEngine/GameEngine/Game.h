#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "GameState.h"
#include "InputManager.h"

//has all the data about the game...provided by user
class Game
{
public:
	Game(){};
	//Game(const Game& g) { std::cerr << "copy constructor"; }

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	inline std::string& GetTitle() { return m_title; }
	inline void SetState(std::unique_ptr<GameState>& gameState)
	{
		m_gameState.reset(gameState.release());
	}

	GameState* GetState(){ return m_gameState.get(); }

	inline void SetInputManager(InputManager *inputManager){ m_inputManager = inputManager; }
	inline InputManager* GetInputManager(){ return m_inputManager; }

	~Game(){};

protected:
	std::string m_title;

private:

	InputManager* m_inputManager;
	std::unique_ptr<GameState> m_gameState; //gameState
};