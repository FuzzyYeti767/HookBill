#include "TestLevel2.h"
#include "imgui.h"
#include <array>
#include "vec3.h"
#include "color3.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <mat3.h>

HookBill::TestLevel2::TestLevel2() : Testkey(HookBill::InputKey::Keyboard::Space),
camera(glm::vec3(0.0f, 0.0f, 3.0f), -90.f, 0.0f, 45.0f, 16.0f / 9.0f, 0.1f, 100.f),
Up(HookBill::InputKey::Keyboard::W), Down(HookBill::InputKey::Keyboard::S), Left(HookBill::InputKey::Keyboard::A), Right(HookBill::InputKey::Keyboard::D)
{

    Engine::GetLogger().LogEvent("Creating TestLevel with Cube..");
    Engine::GetShaderManager().Load("Basic Shader",
        std::filesystem::path("../assets/shaders/pass_thru_pos2d_clr.vert"),
        std::filesystem::path("../assets/shaders/basic_vtx_clr_attribute.frag"));

    Engine::GetTextureManager().Load("../assets/image/beauty.jpg");
	
}

void HookBill::TestLevel2::Load()
{
    glEnable(GL_DEPTH_TEST);
    ImGuiHelper::print_and_save_opengl_settings();

    std::array<glm::vec3, 24> cube_vertices = {
        // Front face
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, 0.5f),
        // Back face
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Left face
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Right face
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        // Top face
        glm::vec3(-0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Bottom face
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(-0.5f, -0.5f, -0.5f)
    };


    std::array<glm::vec3, 24> color =
    {
        // Front face
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, 0.5f),
        // Back face
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Left face
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, 0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Right face
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        // Top face
        glm::vec3(-0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f, 0.5f, -0.5f),
        glm::vec3(-0.5f, 0.5f, -0.5f),
        // Bottom face
        glm::vec3(-0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, 0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(-0.5f, -0.5f, -0.5f)
    };



    std::array<glm::vec2, 24> texture_cordinate_data = {
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f)
    };

    std::array<const unsigned, 36> indices_data = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };

    GLVertexBuffer positions(std::span{ cube_vertices });
    GLVertexBuffer texture_cordinate(std::span{ texture_cordinate_data });
    GLVertexBuffer colors(std::span{ color });
    GLIndexBuffer indices(std::span{ indices_data });

    GLAttributeLayout position_layout;
    position_layout.component_type = GLAttributeLayout::ComponentType::Float;
    position_layout.component_dimension = GLAttributeLayout::NumComponents::_3;
    position_layout.vertex_layout_location = 0;
    position_layout.normalized = GL_FALSE;
    position_layout.relative_offset = 0;
    position_layout.offset = 0;
    position_layout.stride = sizeof(glm::vec3);

    GLAttributeLayout color_layout;
    color_layout.component_type = GLAttributeLayout::ComponentType::Float;
    color_layout.component_dimension = GLAttributeLayout::NumComponents::_3;
    color_layout.vertex_layout_location = 1;
    color_layout.normalized = GL_FALSE;
    color_layout.relative_offset = 0;
    color_layout.offset = 0;
    color_layout.stride = sizeof(glm::vec3);

    GLAttributeLayout uv_cordinate;
    uv_cordinate.component_type = GLAttributeLayout::ComponentType::Float;
    uv_cordinate.component_dimension = GLAttributeLayout::NumComponents::_2;
    uv_cordinate.vertex_layout_location = 2;
    uv_cordinate.normalized = GL_FALSE;
    uv_cordinate.relative_offset = 0;
    uv_cordinate.offset = 0;
    uv_cordinate.stride = sizeof(glm::vec2);

    Triangle_Model.SetPrimitivePattern(GLPrimitive::Triangles);
    Triangle_Model.AddVertexBuffer(std::move(positions), { position_layout });
    Triangle_Model.AddVertexBuffer(std::move(texture_cordinate), { uv_cordinate });
    Triangle_Model.AddVertexBuffer(std::move(colors), { color_layout });
    Triangle_Model.SetIndexBuffer(std::move(indices));








}

void HookBill::TestLevel2::Update()
{
    angle += 0.3f;
    glm::vec3 move(0.0f);
    
    if (Testkey.IsKeyReleased())
    {
		Engine::GetGameStateManager().SetNextState(1);
    }

    if (Up.IsKeyDown())    move.z += 1.0f;  // ¾Õ
    if (Down.IsKeyDown())  move.z -= 1.0f;  // µÚ
    if (Left.IsKeyDown())  move.x -= 1.0f;  // ÁÂ
    if (Right.IsKeyDown()) move.x += 1.0f;  // ¿ì

    camera.ProcessMovement(move, 0.001f);  // ¹æÇâ º¤ÅÍ¸¸ ³Ñ±è

    float sensitivity = 0.1f;


   // camera.ProcessRotation(dx * sensitivity, -dy * sensitivity);

}   

void HookBill::TestLevel2::ImGuiDraw()
{
}

void HookBill::TestLevel2::Draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glm::mat4 scale=glm::scale(glm::mat4(1.0f), glm::vec3(1.f, 1.0f, 1.0f));
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.4f));

	glm::mat4 mvp = camera.GetViewProjectionMatrix() * translate * rotate * scale;

    Engine::GetShaderManager().Use("Basic Shader", true);
    Triangle_Model.Use();
    Engine::GetShaderManager().Get("Basic Shader")->SendUniform("mvp", mvp);
    Engine::GetTextureManager().Load("../assets/image/beauty.jpg")->UseForSlot(3, *(Engine::GetShaderManager().Get("Basic Shader")), "Utex2d");
    Engine::GetTextureManager().Load("../assets/image/wall.jpg")->UseForSlot(4, *(Engine::GetShaderManager().Get("Basic Shader")), "Utex2d1");
    GLDrawIndexed(Triangle_Model);
    Triangle_Model.Use(false);
    Engine::GetShaderManager().Use("Basic Shader", false);
}

void HookBill::TestLevel2::Unload()
{
    Engine::GetLogger().LogEvent("Unloading TestLevel2..");
	
}
