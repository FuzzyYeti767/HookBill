#include "TestLevel.h"
#include"imgui.h"
#include<array>
#include"vec2.h"
#include"color3.h"
HookBill::TestLevel::TestLevel():key(HookBill::InputKey::Keyboard::A)
{
    Engine::GetLogger().LogEvent("Creating TestLevel..");
    shader = GLShader("Basic Shader",
        { {GLShader::VERTEX, "../assets/shaders/pass_thru_pos2d_clr.vert"},
        {GLShader::FRAGMENT, "../assets/shaders/basic_vtx_clr_attribute.frag"} });
  
}

void HookBill::TestLevel::Load()
{
	ImGuiHelper::print_and_save_opengl_settings();

    
    constexpr std::array positions = { vec2{-0.2f, 0.2f}, vec2{-0.2f, 0.6f}, vec2{-0.6f, 0.6f}, vec2{-0.6f, 0.2f} };
    constexpr auto       positions_byte_size = static_cast<long long>(sizeof(vec2) * positions.size());
    constexpr std::array colors = { color3{1, 1, 1}, color3{1, 0, 0}, color3{0, 1, 0}, color3{0, 0, 1} };
    constexpr auto       colors_byte_size = static_cast<long long>(sizeof(color3) * colors.size());
    constexpr auto       buffer_size = positions_byte_size + colors_byte_size;
    GLVertexBuffer       buffer(buffer_size);
    buffer.SetData(std::span(positions));
    buffer.SetData(std::span(colors), positions_byte_size);

    GLAttributeLayout position;
    position.component_type = GLAttributeLayout::Float;
    position.component_dimension = GLAttributeLayout::_2;
    position.normalized = true;
    position.vertex_layout_location = 0;
    position.stride = sizeof(vec2);
    position.offset = 0;
    position.relative_offset = 0;

    GLAttributeLayout color;
    color.component_type = GLAttributeLayout::Float;
    color.component_dimension = GLAttributeLayout::_3;
    color.normalized = true;
    color.vertex_layout_location = 1;
    color.stride = sizeof(color3);
    color.offset = positions_byte_size;
    color.relative_offset = 0;

    left_eye_model.AddVertexBuffer(std::move(buffer), { position, color });

    left_eye_model.SetPrimitivePattern(GLPrimitive::Triangles);

    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };
    GLIndexBuffer                     index_buffer(indices);
    left_eye_model.SetIndexBuffer(std::move(index_buffer));

	
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

    shader.Use();
    left_eye_model.Use();
    GLDrawIndexed(left_eye_model);
    left_eye_model.Use(false);
    shader.Use(false);



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
		{
			
		}
	}
	ImGui::End();
#endif




	
}

void HookBill::TestLevel::Unload()
{
    std::cout << "sex " << '\n';
}
