#ifndef BUTTONCOMPONENT_H
#define BUTTONCOMPONENT_H

#include <SDL.h>

class ButtonComponent {
public:
    ButtonComponent(SDL_Texture* tex, int x, int y, int w, int h, const std::function<void()> &callback = nullptr)
        : texture(tex), rect{x, y, w, h}, isHovered(false), isPressed(false), onClick(callback) {}

    SDL_Rect rect; // Rectangle for button dimensions and position
    SDL_Texture *texture; // Texture for the button
    bool isHovered; // State to check if the button is hovered over
    bool isPressed; // State to check if the button is pressed
    std::function<void()> onClick; // Callback function for on click events
};

#endif // BUTTONCOMPONENT_H
