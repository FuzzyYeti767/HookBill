#include "Engine.h"

Engine::Engine():logger(HookBill::Logger::Severity::Verbose, true)
{
	
	timing.start_time = std::chrono::system_clock::now();
	timing.prev_time = timing.start_time;
}

Engine::~Engine()
{
	GetLogger().LogEvent("Shut Down Engine");
	Engine::GetShaderManager().Clear();

	GetWindow().ShutDown();
}



void Engine::Init(std::string windowName)
{
	GetLogger().LogEvent("Initialize Engine");
	window.Init(windowName);
	GetMouseInput().Init(window.GetWindowSize().x, window.GetWindowSize().y);
	RegisterSystem([]() { Engine::GetInput().Update(); });
	RegisterSystem([]() { Engine::GetShaderManager().Update(); });
	RegisterSystem([]() { Engine::GetGameStateManager().Update(); });
	RegisterSystem([]() { Engine::GetWindow().Update(); });
	RegisterSystem([]() { Engine::GetTiming().update_timing(); });

}

void Engine::Shutdown()
{

	GetWindow().ShutDown();
}

void Engine::Update()
{

	//for (auto& system : engine_systems) 
	//{
 //      system();
 //   }
	
	GetGameStateManager().Update();
	GetInput().Update();
	double x, y;
	glfwGetCursorPos(Engine::GetWindow().Get_OpenGL_Window_ptr(), &x, &y);  // �Ǵ� SDL_GetMouseState()
    Engine::GetMouseInput().Update((float)x, (float)y);
	Engine::GetShaderManager().Update();
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

