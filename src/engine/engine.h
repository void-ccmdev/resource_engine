#pragma once

#include "../input/input.h"

namespace Engine {

class EngineApplication {
    public:
        Input::InputManager inputManager;

        int run();
        void exit();
        bool running;
};

} // namespace Engine
