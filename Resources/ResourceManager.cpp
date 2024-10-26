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
}

SDL_Texture* ResourceManager::getTexture(const std::string& id) const {
    if (const auto it = textures.find(id); it != textures.end()) {
        return it->second;
    }
    std::cerr << "Texture not found: " << id << std::endl;
    return nullptr;
}

ResourceManager::~ResourceManager() {
    for (const auto&[fst, snd] : textures) {
        SDL_DestroyTexture(snd);
    }
}