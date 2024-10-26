#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <SDL.h>
#include <entt/entt.hpp>
#include <string>
#include "../Resources/ResourceManager.h"
#include "../src/ecs/components/ButtonComponent.h"
#include "../src/ecs/components/BackgroundComponent.h"

class GameObjectFactory {
public:
    static SDL_Texture *loadTexture(const std::string &path, SDL_Renderer *renderer);

    static SDL_Texture *getOrLoadTexture(const std::string &id, const std::string &path, SDL_Renderer *renderer);

    static SDL_Rect getTextureDimensions(SDL_Texture *texture);

    static entt::entity createButton(entt::registry &registry, SDL_Texture *texture, int x, int y, float scale,
                                     std::function<void()> callback);

    static entt::entity createBackground(entt::registry &registry, SDL_Texture *texture, int x, int y, int w, int h,
                                         bool useAlphaBlending = false);

private:
    static void logError(const std::string &message);
};

#endif //GAMEOBJECTFACTORY_H
