#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SDL.h>

class EventManager {
public:
    EventManager();
    ~EventManager();

    void handleEvents(bool &running);
};

#endif // EVENTMANAGER_H