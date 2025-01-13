#pragma once
struct GLFWwindow;
namespace ImGuiHelper
{
    void Initialize(GLFWwindow*window);
    //void FeedEvent(const SDL_Event& event);
    void Begin();
    void End();
    void Shutdown();
}
