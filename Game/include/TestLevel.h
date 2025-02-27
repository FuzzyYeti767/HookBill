#pragma once
#include"GameState.h"
#include"Engine.h"
#include"ImGuiHelper.h"
#include"GLVertexArray.h"
#include <GLShader.h>
#include<string>
#include"entt.hpp"
namespace HookBill
{
	class TestLevel :public GameState
	{
	public:
		TestLevel();
		void Load();
		void Update();
		void Draw();
		void ImGuiDraw();
		void Unload();
		std::string GetName() { return "test level"; }
	private:
		
		InputKey Testkey;
		GLVertexArray left_eye_model;
		GLShader shader;
		
	};
}