#include"GaemStateManager.h"
#include"Engine.h"
namespace HookBill
{
	GameStateManager::GameStateManager() :currGameState(nullptr),
		nextGameState(nullptr), state(State::START)
	{

	}

	void GameStateManager::AddGameState(GameState& gameState)
	{
		gameStates.push_back(&gameState);
	}

	void GameStateManager::Update()
	{

		switch (state)
		{
		case State::START:
			if (gameStates.empty() == true)
			{
				Engine::GetLogger().LogError("No Game States!!");
				state = State::EXIT;
			}
			else
			{
				nextGameState = gameStates[0];
				state = State::LOAD;
			}
			break;
		case State::LOAD:
			currGameState = nextGameState;
			Engine::GetLogger().LogEvent("Load " + currGameState->GetName());
			currGameState->Load();
			Engine::GetLogger().LogEvent("Load Complete");
			state = State::UPDATE;
			break;
		case State::UPDATE:
			if (nextGameState != nullptr)
			{
				state = State::UNLOAD;
			}

			currGameState->Update();
			currGameState->Draw();

			ImGuiHelper::Begin();
			currGameState->ImGuiDraw();
			ImGuiHelper::End(Engine::GetWindow().Get_OpenGL_Window_ptr());

			break;
		case State::UNLOAD:
			Engine::GetLogger().LogEvent("UnLoad " + currGameState->GetName());
			currGameState->Unload();
			if (nextGameState == nullptr)
			{
				state = State::SHUTDOWN;

			}
			else
			{
				state = State::LOAD;

			}
			break;
		case State::SHUTDOWN:
			state = State::EXIT;
			break;
		case State::EXIT:
			break;
		}
	}

	void GameStateManager::SetNextState(int initState)
	{
		nextGameState = gameStates[initState];
	}

	void GameStateManager::Shutdown()
	{
		nextGameState = nullptr;
	}

	void GameStateManager::ReloadState()
	{
		state = State::UNLOAD;
	}


}
