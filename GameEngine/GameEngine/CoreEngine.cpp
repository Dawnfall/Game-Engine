#include "CoreEngine.h"

#include <iostream>
#include <thread>
#include <chrono>

#include "Display.h"
#include "Game.h"
#include "Time.h"


CoreEngine::CoreEngine(Game* game)
{
	m_game = game;
	m_game->SetInputManager(&m_inputManager);
	m_isRunning = false;
}

void CoreEngine::Start(float frameRate)
{
	if (!m_isRunning)
	{
		m_isRunning = true;
		Init(frameRate);
		Run();
	}

}

void CoreEngine::Init(float frameRate)
{
	SetFrameRate(frameRate);

	m_display.Init(m_game->GetTitle(), 800, 600); //TODO: width,height game parameters
	m_renderEngine.InitGraphics();
	m_inputManager.Init(m_display.GetWindow());
	
	m_game->Init();

	//std::cerr << (m_game->GetInputManager() == nullptr) << std::endl;
	//std::cerr << (m_game->GetState()->GetInputManager() == nullptr) << std::endl;
	//std::cerr << (m_game->GetState() == nullptr) << std::endl;
	
}

void CoreEngine::Stop()
{
	if (m_isRunning)
		m_isRunning = false;
}

void CoreEngine::Run()
{
	m_isRunning = true;

	int frames = 0;
	double frameCounter = 0;

	double lastTime = Time::GetTime();
	double unprocessedTime = 0;

	bool doRender;

	//main loop here
	while (m_isRunning)
	{
		doRender = false;

		double startTime = Time::GetTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime;

		frameCounter += passedTime;

		//unprocessed time
		while (unprocessedTime > m_frameTime)
		{
			//std::cerr << "Processing" << std::endl; //TODO: delete

			doRender = true;
			unprocessedTime -= m_frameTime;

			//when exit is requested
			if (m_display.GetIsClosed())
			{
				Stop();
			}

			if (frameCounter >= 1.0f)
			{
				std::cout << frames << std::endl;
				frameCounter = 0;
				frames = 0;
			}
			Update();

		}

		if (doRender) //fps counter
		{
			Render();
			frames++;
		}
		else
		{
			try
			{
				std::this_thread::sleep_for(std::chrono::microseconds(1));
			}
			catch (int e)
			{
				std::cerr << "Error: Cant sleep" << std::endl;
			}
		}
	}
}

void CoreEngine::Update()
{
	m_inputManager.Update();
	m_game->Update();
}
void CoreEngine::Render()
{
	m_renderEngine.Clear();
	m_game->Render();

	//m_renderEngine.Render(m_game);

	//***updating buffers
	m_display.Update();
}

CoreEngine::~CoreEngine()
{

}