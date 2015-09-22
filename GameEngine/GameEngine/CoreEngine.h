#pragma once

#include "Game.h"
#include "Display.h"
#include "InputManager.h"
#include "RenderEngine.h"

class CoreEngine
{
public:
	CoreEngine(Game* game);//also game

	void Start(float frameRate);
	void Stop();

	inline Display& GetDisplay() { return m_display; }

	inline void SetFrameRate(float newFrameRate) { m_frameTime = 1.0f / newFrameRate; }

	~CoreEngine();
protected:

private:
	Display m_display; // window
	InputManager m_inputManager; //input
	RenderEngine m_renderEngine; //render engine
	Game* m_game; //game

	bool m_isRunning;

	float m_frameTime;

private:
	void Init(float frameRate);
	void Run();
	void Update();
	void Render();
};