#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scenes/Scene.h"
#include <memory>
#include <map>
#include <string>
#include <SDL.h>

class SceneManager {
public:
    void addScene(const std::string& name, std::shared_ptr<Scene> scene);

    void changeScene(const std::string& name, SDL_Renderer* renderer);

    void update();
    void render(SDL_Renderer* renderer);

private:
    std::map<std::string, std::shared_ptr<Scene>> m_scenes;
    std::shared_ptr<Scene> m_currentScene;
};

#endif // SCENEMANAGER_H