#ifndef BUTTONSYSTEM_H
#define BUTTONSYSTEM_H

#include <entt/entt.hpp>
#include <SDL.h>
#include "ECS/Components/ButtonComponent.h"

class ButtonSystem {
public:
    static void update(entt::registry &registry, const SDL_Event &event) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        for (const auto entity: registry.view<ButtonComponent>()) {
            auto &button = registry.get<ButtonComponent>(entity);

            // Check if mouse is over the button
            button.isHovered = mouseX >= button.rect.x && mouseX < button.rect.x + button.rect.w &&
                               mouseY >= button.rect.y && mouseY < button.rect.y + button.rect.h;

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (button.isHovered) {
                    // Button is pressed only if the mouse is over it
                    button.isPressed = true;
                }
            } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                if (button.isPressed && button.isHovered) {
                    // Trigger action on button release if it was pressed and is still hovered
                    std::cout << "Button clicked!" << std::endl;
                    button.onClick();
                }
                // Always set isPressed to false on mouse button up
                button.isPressed = false;
            }
        }
    }
};

#endif // BUTTONSYSTEM_H
