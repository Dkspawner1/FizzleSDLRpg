#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SDL_events.h>

class EventManager {
public:
    static EventManager& getInstance() {
        static EventManager instance;
        return instance;
    }

    void handleEvents(bool &running);

    // Delete copy constructor and assignment operator
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;

private:
    EventManager() = default;  // Private constructor
    ~EventManager() = default;
};

#endif // EVENTMANAGER_H