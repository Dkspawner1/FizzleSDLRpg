#ifndef BUTTONSYSTEM_H
#define BUTTONSYSTEM_H

#include <entt/entt.hpp>
#include <SDL.h>
#include "ECS/Components/ButtonComponent.h"

class ButtonSystem {
public:
    static void update(entt::registry &registry, const SDL_Event &event) {
        for (const auto entity : registry.view<ButtonComponent>()) {
            auto &button = registry.get<ButtonComponent>(entity);

            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            button.isHovered = mouseX >= button.rect.x && mouseX <= button.rect.x + button.rect.w &&
                               mouseY >= button.rect.y && mouseY <= button.rect.y + button.rect.h;

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                // Button is pressed, trigger action
                button.isPressed = true;
            } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                if (button.isHovered) {
                    button.isPressed = false;
                    // Trigger action on button release if needed
                }
            }
        }
    }

};

#endif // BUTTONSYSTEM_H