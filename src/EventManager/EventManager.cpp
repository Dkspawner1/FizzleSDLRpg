#include "EventManager.h"

EventManager::EventManager() {}

EventManager::~EventManager() {}

void EventManager::handleEvents(bool &running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;  // Set running to false when quitting
        }
        // Handle other events (keyboard, mouse, etc.) here
    }
}