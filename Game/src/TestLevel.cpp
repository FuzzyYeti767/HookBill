#include "TestLevel.h"
#include"imgui.h"

HookBill::TestLevel::TestLevel():key(HookBill::InputKey::Keyboard::A)
{
}

void HookBill::TestLevel::Load()
{
	ImGuiHelper::print_and_save_opengl_settings();
	
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

	ImGui::Begin("Program Info");
	{
		

		for (const auto& [label, description] : ImGuiHelper::settings_descriptions)
		{
			ImGui::LabelText(label.c_str(), "%s", description.c_str());
		}
		{
			
		}
	}
	ImGui::End();


	
}

void HookBill::TestLevel::Unload()
{
}
