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

	constexpr std::array positions = { vec2{0.5f, -0.5f}, vec2{-0.5f,-0.5f}, vec2{0.0f,0.5f} };
	constexpr std::array colors = { color3{0, 0, 1}, color3{1, 1, 1}, color3{1, 0, 0} };
	constexpr std::array<unsigned char,3> indices = { 0, 1, 2};


	GLVertexBuffer    position_buffer(std::span{ positions });
	GLVertexBuffer    colors_buffer(std::span{ colors });


	GLAttributeLayout position;
	position.component_type = GLAttributeLayout::Float;
	position.component_dimension = GLAttributeLayout::_2;
	position.normalized = false;
	position.vertex_layout_location = 0; // 1st field is 0 index based
	position.stride = sizeof(vec2);
	position.offset = 0;
	position.relative_offset = 0;

	GLAttributeLayout color;
	color.component_type = GLAttributeLayout::Float;
	color.component_dimension = GLAttributeLayout::_3;
	color.normalized = false;
	color.vertex_layout_location = 1; // 2nd field of Vertex
	color.stride = sizeof(color3);
	color.offset = 0; // starts after the position bytes
	color.relative_offset = 0;

	Triangle_Model.AddVertexBuffer(std::move(position_buffer), { position });
	Triangle_Model.SetPrimitivePattern(GLPrimitive::Triangles);
	Triangle_Model.AddVertexBuffer(std::move( colors_buffer ) , { color });
	GLIndexBuffer                     index_buffer(indices);
	Triangle_Model.SetIndexBuffer(std::move(index_buffer));
	Triangle_Model.SetVertexCount(3);
}

void HookBill::TestLevel::Update()
{
	
	if (Testkey.IsKeyDown())
	{
		Engine::GetLogger().LogEvent("Key released ");
	}
	//GLuint vbo_handle = Triangle_Model.GetVertexBuffers()[0].GetHandle();

	//// 버퍼를 매핑
	//void* ptr = glMapNamedBuffer(vbo_handle, GL_WRITE_ONLY);

	//if (ptr)
	//{
	//	vec2* mapped_positions = static_cast<vec2*>(ptr);
	//	mapped_positions[0] = vec2{ -0.4f, 0.8f };

	//	// 반드시 언매핑
	//	glUnmapNamedBuffer(vbo_handle);
	//}
	//else
	//{
	//	Engine::GetLogger().LogEvent(std::to_string(vbo_handle));

	//}


}



void HookBill::TestLevel::Draw()
{
	glClearColor(118.f/255.f, 181.f/255.f, 197.f/255.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   Engine::GetShaderManager().Get("Basic Shader")->Use();
   Engine::GetShaderManager().Get("Basic Shader")->SendUniform("ourColor", currentColor.x,currentColor.y,currentColor.z);

   //비용이 비싸기 떄문에 glGetUniformLocation은 init나 로드에서 계산하고 돌려서 써야함
   glUniform1i(glGetUniformLocation(Engine::GetShaderManager().Get("Basic Shader")->program_handle, "useUniform"),UseUniform);



    Triangle_Model.Use();
	GLDrawArrayInstanced(Triangle_Model, 2);
	//GLDrawElementInstanced(Triangle_Model, 5);
	Triangle_Model.Use(false);
	Engine::GetShaderManager().Get("Basic Shader")->Use(false);


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


