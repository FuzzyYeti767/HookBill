#pragma once
#include"Window.h"
#include"Logger.h"
#include"GaemStateManager.h"
#include"event.h"
#include"Input.h"

class Engine {
public:
    static Engine& Instance() { static Engine instance; return instance; }
    static HookBill::Logger& GetLogger(){ return Instance().logger; }
    static HookBill::Window& GetWindow() { return Instance().window; }
    static HookBill::GameStateManager& GetGameStateManager() { return Instance().game_state_manager; }
    static HookBill::EventDispatcher& GetEventDispatcher() { return Instance().event_dispatcher; }
    static HookBill::Input& GetInput() { return Instance().input; }
    void Init(std::string windowName);
    void Shutdown();
    void Update();
    bool HasGameEnded();
    bool ShouldCloseWindow();

private:
    Engine();
    ~Engine();

    HookBill::Logger logger;
    HookBill::Window window;
    HookBill::GameStateManager game_state_manager;
    HookBill::EventDispatcher event_dispatcher;
    HookBill::Input input;
  
};
