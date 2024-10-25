﻿//
// Created by Nicho on 10/26/2024.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H



#include "Scene.h"
#include <SDL.h>
#include <entt/entt.hpp>

class GameScene final : public Scene {
public:
    GameScene();
    ~GameScene() override;

    void initialize(SDL_Renderer* renderer, entt::registry& registry) override;
    void update(entt::registry& registry, const SDL_Event& event) override;
    void render(SDL_Renderer* renderer, entt::registry& registry) override;

private:

    SDL_Renderer* m_renderer;
    entt::registry* m_registry;
};


#endif //GAMESCENE_H
