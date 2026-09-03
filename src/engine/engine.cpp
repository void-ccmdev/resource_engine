#include "engine.h"

//#include <cstdlib>
#include <iostream>
#include <string>

#include "core/window.h"
#include "GLFW/glfw3.h"


#include "../input/input.h"

using namespace Engine;

std::string title = "Engine window";

void forceQuit()
{
    std::cout << "F" << std::endl;
}

int EngineApplication::run()
{
    running = true;

    std::cout << "Engine Application is running!" << std::endl;

    Window engineWindow;
    engineWindow.create(1280, 720, title);

    Input::InputManager inputManager;
    Input::InputEvent e_forceQuit {
        .device = Input::Device::KEYBOARD,
        .key = GLFW_KEY_ESCAPE,
        .state = GLFW_PRESS,
        .action = forceQuit
    };

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
