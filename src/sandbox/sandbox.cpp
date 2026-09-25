#include <iostream>
#include <string>

#include "../engine/engine.h"

Engine::Output output;
Engine::WindowServer windowServer;
Engine::InputServer inputServer;
Engine::UIServer uiServer;

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
    output.println("Running!");
    windowServer.createWindow(width, height, title);
    uiServer.initialize();

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
        uiServer.update();
    }

    uiServer.destroy();
    windowServer.closeWindow(windowServer.getCurrentWindow());

    output.println("Closing!");

    return 0;
}