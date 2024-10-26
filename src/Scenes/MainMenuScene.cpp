#include "MainMenuScene.h"

#include <iostream>
#include <SDL_image.h>

#include "../Resources/ResourceManager.h"
#include "../SceneManager/SceneManager.h"
#include "../src/ecs/components/BackgroundComponent.h"
#include "../src/ecs/components/ButtonComponent.h"
#include "../src/ecs/systems/ButtonSystem.h"
#include "ECS/Systems/RenderSystem.h"
#include "Factories/GameObjectFactory.h"

MainMenuScene::MainMenuScene() = default;

MainMenuScene::~MainMenuScene() = default;

void MainMenuScene::initialize(SDL_Renderer *renderer, entt::registry &registry) {
    std::cout << "Main Menu Scene Initialized" << std::endl;
    m_renderer = renderer; // Store the renderer
    m_registry = &registry; // Store the registry

    createBackground(renderer, registry);
    createButtons(renderer, registry);

    // Initialize the RenderSystem
    RenderSystem::initialize(registry);
}

void MainMenuScene::update(entt::registry &registry, const SDL_Event &event) {
    ButtonSystem::update(registry, event);
}

void MainMenuScene::render(SDL_Renderer *renderer, entt::registry &registry) {
    RenderSystem::render(registry, renderer);
}

void MainMenuScene::createBackground(SDL_Renderer *renderer, entt::registry &registry) {
    SDL_Texture *bgTexture = GameObjectFactory::getOrLoadTexture("background", "../assets/button1.png", renderer);
    if (!bgTexture) {
        std::cerr << "Failed to load background texture" << std::endl;
        return;
    }

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    GameObjectFactory::createBackground(registry, bgTexture, 0, 0, windowWidth, windowHeight, true);
}

void MainMenuScene::createButtons(SDL_Renderer *renderer, entt::registry &registry) const {
    SDL_Texture *buttonTexture0 = GameObjectFactory::getOrLoadTexture("button0", "../assets/button0.png", renderer);
    SDL_Texture *buttonTexture1 = GameObjectFactory::getOrLoadTexture("button1", "../assets/button1.png", renderer);
    SDL_Texture *buttonTexture2 = GameObjectFactory::getOrLoadTexture("button2", "../assets/button2.png", renderer);

    if (!buttonTexture0 || !buttonTexture1 || !buttonTexture2) {
        std::cerr << "Failed to load button texture" << std::endl;
        return;
    }


    // Create button to change to game scene
    GameObjectFactory::createButton(registry, buttonTexture0, 200, 200, 0.25f, [this]() {
        std::cout << "Changing to Game Scene" << std::endl;
        SceneManager::getInstance().changeScene("GameScene", m_renderer, *m_registry);
    });

    // Create button to change to settings scene
    GameObjectFactory::createButton(registry, buttonTexture1, 200, 300, 0.25f, [this]() {
        std::cout << "Changing to Settings Scene" << std::endl;

        // Possible issue, it is passing the scene m_renderer and m_registry instead of the next scenes

        SceneManager::getInstance().changeScene("SettingsScene", m_renderer, *m_registry);
    });

    // Create button to exit game
    GameObjectFactory::createButton(registry, buttonTexture2, 200, 400, 0.25f, [this]() {
        std::cout << "Exiting game" << std::endl;
        SDL_Event quitEvent;
        quitEvent.type = SDL_QUIT;
        SDL_PushEvent(&quitEvent);
    });
}
