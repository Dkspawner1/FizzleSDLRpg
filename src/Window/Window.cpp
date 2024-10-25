#include "Window.h"
#include <iostream>

Window::Window(const std::string &title, int width, int height)
    : m_window(nullptr), m_renderer(nullptr), m_isOpen(false) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (m_window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cerr << "SDL could not create renderer! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_window);
        return;
    }

    m_isOpen = true;  // Set the window as open
}

Window::~Window() {
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

bool Window::initialize() const {
    return m_isOpen;  // Return whether the window is open
}

void Window::clear() const {
    if (m_renderer) {
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);
    }
}

void Window::display() const {
    if (m_renderer) {
        SDL_RenderPresent(m_renderer);
    }
}

bool Window::isOpen() const {
    return m_isOpen;
}

SDL_Renderer* Window::getRenderer() const {
    return m_renderer;
}