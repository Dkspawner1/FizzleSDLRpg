#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "Scene.h"
#include <SDL.h>

class MainMenuScene : public Scene {
public:
    MainMenuScene();
    ~MainMenuScene();

    void initialize(SDL_Renderer* renderer) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    SDL_Texture* m_backgroundTexture;  // Texture for the background
};

#endif // MAINMENUSCENE_H