#pragma once

#include "../engine/core/input.h"
#include "../engine/core/window.h"

namespace Editor {

class EditorApp {
    public:
        bool running = false;
        int run();
        void exit();
    private:
        Engine::Window m_window;
        Input::InputManager m_inputManager;
};

}