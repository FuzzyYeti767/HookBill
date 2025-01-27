#pragma once
#include"opengl-window.h"
#include<string>
#include"event.h"
#include "vec2.h"

namespace HookBill
{
	class Window
	{
	public:
		void Init(std::string windowName);
		bool ShouldCloseWindow();
		void Update();
		void ShutDown();
		ImVec2 GetWindowSize();
		void InitializeFrameBuffer(int width, int height);
		GLFWwindow* Get_OpenGL_Window_ptr() { return HookBill_opengl::window_ptr; }
		void addEventListener(Event::Type type, const std::function<void(const Event&)>& callback);
	
	private:
		int width;
		int height;

	};
}
