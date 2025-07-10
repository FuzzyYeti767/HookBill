#pragma once

#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <filesystem>
#include "GLShader.h"
#include "ShaderWatcher.h"

namespace HookBill 
{

    class ShaderManager {
    public:
        ShaderManager() = default;
        ~ShaderManager() = default;

        std::shared_ptr<GLShader> Load(const std::string& name,
            const std::filesystem::path& vertex_path,
            const std::filesystem::path& fragment_path);

        bool Reload(const std::string& name);
        std::shared_ptr<GLShader> Get(const std::string& name) const;
        void Clear();
        void Use(const std::string& name,bool use) const;
            
        void Update();

    private:
        struct ShaderSource {
            std::filesystem::path vertex_path;
            std::filesystem::path fragment_path;
        };

        std::unordered_map<std::string, std::shared_ptr<GLShader>> shader_cache;
        std::unordered_map<std::string, ShaderSource> source_cache;

        ShaderWatcher shader_watcher;
    };

} // namespace HookBill
