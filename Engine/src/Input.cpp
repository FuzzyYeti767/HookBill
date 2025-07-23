#include"Input.h"
#include"Engine.h"
namespace HookBill
{
	Input::Input()
	{
		keyDown.resize(static_cast<int>(InputKey::Keyboard::Count), false);
		wasKeyDown.resize(static_cast<int>(InputKey::Keyboard::Count), false);
		keyReleased.resize(static_cast<int>(InputKey::Keyboard::Count), false);
		//wasKeyReleased.resize(static_cast<int>(InputKey::Keyboard::Count), false);
	}

	bool Input::IsKeyDown(InputKey::Keyboard key) const
	{
		return keyDown[static_cast<int>(key)];
	}

	bool Input::IsKeyReleased(InputKey::Keyboard key) const
	{
		
		return  (keyDown[static_cast<int>(key)]==false) && (wasKeyDown[static_cast<int>(key)] == true);
	}

	void Input::SetKeyDown(InputKey::Keyboard key, bool value)
	{
	
		keyDown[static_cast<int>(key)] = value;
	}

	void Input::SetKeyReleased(InputKey::Keyboard key, bool value)
	{
		keyReleased[static_cast<int>(key)] = value;
	}

	void Input::Update()
	{
		
		wasKeyDown = keyDown;
	}
	
	InputKey::InputKey(Keyboard button_):button(button_)
	{

	}

	bool InputKey::IsKeyDown() const
	{
		return Engine::GetInput().IsKeyDown(button);
	}

	bool InputKey::IsKeyReleased() const
	{
		return Engine::GetInput().IsKeyReleased(button);;
	}

	
}