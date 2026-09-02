#pragma once

#include <GLFW/glfw3.h>

namespace Input {
    const struct Mod
    {
        bool alt = false;
        bool ctrl = false;
        bool shift = false;
        bool super = false;
    };
    
    const struct InputEvent
    {
        int key;
        Mod mod;
        int state = GLFW_PRESS;
        const void* action;
    };
    
    InputEvent events[64];
    unsigned int eventsCount = 0;

    void addEvent(InputEvent newEvent);
    void processInput();

} //namespace Input