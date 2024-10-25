﻿#include <crtdbg.h>
#include <SDL.h>
#include <entt/entt.hpp>
#include "Resources/ResourceManager.h"
#include "Scenes/GameScene.h"
#include "Scenes/SettingsScene.h"
#include "src/EventManager/EventManager.h"
#include "src/SceneManager/SceneManager.h"
#include "src/Scenes/MainMenuScene.h"
#include "src/Window/Window.h"

int main(int, char *[]) {
    #if (DEBUG_LEVEL > 0)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

    // Uncomment the following line and replace XXXX with the allocation number to break on
    // _CrtSetBreakAlloc(XXXX);
    #endif

    // Initialize the window
    const Window window("Fizzle RPG!", 1600, 900);
    if (!window.initialize()) {
        return 1;  // Initialization failed
    }

    // Get manager instances
    EventManager& eventManager = EventManager::getInstance();
    SceneManager& sceneManager = SceneManager::getInstance();

    // Create an entity registry for EnTT
    entt::registry registry;

    // Create and add scenes to the Scene Manager
    const auto mainMenu = std::make_shared<MainMenuScene>();
    sceneManager.addScene("MainMenu", mainMenu);

    const auto settingsScene = std::make_shared<SettingsScene>();
    sceneManager.addScene("SettingsScene", settingsScene);

    const auto gameScene = std::make_shared<GameScene>();
    sceneManager.addScene("GameScene", gameScene);

    // Change to the Main Menu scene and initialize it with the renderer and registry
    sceneManager.changeScene("MainMenu", window.getRenderer(), registry);

    // Enable alpha blending for rendering
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);

    bool running = true;

    // Main game loop
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
            eventManager.handleEvents(running);
            sceneManager.update(registry, event);
        }

        if (!running) break;  // Exit the main loop if running is false

        window.clear();
        sceneManager.render(window.getRenderer(), registry);
        window.display();
    }

    // Dump memory leaks at the end of execution
    #if (DEBUG_LEVEL > 0)
    _CrtDumpMemoryLeaks();
    #endif

    // Return success
    return 0;
}