#include "src/Window/Window.h"
#include "src/EventManager/EventManager.h"
#include "src/SceneManager/SceneManager.h"
#include "src/Scenes/MainMenuScene.h"
#include "src/ecs/components/ButtonComponent.h"
#include "src/ecs/systems/ButtonSystem.h"
#include "src/ecs/systems/RenderSystem.h"
#include <entt/entt.hpp>

int main(int argc, char *args[]) {
    Window window("Fizzle RPG!", 1600, 900);

    if (!window.initialize()) {
        return 1;  // Initialization failed
    }

    EventManager eventManager;
    SceneManager sceneManager;

    entt::registry registry;  // Create an entity registry for EnTT

    // Create a button entity and add a ButtonComponent to it
    auto buttonEntity = registry.create();
    registry.emplace<ButtonComponent>(buttonEntity, 100, 100, 200, 50); // x, y, width, height

    ButtonSystem buttonSystem;

    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            eventManager.handleEvents(running);  // Handle events

            // Update buttons with the current event
            buttonSystem.update(registry, event);
        }

        window.clear();                       // Clear the window

        // Render buttons before displaying the window
        buttonSystem.render(registry, window.getRenderer());

        window.display();                     // Display the rendered content
    }

    return 0;  // Return success
}