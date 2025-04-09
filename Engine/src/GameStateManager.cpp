#include"GaemStateManager.h"
#include"Engine.h"
namespace HookBill
{
	void RenderImGuiGui()
	{
		ImGuiWindowFlags window_flags = /*ImGuiWindowFlags_MenuBar |*/ ImGuiWindowFlags_NoDocking;

		//Need This code for ImGui Dock Space
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;


		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::Begin("DockSpace Window", nullptr, window_flags);
		ImGui::PopStyleVar(2);

		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
		}

		ImGui::End();
	}
	void RenderSceneViewport()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, HookBill_opengl::fbo);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 장면 지우기
		Engine::GetGameStateManager().GetCurrentState()->Draw();
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		ImGui::Begin("Scene");

		// 창의 크기와 텍스처 비율에 맞춰 이미지를 그릴 수 있음
		ImVec2 window_size = ImGui::GetWindowSize(); // size of ImGui Window
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddImage(
			static_cast<ImTextureID>(HookBill_opengl::texture),
			ImVec2(pos.x, pos.y),
			ImVec2(pos.x + window_size.x, pos.y + window_size.y), // 창 크기에 맞춰 이미지 크기 설정
			ImVec2(0, 1),  // Left Bottom of texture
			ImVec2(1, 0)   // Right Top of texture
		);
		ImGui::End();
	}


	GameStateManager::GameStateManager() :currGameState(nullptr),
		nextGameState(nullptr), state(State::START)
	{

	}

	void GameStateManager::AddGameState(GameState& gameState)
	{
		gameStates.push_back(&gameState);
	}

	void GameStateManager::Update()
	{

		switch (state)
		{
		case State::START:
			if (gameStates.empty() == true)
			{
				Engine::GetLogger().LogError("No Game States!!");
				state = State::EXIT;
			}
			else
			{
				nextGameState = gameStates[0];
				state = State::LOAD;
			}
			break;
		case State::LOAD:
			currGameState = nextGameState;

#ifdef _DEBUG
			Engine::GetWindow().InitializeFrameBuffer(Engine::GetWindow().GetWindowSize().x,Engine::GetWindow().GetWindowSize().y);
#endif

			Engine::GetLogger().LogEvent("Load " + currGameState->GetName());
			currGameState->Load();
			Engine::GetLogger().LogEvent("Load Complete");
			state = State::UPDATE;
			break;
		case State::UPDATE:
			Engine::GetWindow().UpdateFrameBufferSize(Engine::GetWindow().GetWindowSize().x, Engine::GetWindow().GetWindowSize().y);
			if (currGameState != nextGameState)
			{
				state = State::UNLOAD;
			}

			else
			{
				currGameState->Update();

				ImGuiHelper::Begin();
#ifdef _DEBUG
				RenderImGuiGui();
				RenderSceneViewport();
#endif
#ifdef NDEBUG
				currGameState->Draw();
#endif

				currGameState->ImGuiDraw();
				ImGuiHelper::End(Engine::GetWindow().Get_OpenGL_Window_ptr());
										//	Engine::GetLogger().LogEvent("Updateing !!! ");

			}

			break;
		case State::UNLOAD:
			Engine::GetLogger().LogEvent("UnLoad " + currGameState->GetName());
			currGameState->Unload();
			if (nextGameState == nullptr)
			{
				state = State::SHUTDOWN;

			}
			else
			{
				state = State::LOAD;

			}
			break;
		case State::SHUTDOWN:
			state = State::EXIT;
			break;
		case State::EXIT:
			break;
		}
	}

	void GameStateManager::SetNextState(int initState)
	{
		nextGameState = gameStates[initState];
	}

	void GameStateManager::Shutdown()
	{
		nextGameState = nullptr;
	}

	void GameStateManager::ReloadState()
	{
		state = State::UNLOAD;
	}


}
