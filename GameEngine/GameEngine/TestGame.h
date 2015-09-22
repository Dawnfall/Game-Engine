#pragma once

#include <memory>
#include <iostream>

#include "Game.h"
#include "TestState.h"
#include "InputManager.h"

enum gameStateType
{
	TestStateType
};

class TestGame : public Game
{
public:
	TestGame()
	{
		m_title = "TestGame";
	};

	void Init()
	{
		SetState(std::unique_ptr<GameState>(new TestState(GetInputManager())));
	}

	void Update()
	{
		GetState()->Update();	
	};

	void Render()
	{
		GetState()->Render();
	}

	~TestGame(){};
private:
};