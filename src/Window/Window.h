#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    bool initialize() const;
    void clear() const;
    void display() const;
    [[nodiscard]] bool isOpen() const;
    [[nodiscard]] SDL_Renderer* getRenderer() const;

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_isOpen;
};

#endif // WINDOW_H