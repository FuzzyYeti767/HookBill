#include "TextureManager.h"
#include <stdexcept>

namespace HookBill
{
    std::shared_ptr<GLTexture> TextureManager::Load(const std::string& filepath) {
        auto it = texture_cache.find(filepath);
        if (it != texture_cache.end()) {
            return it->second;
        }

        auto texture = std::make_shared<GLTexture>();
        if (!texture->LoadFromFileImage(filepath)) {
            throw std::runtime_error("Failed to load texture: " + filepath);
        }

        texture_cache[filepath] = texture;
        return texture;
    }

    void TextureManager::Clear() {
        texture_cache.clear(); 
    }
}