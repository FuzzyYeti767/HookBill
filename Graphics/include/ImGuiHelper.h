#pragma once
#include <unordered_map>
#include<string>

#include "imgui.h"
#include"glad/glad.h"
struct GLFWwindow;
namespace ImGuiHelper
{
    void Initialize(GLFWwindow*window);
    //void FeedEvent(const SDL_Event& event);
    void Begin();
    void End(GLFWwindow* window);
    void ShutDown();
    
    inline std::unordered_map <std::string, std::string>settings_descriptions;


    inline void print_and_save_opengl_settings() noexcept
    {
        //GL_VENDOR: Intel
        //GL_RENDERER : Intel(R) Iris(R) Graphics 540
        //GL_VERSION : 4.6.0 - Build 30.0.101.1660
        //GL_SHADING_LANGUAGE_VERSION : 4.60 - Build 30.0.101.1660
        //GL_MAJOR_VERSION : 4
        //GL_MINOR_VERSION : 6
        //GL_MAX_ELEMENTS_VERTICES : 1048576
        //GL_MAX_ELEMENTS_INDICES : 1048576
        //GL_MAX_TEXTURE_IMAGE_UNITS : 32
        //GL_MAX_TEXTURE_SIZE : 16384
        //GL_MAX_VIEWPORT_DIMS : 16384 x 16384
        //GL_DOUBLEBUFFER : true

        std::string GL_VENDOR_KEY = "GL_VENDOR";
        std::string GL_RENDERER_KEY = "GL_RENDERER";
        std::string GL_VERSION_KEY = "GL_VERSION";
        std::string GL_SHADING_LANGUAGE_VERSION_KEY = "GL_SHADING_LANGUAGE_VERSION";
        std::string GL_MAJOR_VERSION_KEY = "GL_MAJOR_VERSION";
        std::string GL_MINOR_VERSION_KEY = "GL_MINOR_VERSION";
        std::string GL_MAX_ELEMENTS_VERTICES_KEY = "GL_MAX_ELEMENTS_VERTICES";
        std::string GL_MAX_ELEMENTS_INDICES_KEY = "GL_MAX_ELEMENTS_INDICES";
        std::string GL_MAX_TEXTURE_IMAGE_UNITS_KEY = "GL_MAX_TEXTURE_IMAGE_UNITS";
        std::string GL_MAX_TEXTURE_IMAGE_SIZE_KEY = "GL_MAX_TEXTURE_SIZE";
        std::string GL_MAX_VIEWPORT_DIMS_KEY = "GL_MAX_VIEWPORT_DIMS";
        std::string GL_DOUBLEBUFFER_KEY = "GL_DOUBLEBUFFER";

        const GLubyte* GL_VENDOR_V;
        const GLubyte* GL_RENDERER_V;
        const GLubyte* GL_VERSION_V;
        const GLubyte* GL_SHADING_LANGUAGE_VERSION_V;
        GLint GL_MAJOR_VERSION_V;
        GLint GL_MINOR_VERSION_V;
        GLint GL_MAX_ELEMENTS_VERTICES_V;
        GLint GL_MAX_ELEMENTS_INDICES_V;
        GLint GL_MAX_TEXTURE_IMAGE_UNITS_V;
        GLint GL_MAX_TEXTURE_SIZE_V;

       [[maybe_unused]] GLboolean GL_DOUBLEBUFFER_V;


        GL_VENDOR_V = glGetString(GL_VENDOR);
        settings_descriptions[GL_VENDOR_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_VENDOR_V));


        GL_RENDERER_V = glGetString(GL_RENDERER);
        settings_descriptions[GL_RENDERER_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_RENDERER_V));


        GL_VERSION_V = glGetString(GL_VERSION);
        settings_descriptions[GL_VERSION_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_VERSION_V));


        GL_SHADING_LANGUAGE_VERSION_V = glGetString(GL_SHADING_LANGUAGE_VERSION);
        settings_descriptions[GL_SHADING_LANGUAGE_VERSION_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_SHADING_LANGUAGE_VERSION_V));



        glGetIntegerv(GL_MAJOR_VERSION, &GL_MAJOR_VERSION_V);
        settings_descriptions[GL_MAJOR_VERSION_KEY] = std::to_string(GL_MAJOR_VERSION_V);


        glGetIntegerv(GL_MINOR_VERSION, &GL_MINOR_VERSION_V);
        settings_descriptions[GL_MINOR_VERSION_KEY] = std::to_string(GL_MINOR_VERSION_V);


        glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &GL_MAX_ELEMENTS_VERTICES_V);
        settings_descriptions[GL_MAX_ELEMENTS_VERTICES_KEY] = std::to_string(GL_MAX_ELEMENTS_VERTICES_V);



        glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &GL_MAX_ELEMENTS_INDICES_V);
        settings_descriptions[GL_MAX_ELEMENTS_INDICES_KEY] = std::to_string(GL_MAX_ELEMENTS_INDICES_V);



        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &GL_MAX_TEXTURE_IMAGE_UNITS_V);
        settings_descriptions[GL_MAX_TEXTURE_IMAGE_UNITS_KEY] = std::to_string(GL_MAX_TEXTURE_IMAGE_UNITS_V);


        glGetIntegerv(GL_MAX_TEXTURE_SIZE, &GL_MAX_TEXTURE_SIZE_V);
        settings_descriptions[GL_MAX_TEXTURE_IMAGE_SIZE_KEY] = std::to_string(GL_MAX_TEXTURE_SIZE_V);



        settings_descriptions[GL_MAX_VIEWPORT_DIMS_KEY] = std::to_string(GL_MAX_TEXTURE_SIZE_V) + " X " + std::to_string(GL_MAX_TEXTURE_SIZE_V);









    }



    inline void ShowDockSpace()
    {
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        ImGui::Begin("DockSpace Demo", nullptr, window_flags);

        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }

        ImGui::End();
    }

}
