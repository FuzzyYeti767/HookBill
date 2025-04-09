#include"Engine.h"
#include"Window.h"
#include<iostream>
#include<sstream>

void key_callback([[maybe_unused]] GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {

		if (key == GLFW_KEY_ESCAPE) {
			std::cout << "Escape key pressed, closing window..." << std::endl;
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}


		HookBill::Event event(HookBill::Event::Type::KeyPressed, key);
		Engine::GetEventDispatcher().dispatch(event);
		Engine::GetInput().SetKeyDown(static_cast<HookBill::InputKey::Keyboard>(key), true);
	}
	else if (action == GLFW_RELEASE) {

		HookBill::Event event(HookBill::Event::Type::KeyReleased, key);
		Engine::GetEventDispatcher().dispatch(event);
		Engine::GetInput().SetKeyDown(static_cast<HookBill::InputKey::Keyboard>(key), false);
	}
}


void mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
	if (action == GLFW_PRESS) {

		HookBill::Event event(HookBill::Event::Type::MouseButtonPressed, button);
		Engine::GetEventDispatcher().dispatch(event);
	}
}

void cursor_position_callback([[maybe_unused]] GLFWwindow* window, double xpos, double ypos) {

	HookBill::Event event(HookBill::Event::Type::MouseMoved, 0, xpos, ypos);
	Engine::GetEventDispatcher().dispatch(event);
}



void scroll_callback([[maybe_unused]] GLFWwindow* window, double xoffset, double yoffset)
{
	HookBill::Event event(HookBill::Event::Type::MouseScroll, 0, xoffset, yoffset);
	Engine::GetEventDispatcher().dispatch(event);
}

void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height)
{
	
#ifdef _DEBUG

	glViewport(0, 0, width,height);
	std::cout << "Framebuffer size changed: " << width << "x" << height << std::endl;
#endif
	glViewport(0, 0, width, height);
	Engine::GetWindow().SetWidth(width);
	Engine::GetWindow().SetHeight(height);
}


namespace HookBill
{
	void Window::Init(std::string windowName)
	{


		HookBill_opengl::create_window(windowName);

		glfwSetKeyCallback(Get_OpenGL_Window_ptr(), key_callback);
		glfwSetMouseButtonCallback(Get_OpenGL_Window_ptr(), mouse_button_callback);
		glfwSetCursorPosCallback(Get_OpenGL_Window_ptr(), cursor_position_callback);
		glfwSetScrollCallback(Get_OpenGL_Window_ptr(), scroll_callback);
		glfwSetFramebufferSizeCallback(Get_OpenGL_Window_ptr(), framebuffer_size_callback);
		addEventListener(Event::Type::KeyPressed,
			[](const Event& event)
			{
#ifdef _DEBUG
				std::ostringstream oss;
				// << "Key pressed: " << event.key << '\n';
				Engine::GetInput().SetKeyDown(static_cast<HookBill::InputKey::Keyboard>(event.key), true);
				//Engine::GetLogger().LogVerbose(oss.str());
#endif


			}
		);

		addEventListener(Event::Type::KeyReleased,
			[](const Event& event)
			{
#ifdef _DEBUG
				std::ostringstream oss;
				//oss << "Key Released: " << static_cast<char>(event.key) << '\n';
				Engine::GetInput().SetKeyDown(static_cast<HookBill::InputKey::Keyboard>(event.key), false);
				//Engine::GetLogger().LogVerbose(oss.str());
#endif

			}
		);

		addEventListener(Event::Type::MouseMoved,
			[]([[maybe_unused]] const Event& event)
			{
				std::cout << "Mouse moved to: (" << event.x << ", " << event.y << ")" << std::endl;
			}
		);
		addEventListener(Event::Type::MouseButtonPressed, []([[maybe_unused]] const Event& event)
			{

				//std::cout << "Mouse Button " << event.key << " pressed at: (" << event.x << ", " << event.y << ")" << std::endl;
			}
		);
		addEventListener(Event::Type::MouseScroll,
			[]([[maybe_unused]] const Event& event)
			{
				//std::cout << "Mouse wheel scrolled: (" << event.x << ", " << event.y << ")" << std::endl;
			});

		ImGuiHelper::Initialize(Get_OpenGL_Window_ptr());


	}



	bool Window::ShouldCloseWindow()
	{
		return HookBill_opengl::ShouldCloseWindow();
	}

	void Window::Update()
	{
		HookBill_opengl::update_window();
	}
	void Window::ShutDown()
	{
		ImGuiHelper::ShutDown();
		HookBill_opengl::shutdown_window();

	}

	ImVec2 Window::GetWindowSize()
	{
		int width, height;
		glfwGetWindowSize(Get_OpenGL_Window_ptr(), &width, &height);
		return ImVec2{ static_cast<float>(width),static_cast<float>(height) };
	}

	void Window::InitializeFrameBuffer(int width, int height)
	{
		HookBill_opengl::InitializeFrameBuffer(width, height);
	}

	void Window::UpdateFrameBufferSize(int width, int height)
	{
	
		HookBill_opengl::UpdateFrameBufferSize(width, height);
	}

	void Window::addEventListener(Event::Type type, const std::function<void(const Event&)>& callback)
	{
		HookBill::EventListener listener(type, callback);
		Engine::GetEventDispatcher().addListener(listener);
	}

}