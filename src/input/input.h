#pragma once

#include <GLFW/glfw3.h>
#include <functional>

namespace Input {
    struct Mod
    {
        bool alt = false;
        bool ctrl = false;
        bool shift = false;
        bool super = false;
    };

    enum DEVICE {
        KEYBOARD,
        MOUSE
    };

    struct InputEvent
    {
        DEVICE device = KEYBOARD;
        int key;
        Mod mod;
        int state = GLFW_PRESS;
        std::function<void()> action;
    };


    InputEvent events[64];
    unsigned int eventsCount = 0;

    void addEvent(InputEvent newEvent);
    void processInput(GLFWwindow* window);

} //namespace Input
