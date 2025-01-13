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
        // ImGui 버전 확인 및 컨텍스트 생성
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        // ImGui IO 설정
        {
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // 키보드 내비게이션 활성화
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;      // 도킹 기능 활성화
            io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;    // 여러 뷰포트 활성화
        }

        // GLFW와 OpenGL을 위한 ImGui 백엔드 초기화
        ImGui_ImplGlfw_InitForOpenGL(window, true);

        // OpenGL 3.x을 위한 GLSL 버전 설정
        const char* glsl_version = "#version 130"; // 또는 "#version 330" 등 사용 중인 OpenGL 버전에 맞게 설정
        ImGui_ImplOpenGL3_Init(glsl_version);
    }


   
}
