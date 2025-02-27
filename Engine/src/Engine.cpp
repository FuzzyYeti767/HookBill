#include "Engine.h"

Engine::Engine():logger(HookBill::Logger::Severity::Verbose, true)
{
	timing.start_time = std::chrono::system_clock::now();
	timing.prev_time = timing.start_time;
}

Engine::~Engine()
{
	GetWindow().ShutDown();
}

void Engine::update_timing()
{
	
}

void Engine::Init(std::string windowName)
{
	GetLogger().LogEvent("Initialize Engine");
	window.Init(windowName);
	

}

void Engine::Shutdown()
{

	GetWindow().ShutDown();
}

void Engine::Update()
{


	GetInput().Update();
	GetGameStateManager().Update();
	GetWindow().Update();
	GetTiming().update_timing();
	//ToDo : Input update 
}

bool Engine::HasGameEnded()
{
	return GetGameStateManager().HasGameEnded();
}

bool Engine::ShouldCloseWindow()
{
	return GetGameStateManager().HasGameEnded() || GetWindow().ShouldCloseWindow();
}

