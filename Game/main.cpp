#include"Engine.h"
#include"TestLevel.h"
#include"TestLevel2.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Test Engine Please Ignore");
	HookBill::TestLevel test;
	HookBill::TestLevel2 test2;
	Engine::GetGameStateManager().AddGameState(test);
	Engine::GetGameStateManager().AddGameState(test2);
	while (!engine.ShouldCloseWindow())
	{
			engine.Update();
	}
	
	
	
}   