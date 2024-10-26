

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
    std::cout << "Game Scene Initialized" << std::endl;
    m_renderer = renderer; // Store the renderer
    m_registry = &registry; // Store the registry

    // Initialize the RenderSystem
    RenderSystem::initialize(registry);
}

void GameScene::update(entt::registry &registry, const SDL_Event &event) {
    ButtonSystem::update(registry, event);
}

void GameScene::render(SDL_Renderer *renderer, entt::registry &registry) {
    RenderSystem::render(registry, renderer);
}

