#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SDL.h>
#include <entt/entt.hpp>
#include "../Components/ButtonComponent.h"
#include "../Components/BackgroundComponent.h"
#include <algorithm>
#include <vector>

class RenderSystem {
public:
    static void initialize(entt::registry& registry) {
        registry.group<BackgroundComponent, ButtonComponent>();
    }

    static void render(entt::registry& registry, SDL_Renderer* renderer) {
        renderBackgrounds(registry, renderer);
        renderButtons(registry, renderer);
    }

private:
    static void renderBackgrounds(entt::registry& registry, SDL_Renderer* renderer) {
        auto view = registry.view<BackgroundComponent>();
        for (auto [entity, bg] : view.each()) {
            if (bg.useAlphaBlending) {
                SDL_SetTextureBlendMode(bg.texture, SDL_BLENDMODE_BLEND);
            }
            SDL_RenderCopy(renderer, bg.texture, nullptr, &bg.rect);
        }
    }

    static void renderButtons(entt::registry& registry, SDL_Renderer* renderer) {
        auto view = registry.view<ButtonComponent>();
        for (auto [entity, button] : view.each()) {
            setButtonColor(button);
            renderButtonTexture(renderer, button);
            drawButtonOutline(renderer, button);
        }
    }

    static void setButtonColor(const ButtonComponent& button) {
        if (button.isPressed) {
            SDL_SetTextureColorMod(button.texture, 128, 128, 128); // Gray when pressed
        } else if (button.isHovered) {
            SDL_SetTextureColorMod(button.texture, 169, 169, 169); // Dark Gray when hovered
        } else {
            SDL_SetTextureColorMod(button.texture, 255, 255, 255); // White for normal state
        }
    }

    static void renderButtonTexture(SDL_Renderer* renderer, const ButtonComponent& button) {
        if (button.texture) {
            if (SDL_RenderCopy(renderer, button.texture, nullptr, &button.rect) != 0) {
                std::cerr << "SDL_RenderCopy error: " << SDL_GetError() << std::endl;
            }
        } else {
            std::cerr << "Button texture is null!" << std::endl;
        }
    }

    static void drawButtonOutline(SDL_Renderer* renderer, const ButtonComponent& button) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for rectangle
        SDL_RenderDrawRect(renderer, &button.rect);
    }
};

#endif // RENDERSYSTEM_H