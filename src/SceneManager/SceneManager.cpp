#include "SceneManager.h"

void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene>& scene) {
    m_scenes[name] = scene;
}

void SceneManager::changeScene(const std::string& name, SDL_Renderer* renderer, entt::registry& registry) {
    auto it = m_scenes.find(name);
    if (it != m_scenes.end()) {
        m_currentScene = it->second;
        m_currentScene->initialize(renderer, registry);
    } else {
        // Handle error: scene not found
        std::cerr << "Scene not found: " << name << std::endl;
    }
}

void SceneManager::update(entt::registry& registry, const SDL_Event& event) {
    if (m_currentScene) {
        m_currentScene->update(registry, event);
    }
}

void SceneManager::render(SDL_Renderer* renderer, entt::registry& registry) {
    if (m_currentScene) {
        m_currentScene->render(renderer, registry);
    }
}