#include <entt/entt.hpp>
#include <SDL.h>
#include "src/Window/Window.h"
#include "src/EventManager/EventManager.h"
#include "src/SceneManager/SceneManager.h"
#include "src/Scenes/MainMenuScene.h"
#include "Resources/ResourceManager.h"

int main(int argc, char *args[]) {
    // Initialize the window
    const Window window("Fizzle RPG!", 1600, 900);
    if (!window.initialize()) {
        return 1;  // Initialization failed
    }

    // Resource Manager for loading textures
    ResourceManager& resourceManager = ResourceManager::getInstance(); // Use singleton instance

    // Event and Scene Managers
    EventManager eventManager;
    SceneManager sceneManager;

    // Create an entity registry for EnTT
    entt::registry registry;

    // Create and add scenes to the Scene Manager
    const auto mainMenu = std::make_shared<MainMenuScene>();
    sceneManager.addScene("MainMenu", mainMenu);

    // Change to the Main Menu scene and initialize it with the renderer and registry
    sceneManager.changeScene("MainMenu", window.getRenderer(), registry);

    // Enable alpha blending for rendering
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);

    bool running = true;

    // Main game loop
    while (running) {
        SDL_Event event;

        // Handle events
        while (SDL_PollEvent(&event)) {
            eventManager.handleEvents(running);
            sceneManager.update(registry, event);  // Pass SDL_Event to SceneManager
        }

        window.clear();  // Clear the window

        sceneManager.render(window.getRenderer(), registry);  // Pass the registry here

        window.display();  // Display the rendered content
    }

    return 0;  // Return success
}
