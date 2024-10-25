#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <entt/entt.hpp>
#include <SDL.h>
#include "../Components/ButtonComponent.h"

class RenderSystem {
public:
    void render(entt::registry &registry, SDL_Renderer *renderer) {
        auto view = registry.view<ButtonComponent>();

        for (auto entity: view) {
            const auto &button = view.get<ButtonComponent>(entity);

            SDL_SetRenderDrawColor(renderer, button.isHovered ? 255 : 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &button.rect);
        }
    }
};

#endif //RENDERSYSTEM_H
