#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "Scene.h"
#include <SDL.h>
#include <entt/entt.hpp>

class MainMenuScene final : public Scene {
public:
    MainMenuScene();
    ~MainMenuScene() override;

    void initialize(SDL_Renderer* renderer, entt::registry& registry) override;
    void update(entt::registry& registry, const SDL_Event& event) override;
    void render(SDL_Renderer* renderer, entt::registry& registry) override;

private:
    void createBackground(SDL_Renderer* renderer, entt::registry& registry);
    void createButtons(SDL_Renderer* renderer, entt::registry& registry);

    SDL_Renderer* m_renderer;
    entt::registry* m_registry;
};

#endif // MAINMENUSCENE_H