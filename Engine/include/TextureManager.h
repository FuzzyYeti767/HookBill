#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "GLTexture.h"

namespace HookBill {
    class TextureManager {
    public:
        TextureManager() = default;
        ~TextureManager() = default;

        
        std::shared_ptr<GLTexture> Load(const std::string& filepath);

     
        void Clear();

    private:
        std::unordered_map<std::string, std::shared_ptr<GLTexture>> texture_cache;
    };
}
