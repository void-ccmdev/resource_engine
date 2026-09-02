#include "engine.h"

#include <iostream>
#include <string>

#include "core/window.h"

using namespace Engine;

std::string title = "Engine window";

int EngineApplication::run()
{
    running = true;

    std::cout << "Engine Application is running!" << std::endl;

    Window engineWindow;
    engineWindow.create(1280, 720, title);

    while (running && !engineWindow.shouldClose()) {
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
