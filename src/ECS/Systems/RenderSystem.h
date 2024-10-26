#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SDL.h>
#include <entt/entt.hpp>
#include "../Components/ButtonComponent.h"

class RenderSystem {
public:
    static void render(entt::registry &registry, SDL_Renderer *renderer) {
        for (const entt::entity entity: registry.view<ButtonComponent>()) {
            const ButtonComponent &button = registry.get<ButtonComponent>(entity);

            // Set color modulation based on button state
            if (button.isPressed) {
                SDL_SetTextureColorMod(button.texture, 0, 255, 0); // Green when pressed
            } else if (button.isHovered) {
                SDL_SetTextureColorMod(button.texture, 255, 255, 0); // Yellow when hovered
            } else {
                SDL_SetTextureColorMod(button.texture, 255, 0, 0); // Red for normal state
            }

            // Render the button's texture
            if (button.texture) {
                if (SDL_RenderCopy(renderer, button.texture, nullptr, &button.rect) != 0) {
                    std::cerr << "SDL_RenderCopy error: " << SDL_GetError() << std::endl; // Check for rendering errors
                }
                // std::cout << "Rendering button at position: (" << button.rect.x << ", " << button.rect.y << ")" << std::endl;
            } else {
                std::cerr << "Button texture is null!" << std::endl; // Debugging output
            }

            // Draw rectangle around where the button should be rendered
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for rectangle
            SDL_RenderDrawRect(renderer, &button.rect);
        }
    }
};

#endif // RENDERSYSTEM_H
