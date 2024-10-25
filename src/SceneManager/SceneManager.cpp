#include "SceneManager.h"

void SceneManager::addScene(const std::string& name, std::shared_ptr<Scene> scene) {
    // Add scene to map by name
    m_scenes[name] = scene;
}

void SceneManager::changeScene(const std::string& name, SDL_Renderer* renderer) {
    if (m_scenes.find(name) != m_scenes.end()) {
        m_currentScene = m_scenes[name];
        // Initialize new scene with renderer
        m_currentScene->initialize(renderer);
    }
}

void SceneManager::update() {
    // Update current scene logic
    if (m_currentScene) {
        m_currentScene->update();
    }
}

void SceneManager::render(SDL_Renderer* renderer) {
    // Render current scene content with renderer
    if (m_currentScene) {
        m_currentScene->render(renderer);
    }
}