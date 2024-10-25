#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    bool initialize();
    void clear();
    void display();
    bool isOpen() const;
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_isOpen;
};

#endif // WINDOW_H