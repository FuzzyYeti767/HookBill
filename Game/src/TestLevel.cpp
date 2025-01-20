#include "TestLevel.h"
#include"imgui.h"
HookBill::TestLevel::TestLevel():key(HookBill::InputKey::Keyboard::A)
{
}

void HookBill::TestLevel::Load()
{
	
	
}

void HookBill::TestLevel::Update()
{
	
	if (key.IsKeyDown())
	{
		Engine::GetLogger().LogEvent("Key released ");
	}
}

void HookBill::TestLevel::Draw()
{
	glClearColor(0.6f, 0.5f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void HookBill::TestLevel::ImGuiDraw()
{
	static bool show_debug_window = true;
	ImGui::Checkbox("Show Debug Window", &show_debug_window);
}

void HookBill::TestLevel::Unload()
{
}
