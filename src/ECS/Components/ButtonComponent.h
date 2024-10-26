#ifndef BUTTONCOMPONENT_H
#define BUTTONCOMPONENT_H

#include <SDL.h>

class ButtonComponent {
public:
    ButtonComponent(SDL_Texture* texture, const int x, const int y, const int w, const int h)
        : rect{x, y, w, h}, texture(texture), isHovered(false), isPressed(false) {}

    SDL_Rect rect;           // Rectangle for button dimensions and position
    SDL_Texture* texture;    // Texture for the button
    bool isHovered;          // State to check if the button is hovered over
    bool isPressed;          // State to check if the button is pressed
};

#endif // BUTTONCOMPONENT_H