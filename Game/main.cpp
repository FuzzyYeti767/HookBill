#include"Engine.h"
#include"TestLevel.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Fuck You Digipen");
	while (!engine.ShouldCloseWindow())
	{
		
		HookBill::TestLevel test;
		Engine::GetGameStateManager().AddGameState(test);

	
		
		engine.Update();
	}
	
	
	
}   