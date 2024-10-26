#include "ResourceManager.h"

SDL_Texture* ResourceManager::loadTexture(const std::string& filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture) {
        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
    }
    return texture;
}

void ResourceManager::addTexture(const std::string& id, const std::string& filePath, SDL_Renderer* renderer) {
    textures[id] = loadTexture(filePath, renderer);
    if (textures[id] != nullptr) {
        std::cout << "Loaded texture with ID: " << id << " from " << filePath << std::endl;
    } else {
        std::cerr << "Failed to load texture with ID: " << id << std::endl;
    }
}

SDL_Texture* ResourceManager::getTexture(const std::string& id) const {
    if (const auto it = textures.find(id); it != textures.end()) {
        return it->second;
    }
    std::cerr << "Texture ID not found: " << id << std::endl;
    return nullptr; // Return null if not found
}

ResourceManager::~ResourceManager() {
    for (auto& [id, texture] : textures) {
        SDL_DestroyTexture(texture);
    }
}