#include"Engine.h"
int main()
{
	Engine& engine = Engine::Instance();
	engine.Init("Fuck You Digipen");
	while (!engine.ShouldCloseWindow())
	{
		engine.Update();
	}
	
	
	
}   