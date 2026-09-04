#include "engine/engine.h"

// This is only a temporary way of executing this.
// In the future I'll add an Editor Application that runs everything!

Engine::EngineApplication app;

void closeApp() 
{
    app.exit();
}

int main()
{
    Input::InputManager inputManager = app.inputManager;
    
    Input::InputEvent e_quit;

    e_quit.name = "quit";
    e_quit.device = Input::Device::KEYBOARD;
    e_quit.key = GLFW_KEY_END;
    e_quit.mod.alt = true;
    e_quit.action = closeApp;

    inputManager.addEvent(e_quit);

    return app.run();
}