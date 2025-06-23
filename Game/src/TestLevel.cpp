#include "TestLevel.h"
#include"imgui.h"
#include<array>
#include"vec2.h"
#include"color3.h"
#include"glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <mat3.h>




HookBill::TestLevel::TestLevel():Testkey(HookBill::InputKey::Keyboard::Space)
{
    Engine::GetLogger().LogEvent("Creating TestLevel..");
   // shader = GLShader("Basic Shader", { {GLShader::VERTEX, "../assets/shaders/pass_thru_pos2d_clr.vert"},{GLShader::FRAGMENT, "../assets/shaders/basic_vtx_clr_attribute.frag"} });
    Engine::GetShaderManager().Load("Basic Shader",
        std::filesystem::path("../assets/shaders/pass_thru_pos2d_clr.vert"),
        std::filesystem::path("../assets/shaders/basic_vtx_clr_attribute.frag"));

    Engine::GetTextureManager().Load("../assets/image/beauty.jpg");
}

void HookBill::TestLevel::Load()
{

	ImGuiHelper::print_and_save_opengl_settings();

}

void HookBill::TestLevel::Update()
{
	
	if (Testkey.IsKeyDown())
	{
		Engine::GetLogger().LogEvent("Key released ");
	}
}



void HookBill::TestLevel::Draw()
{
	glClearColor(118.f/255.f, 181.f/255.f, 197.f/255.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	


}

void HookBill::TestLevel::ImGuiDraw()
{

#ifdef _DEBUG
   
	ImGui::Begin("Program Info");
	{
		
		ImGui::LabelText("FPS", "%.1f", Engine::GetTiming().get_fps());

		for (const auto& [label, description] : ImGuiHelper::settings_descriptions)
		{
			ImGui::LabelText(label.c_str(), "%s", description.c_str());
		}
		ImGui::Separator(); 
		ImGui::Text("Color Settings");
		ImGui::ColorEdit3("UniformColor", glm::value_ptr(currentColor));

		ImGui::Separator();
		
		ImGui::Checkbox("Use Uniform", &UseUniform);



	}
	ImGui::End();
#endif




	
}

void HookBill::TestLevel::Unload()
{
  
}


