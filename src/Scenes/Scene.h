#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void initialize(SDL_Renderer* renderer) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif // SCENE_H