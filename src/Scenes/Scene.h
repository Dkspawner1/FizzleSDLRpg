#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <entt/entt.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    // Initialize the scene with the renderer and entity registry
    virtual void initialize(SDL_Renderer* renderer, entt::registry& registry) = 0;

    // Update the scene with the current events and entity registry
    virtual void update(entt::registry& registry, const SDL_Event& event) = 0;

    // Render the scene using the specified renderer and entity registry
    virtual void render(SDL_Renderer* renderer, entt::registry& registry) = 0;
};

#endif // SCENE_H