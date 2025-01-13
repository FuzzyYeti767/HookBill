/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#include "ImGuiHelper.h"
#include<GLFW/glfw3.h>
#include<Imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

namespace ImGuiHelper
{
    void Initialize(GLFWwindow* window)
    {
        // ImGui ���� Ȯ�� �� ���ؽ�Ʈ ����
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        // ImGui IO ����
        {
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Ű���� ������̼� Ȱ��ȭ
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;      // ��ŷ ��� Ȱ��ȭ
            io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;    // ���� ����Ʈ Ȱ��ȭ
        }

        // GLFW�� OpenGL�� ���� ImGui �鿣�� �ʱ�ȭ
        ImGui_ImplGlfw_InitForOpenGL(window, true);

        // OpenGL 3.x�� ���� GLSL ���� ����
        const char* glsl_version = "#version 130"; // �Ǵ� "#version 330" �� ��� ���� OpenGL ������ �°� ����
        ImGui_ImplOpenGL3_Init(glsl_version);
    }


   
}
