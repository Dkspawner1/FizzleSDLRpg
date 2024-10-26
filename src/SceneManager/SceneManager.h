#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <map>
#include <memory>
#include <SDL.h>
#include <string>
#include <entt/entt.hpp>
#include "Scenes/Scene.h"

class SceneManager {
public:
    void addScene(const std::string& name, const std::shared_ptr<Scene>& scene);
    void changeScene(const std::string& name, SDL_Renderer* renderer, entt::registry& registry); // Pass registry for scene initialization
    void update(entt::registry& registry, const SDL_Event& event) const; // Pass event for updating scenes
    void render(SDL_Renderer* renderer, entt::registry& registry) const; // Pass registry for rendering

private:
    std::map<std::string, std::shared_ptr<Scene>> m_scenes;
    std::shared_ptr<Scene> m_currentScene;
};

#endif // SCENEMANAGER_H