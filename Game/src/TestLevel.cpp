#include "TestLevel.h"
#include"imgui.h"
#include<array>
#include"vec2.h"
#include"color3.h"
#include"glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <mat3.h>

glm::vec3 camPos = glm::vec3(2, 1, 4);
glm::vec3 camTarget = glm::vec3(0, 0, 0);
float camFOV = 60.0f;

void ImGuiCameraControl(Camera& cam, glm::vec3& position, glm::vec3& target, float& fov)
{
    ImGui::Begin("Camera Settings");

    if (ImGui::DragFloat3("Position", &position[0], 0.1f))
        cam.LookAt(position, target, glm::vec3(0, 1, 0));

    if (ImGui::DragFloat3("Target", &target[0], 0.1f))
        cam.LookAt(position, target, glm::vec3(0, 1, 0));

    if (ImGui::SliderFloat("FOV", &fov, 30.0f, 120.0f)) {
        float aspect = static_cast<float>(Engine::GetWindow().GetWindowSize().x) / Engine::GetWindow().GetWindowSize().y;
        cam.SetPerspective(fov, aspect, 0.1f, 100.0f);
    }

    ImGui::End();
}



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

    cam.SetPerspective(60.0f, (float)Engine::GetWindow().GetWindowSize().x / Engine::GetWindow().GetWindowSize().y, 0.1f, 100.0f);
    cam.LookAt(camPos, camTarget, glm::vec3(0, 1, 0));
			
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
	glClearColor(0.6f, 0.5f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glm::mat4 model = glm::mat4(1.0f); // 필요 시 회전/이동 추가

    Engine::GetShaderManager().Get("Basic Shader")->Use();

    cube_mesh.Use(true);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // 와이어프레임



    Engine::GetShaderManager().Get("Basic Shader")->SendUniform("uModel", model);
    Engine::GetShaderManager().Get("Basic Shader")->SendUniform("uView", cam.GetViewMatrix());
    Engine::GetShaderManager().Get("Basic Shader")->SendUniform("uProjection", cam.GetProjectionMatrix());
  
    cube_mesh.Draw();
    cube_mesh.Use(false);
    
    Engine::GetShaderManager().Get("Basic Shader")->Use(false);






}

void HookBill::TestLevel::ImGuiDraw()
{

#ifdef _DEBUG
    ImGuiCameraControl(cam, camPos, camTarget, camFOV);
	/*ImGui::Begin("Program Info");
	{
		
		ImGui::LabelText("FPS", "%.1f", Engine::GetTiming().get_fps());

		for (const auto& [label, description] : ImGuiHelper::settings_descriptions)
		{
			ImGui::LabelText(label.c_str(), "%s", description.c_str());
		}
		{
			
		}
	}
	ImGui::End();*/
#endif




	
}

void HookBill::TestLevel::Unload()
{
  
}


