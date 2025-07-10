

#pragma once
#include"GameState.h"
#include"Engine.h"
#include"ImGuiHelper.h"
#include"GLVertexArray.h"
#include <GLShader.h>
#include<string>
#include"entt.hpp"
#include"GLTexture.h"
#include"CubeMesh.h"


namespace HookBill
{
	class TestLevel2 :public GameState
	{
	public:
		TestLevel2();
		void Load();
		void Update();
		void Draw();
		void ImGuiDraw();
		void Unload();
		std::string GetName() { return "test level"; }
	private:

		InputKey Testkey;
		GLVertexArray Triangle_Model;

		glm::vec3 currentColor = glm::vec3(1.0f, 192.0f / 255.0f, 203.0f / 255.0f);
		bool UseUniform = false;


	};
}