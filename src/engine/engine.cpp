#include "engine.h"

//#include <cstdlib>
#include <iostream>
#include <string>

#include "core/window.h"

#include "../input/input.h"

using namespace Engine;

std::string title = "Engine window";


int EngineApplication::run()
{
    running = true;

    std::cout << "Engine Application is running!" << std::endl;

    Window engineWindow;
    engineWindow.create(1280, 720, title);

    Input::InputEvent e_quit;
    e_quit.name = "quit";
    e_quit.device = Input::Device::KEYBOARD;
    e_quit.key = GLFW_KEY_END;
    e_quit.mod.alt = true;
    e_quit.action = []() {  };

    inputManager.addEvent(e_quit);

    while (running && !engineWindow.shouldClose()) {
        inputManager.processInput(engineWindow.getGlfwWindow());
        engineWindow.update();
    }

    engineWindow.close();

    std::cout << "Engine Application is not running anymore!" << std::endl;
    return 0;
}

void EngineApplication::exit()
{
    running = false;
}
