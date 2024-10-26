//
// Created by Nicho on 10/26/2024.
//

#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H



#include "Scene.h"
#include <SDL.h>
#include <entt/entt.hpp>

class SettingsScene final : public Scene {
public:
    SettingsScene();
    ~SettingsScene() override;

    void initialize(SDL_Renderer* renderer, entt::registry& registry) override;
    void update(entt::registry& registry, const SDL_Event& event) override;
    void render(SDL_Renderer* renderer, entt::registry& registry) override;

private:
    void createBackground(SDL_Renderer* renderer, entt::registry& registry);
    void createButtons(SDL_Renderer* renderer, entt::registry& registry);

    SDL_Renderer* m_renderer;
    entt::registry* m_registry;
};


#endif //SETTINGSSCENE_H
