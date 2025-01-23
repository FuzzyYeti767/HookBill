#include"Engine.h"
#include"TestLevel.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Fuck You Digipen");
	HookBill::TestLevel test;
	while (!engine.ShouldCloseWindow())
	{
		
		
		Engine::GetGameStateManager().AddGameState(test);

	
		
		engine.Update();
	}
	
	
	
}   