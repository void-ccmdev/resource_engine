#include "engine.h"

Engine::Output output;
Engine::InputServer inputServer;
Engine::WindowServer windowServer;

std::string title = "Resource Engine - Editor";
unsigned int width = 500, height = 500;

void forceQuit() { windowServer.setWindowShouldClose(windowServer.getCurrentWindow(), true); }

int main()
{   
    output.println("Launching editor!");
    windowServer.createWindow(width, height, title);

    Input::InputEvent e_quit;
    {
        e_quit.name = "quit";
        e_quit.device = Input::Device::KEYBOARD;
        e_quit.key = GLFW_KEY_ESCAPE;
        e_quit.action = forceQuit;
    }
    inputServer.addEvent(e_quit);

    while (!windowServer.shouldWindowClose(windowServer.getCurrentWindow()))
    {
        inputServer.processInput(windowServer.getCurrentWindow());
        windowServer.updateWindow(windowServer.getCurrentWindow());
    }

    windowServer.closeWindow(windowServer.getCurrentWindow());
    output.println("Closing editor!");

    return 0;
}