#include "TestLevel2.h"
#include"imgui.h"
#include<array>
#include"vec2.h"
#include"color3.h"
#include"glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <mat3.h>




HookBill::TestLevel2::TestLevel2() :Testkey(HookBill::InputKey::Keyboard::Space)
{
	Engine::GetLogger().LogEvent("Creating TestLevel..");
	// shader = GLShader("Basic Shader", { {GLShader::VERTEX, "../assets/shaders/pass_thru_pos2d_clr.vert"},{GLShader::FRAGMENT, "../assets/shaders/basic_vtx_clr_attribute.frag"} });
	Engine::GetShaderManager().Load("Basic Shader",
		std::filesystem::path("../assets/shaders/pass_thru_pos2d_clr.vert"),
		std::filesystem::path("../assets/shaders/basic_vtx_clr_attribute.frag"));

	Engine::GetTextureManager().Load("../assets/image/beauty.jpg");
	Engine::GetTextureManager().Load("../assets/image/container.jpg");
}

void HookBill::TestLevel2::Load()
{

	ImGuiHelper::print_and_save_opengl_settings();
	std::array<glm::vec2, 4> positions_data =
	{
		glm::vec2(-0.5f, -0.5f), // 왼쪽 아래
		glm::vec2(0.5f, -0.5f), // 오른쪽 아래
		glm::vec2(0.5f,  0.5f), // 오른쪽 위
		glm::vec2(-0.5f,  0.5f)  // 왼쪽 위
	};

	GLVertexBuffer positions(std::span{ positions_data });


	std::array<color3, 4> colors_data =
	{
		color3(1.0f, 0.0f, 0.0f),
		color3(0.0f, 1.0f, 0.0f),
		color3(0.0f, 0.0f, 1.0f),
		color3(0.2f, 0.3f, 0.4f)
	};

	GLVertexBuffer colors(std::span{ colors_data });

	std::array<const unsigned, 6> indices_data =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLIndexBuffer indices(std::span{ indices_data });

	std::array<glm::vec2, 4> texture_cordinate_data =
	{
		glm::vec2(0.0f, 0.0f), // 왼쪽 아래
		glm::vec2(1.0f, 0.0f), // 오른쪽 아래
		glm::vec2(1.0f, 1.0f), // 오른쪽 위
		glm::vec2(0.0f, 1.0f)  // 왼쪽 위
	};

	GLVertexBuffer texture_cordinates(std::span{ texture_cordinate_data });



	GLAttributeLayout position_layout;
	position_layout.component_type = GLAttributeLayout::ComponentType::Float;
	position_layout.component_dimension = GLAttributeLayout::NumComponents::_2;
	position_layout.vertex_layout_location = 0;
	position_layout.normalized = GL_FALSE;
	position_layout.relative_offset = 0;
	position_layout.offset = 0;
	position_layout.stride = sizeof(glm::vec2);


	GLAttributeLayout color_layout;
	color_layout.component_type = GLAttributeLayout::ComponentType::Float;
	color_layout.component_dimension = GLAttributeLayout::NumComponents::_3;
	color_layout.vertex_layout_location = 1;
	color_layout.normalized = GL_FALSE;
	color_layout.relative_offset = 0;
	color_layout.offset = 0;
	color_layout.stride = sizeof(color3);

	GLAttributeLayout texture_cordinate_layout;
	texture_cordinate_layout.component_type = GLAttributeLayout::ComponentType::Float;
	texture_cordinate_layout.component_dimension = GLAttributeLayout::NumComponents::_2;
	texture_cordinate_layout.vertex_layout_location = 2;
	texture_cordinate_layout.normalized = GL_FALSE;
	texture_cordinate_layout.relative_offset = 0;
	texture_cordinate_layout.offset = 0;
	texture_cordinate_layout.stride = sizeof(glm::vec2);



	Triangle_Model.SetPrimitivePattern(GLPrimitive::Triangles);
	Triangle_Model.AddVertexBuffer(std::move(positions), { position_layout });
	Triangle_Model.AddVertexBuffer(std::move(colors), { color_layout });
	Triangle_Model.AddVertexBuffer(std::move(texture_cordinates), { texture_cordinate_layout });
	Triangle_Model.SetIndexBuffer(std::move(indices));
}

void HookBill::TestLevel2::Update()
{

	if (Testkey.IsKeyDown())
	{
		Engine::GetLogger().LogEvent("Key released ");
	}
}



void HookBill::TestLevel2::Draw()
{
	glClearColor(118.f / 255.f, 181.f / 255.f, 197.f / 255.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	Engine::GetShaderManager().Use("Basic Shader", true);
	Triangle_Model.Use();
	Engine::GetTextureManager().Load("../assets/image/beauty.jpg")->UseForSlot(3, *(Engine::GetShaderManager().Get("Basic Shader")), "Utex2d");
	Engine::GetTextureManager().Load("../assets/image/comet.jpg")->UseForSlot(4, *(Engine::GetShaderManager().Get("Basic Shader")), "Utex2d1");
	//파일이름에 확장자만 있고 이름이 없었음
	GLDrawIndexed(Triangle_Model);
	Triangle_Model.Use(false);
	Engine::GetShaderManager().Use("Basic Shader", false);

}

void HookBill::TestLevel2::ImGuiDraw()
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

void HookBill::TestLevel2::Unload()
{

}


