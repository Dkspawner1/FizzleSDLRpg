#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene()
    : m_backgroundTexture(nullptr) {
}

MainMenuScene::~MainMenuScene() {
    if (m_backgroundTexture) {
        SDL_DestroyTexture(m_backgroundTexture);
    }
}

void MainMenuScene::initialize(SDL_Renderer* renderer) {
    std::cout << "Main Menu Scene Initialized" << std::endl;
}

void MainMenuScene::update() {

}

void MainMenuScene::render(SDL_Renderer* renderer) {
    if (m_backgroundTexture) {
        SDL_RenderCopy(renderer, m_backgroundTexture, nullptr, nullptr);
    }
}