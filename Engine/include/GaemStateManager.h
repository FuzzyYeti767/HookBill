
#pragma once
#include <vector>
#include"GameState.h"
#include"ImGuiHelper.h"
namespace HookBill 
{
	class GameState;

	class GameStateManager {
	public:
		GameStateManager();

		void AddGameState(GameState& gameState);
		void Update();
		void SetNextState(int initState);
		void Shutdown();
		void ReloadState();
		bool HasGameEnded() { return state == State::EXIT; }
		GameState* GetCurrentState() { return currGameState; }
	private:
		enum class State {
			START,
			LOAD,
			UPDATE,
			UNLOAD,
			SHUTDOWN,
			EXIT,
		};

		std::vector<GameState*> gameStates;
		State state;
		GameState* currGameState;
		GameState* nextGameState;
	};
}