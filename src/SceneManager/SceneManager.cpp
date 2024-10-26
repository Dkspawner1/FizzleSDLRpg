#include "SceneManager.h"

void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene>& scene) {
    m_scenes[name] = scene;
}

void SceneManager::changeScene(const std::string& name, SDL_Renderer* renderer, entt::registry& registry) {
    if (m_scenes.contains(name)) {
        m_currentScene = m_scenes[name];
        m_currentScene->initialize(renderer, registry); // Initialize new scene with renderer and registry
    }
}

void SceneManager::update(entt::registry& registry, const SDL_Event& event) const {
    if (m_currentScene) {
        m_currentScene->update(registry, event); // Pass event to current scene
    }
}

void SceneManager::render(SDL_Renderer* renderer, entt::registry& registry) const { // Accept registry here
    if (m_currentScene) {
        m_currentScene->render(renderer, registry); // Pass the registry to render
    }
}