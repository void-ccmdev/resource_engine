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

    enum Device {
        KEYBOARD,
        MOUSE
    };

    using Action = void (*)();

    struct InputEvent
    {
        using Action = void (*)();

        Device device = KEYBOARD;
        int key;
        Mod mod;
        int state = GLFW_PRESS;
        Action action = nullptr;
    };

    class InputManager {
        public:
            void addEvent(InputEvent newEvent);
            void processInput(GLFWwindow* window);
        private:
            InputEvent events[64];
            unsigned int eventsCount = 0;
    };

} //namespace Input
