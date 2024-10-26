#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <memory>
#include <SDL.h>
#include <string>
#include <unordered_map>
#include <entt/entt.hpp>
#include "../src/Scenes/Scene.h"

class SceneManager {
public:
    static SceneManager& getInstance() {
        static SceneManager instance;
        return instance;
    }

    void addScene(const std::string& name, const std::shared_ptr<Scene>& scene);
    void changeScene(const std::string& name, SDL_Renderer* renderer, entt::registry& registry);
    void update(entt::registry& registry, const SDL_Event& event);
    void render(SDL_Renderer* renderer, entt::registry& registry);

private:
    SceneManager() = default;
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
    std::shared_ptr<Scene> m_currentScene;
};

#endif // SCENEMANAGER_H