#include"Engine.h"
#include"TestLevel.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Test Engine Please Ignore");
	HookBill::TestLevel test;
	Engine::GetGameStateManager().AddGameState(test);
	while (!engine.ShouldCloseWindow())
	{
			engine.Update();
	}
	
	
	
}   