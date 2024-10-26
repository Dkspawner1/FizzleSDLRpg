#ifndef BACKGROUNDCOMPONENT_H
#define BACKGROUNDCOMPONENT_H

#include <SDL.h>

struct BackgroundComponent {
    SDL_Texture *texture;
    SDL_Rect rect;
    bool useAlphaBlending;

    BackgroundComponent(SDL_Texture *texture, SDL_Rect rect, bool alpha = false) : texture(texture), rect(rect), useAlphaBlending(alpha) {
    }

};

#endif //BACKGROUNDCOMPONENT_H
