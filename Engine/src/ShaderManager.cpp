
#include "ShaderManager.h"
#include <iostream>
#include"Engine.h"
namespace HookBill {

    std::shared_ptr<GLShader> ShaderManager::Load(
        const std::string& name,
        const std::filesystem::path& vertex_path,
        const std::filesystem::path& fragment_path)
    {
        auto it = shader_cache.find(name);
        if (it != shader_cache.end()) return it->second;

        auto shader = std::make_shared<GLShader>(
            name,
            std::initializer_list<std::pair<GLShader::Type, std::filesystem::path>>{
                {GLShader::VERTEX, vertex_path},
                { GLShader::FRAGMENT, fragment_path }
        });

        shader_cache[name] = shader;
        source_cache[name] = { vertex_path, fragment_path };

        
        shader_watcher.Watch(name, vertex_path, fragment_path);

        return shader;
    }

    bool ShaderManager::Reload(const std::string& name) {
        auto it = source_cache.find(name);
        if (it == source_cache.end()) return false;

        auto shader = std::make_shared<GLShader>(
            name,
            std::initializer_list<std::pair<GLShader::Type, std::filesystem::path>>{
                {GLShader::VERTEX, it->second.vertex_path},
                { GLShader::FRAGMENT, it->second.fragment_path }
        });

        shader_cache[name] = shader;
        return true;
    }

    std::shared_ptr<GLShader> ShaderManager::Get(const std::string& name) const {
        auto it = shader_cache.find(name);
        if (it != shader_cache.end()) return it->second;
        return nullptr;
    }

    void ShaderManager::Clear() {
        shader_cache.clear();
        source_cache.clear();
    }

    
    void ShaderManager::Update()
    {
        for (const auto& name : shader_watcher.PollChangedShaders()) 
        {
            Engine::GetLogger().LogEvent("Reloading shader: " + name);
            Reload(name);
        }
    }

    void ShaderManager::Use(const std::string& name,bool use) const 
    {
        if (use == true)
        {
            auto shader = Get(name);
            if (shader) {
                shader->Use();
            }
            else {
                Engine::GetLogger().LogError("Shader not found: " + name);
            }
        }
        else
        {
            auto shader = Get(name);
            if (shader) {
                shader->Use(false);
            }
            else {
                Engine::GetLogger().LogError("Shader not found: " + name);
            }
        }
	}

} // namespace HookBill
