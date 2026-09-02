#include "input.h"

#include <stdexcept>

void Input::addEvent(InputEvent newEvent)
{
    if (eventsCount >= sizeof(events) / sizeof(events[0])) {
        std::runtime_error("Too many input events! Max 64 Input events!");
        return;
    }

    events[eventsCount] = newEvent;
    eventsCount++;
}

void Input::processInput()
{
    
}