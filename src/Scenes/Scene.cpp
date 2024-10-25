#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "Scene.h"
#include <SDL.h>

class MainMenuScene : public Scene {
public:
    MainMenuScene();
    ~MainMenuScene() override;

    void initialize(SDL_Renderer* renderer) override;  // Override with parameters
    void update() override;
    void render(SDL_Renderer* renderer) override;      // Override with parameters

private:
    SDL_Texture* m_backgroundTexture;  // Texture for the background
};

#endif // MAINMENUSCENE_H