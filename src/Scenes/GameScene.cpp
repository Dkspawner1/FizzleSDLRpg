

#include "GameScene.h"
#include <iostream>
#include <SDL_image.h>
#include "../Resources/ResourceManager.h"
#include "../SceneManager/SceneManager.h"
#include "../src/ecs/components/BackgroundComponent.h"
#include "../src/ecs/components/ButtonComponent.h"
#include "../src/ecs/systems/ButtonSystem.h"
#include "ECS/Systems/RenderSystem.h"
#include "Factories/GameObjectFactory.h"

GameScene::GameScene() = default;

GameScene::~GameScene() = default;

void GameScene::initialize(SDL_Renderer *renderer, entt::registry &registry) {
    std::cout << "Main Menu Scene Initialized" << std::endl;
    m_renderer = renderer; // Store the renderer
    m_registry = &registry; // Store the registry

    createBackground(renderer, registry);
    createButtons(renderer, registry);

    // Initialize the RenderSystem
    RenderSystem::initialize(registry);
}

void GameScene::update(entt::registry &registry, const SDL_Event &event) {
    ButtonSystem::update(registry, event);
}

void GameScene::render(SDL_Renderer *renderer, entt::registry &registry) {
    RenderSystem::render(registry, renderer);
}

void GameScene::createBackground(SDL_Renderer *renderer, entt::registry &registry) {
    SDL_Texture *bgTexture = GameObjectFactory::getOrLoadTexture("background", "../assets/button1.png", renderer);
    if (!bgTexture) {
        std::cerr << "Failed to load background texture" << std::endl;
        return;
    }

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    GameObjectFactory::createBackground(registry, bgTexture, 0, 0, windowWidth, windowHeight, true);
}

void GameScene::createButtons(SDL_Renderer *renderer, entt::registry &registry) {
    SDL_Texture *buttonTexture = GameObjectFactory::getOrLoadTexture("button0", "../assets/button0.png", renderer);
    if (!buttonTexture) {
        std::cerr << "Failed to load button texture" << std::endl;
        return;
    }

    // Create button to change to game scene
    GameObjectFactory::createButton(registry, buttonTexture, 200, 200, 0.25f, [this]() {
        std::cout << "Changing to Game Scene" << std::endl;
        SceneManager::getInstance().changeScene("GameScene", m_renderer, *m_registry);
    });

    // Create button to change to settings scene
    GameObjectFactory::createButton(registry, buttonTexture, 200, 300, 0.25f, [this]() {
        std::cout << "Changing to Settings Scene" << std::endl;
        SceneManager::getInstance().changeScene("SettingsScene", m_renderer, *m_registry);
    });

    // Create button to exit game
    GameObjectFactory::createButton(registry, buttonTexture, 200, 400, 0.25f, [this]() {
        std::cout << "Exiting game" << std::endl;
        SDL_Event quitEvent;
        quitEvent.type = SDL_QUIT;
        SDL_PushEvent(&quitEvent);
    });
}
