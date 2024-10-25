#include "EventManager.h"

#include <SDL_events.h>

EventManager::EventManager() = default;

EventManager::~EventManager() = default;

void EventManager::handleEvents(bool &running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        // Set running to false when quitting
        if (event.type == SDL_QUIT) {
            running = false;
        }
        // Handle other events (keyboard, mouse, etc.) here
    }
}