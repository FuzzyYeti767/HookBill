#include "Engine.h"

Engine::Engine():logger(HookBill::Logger::Severity::Verbose, true)
{

}

Engine::~Engine()
{
	GetWindow().ShutDown();
}

void Engine::Init(std::string windowName)
{
	GetLogger().LogEvent("Initialize Engine");
	window.Init("MOM");
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

