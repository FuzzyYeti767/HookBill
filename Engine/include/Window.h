#pragma once
#include"opengl-window.h"
#include<string>
#include"event.h"
namespace HookBill
{
	class Window
	{
	public:
		void Init(std::string windowName);
		bool ShouldCloseWindow();
		void Update();
		void ShutDown();
		GLFWwindow* Get_OpenGL_Window_ptr() { return HookBill_opengl::window_ptr; }
		void addEventListener(Event::Type type, const std::function<void(const Event&)>& callback);
	
	private:
		

	};
}