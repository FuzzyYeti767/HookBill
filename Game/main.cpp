#include"Engine.h"
#include"TestLevel.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Fuck You Digipen");
	HookBill::TestLevel test;
	Engine::GetGameStateManager().AddGameState(test);
	while (!engine.ShouldCloseWindow())
	{
			engine.Update();
	}
	
	
	
}   