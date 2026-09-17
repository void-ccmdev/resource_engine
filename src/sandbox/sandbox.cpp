#include <iostream>
#include <string>

#include "../engine/engine.h"

Engine::Output output;
Engine::WindowServer windowServer;
Engine::InputServer inputServer;

std::string title = "Hello world!";
unsigned int width = 500, height = 500;

void quitAction() {
    windowServer.setWindowShouldClose(
        windowServer.getCurrentWindow(),
        true
    );
}

int main()
{   
    output.print("Running!");
    windowServer.createWindow(width, height, title);

    Input::InputEvent event;
    {
        event.device = Input::Device::KEYBOARD;
        event.key = GLFW_KEY_ESCAPE;
        event.name = "quit";
        event.action = quitAction;
    }

    inputServer.addEvent(event);

    while (! windowServer.shouldWindowClose(windowServer.getCurrentWindow()))
    {
        inputServer.processInput(windowServer.getCurrentWindow());
        windowServer.updateWindow(windowServer.getCurrentWindow());
    }

    windowServer.closeWindow(windowServer.getCurrentWindow());

    output.print("Closing!");

    return 0;
}