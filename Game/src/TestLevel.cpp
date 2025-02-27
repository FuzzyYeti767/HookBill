#include "TestLevel.h"
#include"imgui.h"
#include<array>
#include"vec2.h"
#include"color3.h"
HookBill::TestLevel::TestLevel():Testkey(HookBill::InputKey::Keyboard::Space)
{
    Engine::GetLogger().LogEvent("Creating TestLevel..");
    shader = GLShader("Basic Shader",{ {GLShader::VERTEX, "../assets/shaders/pass_thru_pos2d_clr.vert"},{GLShader::FRAGMENT, "../assets/shaders/basic_vtx_clr_attribute.frag"} });
    
     
}

void HookBill::TestLevel::Load()
{

	ImGuiHelper::print_and_save_opengl_settings();
    std::vector<vec2> pos_vtx =
    {
        //Fisrt Triangle
        vec2{0.0f,0.75f},  //0
        vec2{-0.7f,-0.55f}, //1
        vec2{0.7f,-0.55f},  //2

        ////Second Triangle
        vec2{-0.7f,0.55f}, //3
        vec2{0.7f,0.55f},  //4
        vec2{0.0f,-0.75f},  //5

    };
    std::vector<color3>clr_vtx =
    {
        color3{1.0f,0.0f,1.0f},
        color3{0.0f,1.0f,1.0f},
        color3{0.0f,0.0f,0.f},

        color3{0.2f,1.0f,0.5f},
        color3{0.4f,0.6f,0.1f},
        color3{0.3f,0.2f,0.7f}
    };
    std::vector<GLuint>idx_vtx =
    {
        0,
        1,
        2,

        //Second Triangle
        3,
        4,
        5,
    };






    GLAttributeLayout position;
    position.component_dimension = GLAttributeLayout::_2;
    position.component_type = GLAttributeLayout::Float;
    position.normalized = false;
    position.offset = 0;
    position.relative_offset = 0;
    position.stride = sizeof(vec2);
    position.vertex_layout_location = 0;


    GLAttributeLayout color;
    color.component_type = GLAttributeLayout::Float;
    color.component_dimension = GLAttributeLayout::_3;
    color.normalized = false;
    color.vertex_layout_location = 1; // 2nd field of Vertex
    color.stride = sizeof(color3);
    color.offset = 0; // starts after the position bytes
    color.relative_offset = 0;

    GLIndexBuffer index(idx_vtx);

    left_eye_model.AddVertexBuffer(GLVertexBuffer(std::span{ pos_vtx }), { position });
    left_eye_model.AddVertexBuffer(GLVertexBuffer(std::span{ clr_vtx }), { color });
    left_eye_model.SetIndexBuffer(std::move(index));
    left_eye_model.SetPrimitivePattern(GLPrimitive::Triangles);
	
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
