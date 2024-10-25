#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

class EventManager {
public:
    EventManager();
    ~EventManager();

    static void handleEvents(bool &running);
};

#endif // EVENTMANAGER_H