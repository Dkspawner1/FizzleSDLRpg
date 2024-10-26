#include "MainMenuScene.h"
#include <iostream>
#include <SDL_image.h>
#include "../src/ecs/components/ButtonComponent.h"
#include "../src/ecs/systems/ButtonSystem.h"
#include "../Resources/ResourceManager.h"
#include "ECS/Systems/RenderSystem.h"

MainMenuScene::MainMenuScene()
    : m_backgroundTexture(nullptr) {
}

MainMenuScene::~MainMenuScene() {
    if (m_backgroundTexture) {
        SDL_DestroyTexture(m_backgroundTexture);
    }
}

void MainMenuScene::initialize(SDL_Renderer *renderer, entt::registry &registry) {
    std::cout << "Main Menu Scene Initialized" << std::endl;

    // Load background texture
    m_backgroundTexture = IMG_LoadTexture(renderer, "../assets/button1.png");
    if (!m_backgroundTexture) {
        std::cerr << "Failed to load background texture: " << IMG_GetError() << std::endl;
        return; // Exit if texture loading fails
    }

    // Load button texture using ResourceManager singleton
    ResourceManager::getInstance().addTexture("button0", "../assets/button0.png", renderer);

    SDL_Texture *buttonTexture = ResourceManager::getInstance().getTexture("button0");
    if (!buttonTexture) {
        std::cerr << "Failed to retrieve button texture." << std::endl;
        return; // Exit if texture retrieval fails
    }

    // Create a button entity and add a ButtonComponent to it
    const auto buttonEntity = registry.create();
    registry.emplace<ButtonComponent>(buttonEntity, buttonTexture, 200, 200, 400, 400); // Pass texture and dimensions
}

void MainMenuScene::update(entt::registry &registry, const SDL_Event &event) {
    ButtonSystem::update(registry, event); // Pass event to ButtonSystem for handling
}

void MainMenuScene::render(SDL_Renderer *renderer, entt::registry &registry) {

    // Draw the background first (commented out for testing)
    if (m_backgroundTexture) {
        SDL_RenderCopy(renderer, m_backgroundTexture, nullptr, nullptr);
    }

    // Then render buttons using RenderSystem
    RenderSystem::render(registry, renderer); // Pass registry to RenderSystem for rendering buttons
}
