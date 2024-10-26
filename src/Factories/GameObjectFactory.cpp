// GameObjectFactory.cpp
#include "GameObjectFactory.h"
#include <iostream>
#include <SDL_image.h>

SDL_Texture* GameObjectFactory::loadTexture(const std::string& path, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        std::cerr << "Failed to load texture: " << path << " Error: " << IMG_GetError() << std::endl;
    }
    return texture;
}

SDL_Texture* GameObjectFactory::getOrLoadTexture(const std::string& id, const std::string& path, SDL_Renderer* renderer) {
    SDL_Texture* texture = ResourceManager::getInstance().getTexture(id);
    if (!texture) {
        texture = loadTexture(path, renderer);
        if (texture) {
            ResourceManager::getInstance().addTexture(id, path, renderer);
        }
    }
    return texture;
}

SDL_Rect GameObjectFactory::getTextureDimensions(SDL_Texture* texture) {
    SDL_Rect rect{0, 0, 0, 0};
    if (texture) {
        SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    }
    return rect;
}

entt::entity GameObjectFactory::createButton(entt::registry& registry, SDL_Texture* texture, int x, int y, float scale, std::function<void()> callback) {
    SDL_Rect dimensions = getTextureDimensions(texture);
    auto entity = registry.create();
    registry.emplace<ButtonComponent>(entity, texture, x, y,
                                      static_cast<int>(dimensions.w * scale),
                                      static_cast<int>(dimensions.h * scale),
                                      callback);
    return entity;
}
entt::entity GameObjectFactory::createBackground(entt::registry& registry, SDL_Texture* texture, int x, int y, int w, int h, bool useAlphaBlending) {
    if (!texture) {
        logError("Attempted to create background with null texture");
        return entt::null;
    }

    auto entity = registry.create();
    registry.emplace<BackgroundComponent>(entity, texture, SDL_Rect{x, y, w, h}, useAlphaBlending);
    return entity;
}

void GameObjectFactory::logError(const std::string& message) {
    std::cerr << "GameObjectFactory Error: " << message << std::endl;
}