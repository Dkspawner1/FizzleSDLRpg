#ifndef BUTTONCOMPONENT_H
#define BUTTONCOMPONENT_H
#include <SDL_rect.h>


class ButtonComponent {
public:
    SDL_Rect rect;
    bool isHovered;
    bool isPressed;

    ButtonComponent(int x, int y, int w , int h): rect(x,y,w,h), isHovered(false),isPressed(false) {}
};



#endif //BUTTONCOMPONENT_H
