#pragma once

#include <GLFW/glfw3.h>
#include <string>

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

        std::string name = "unnamed_event";
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
            InputEvent events[32];
            unsigned int eventsCount = 0;
    };

} //namespace Input
