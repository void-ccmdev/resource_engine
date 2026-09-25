#include "editor_app.h"

#include "GLFW/glfw3.h"
#include "core/input.h"
#include "engine.h"

Engine::Output output;
Engine::InputServer inputServer;
Engine::WindowServer windowServer;
Engine::UIServer uiServer;

using namespace Editor;

void forceQuit() { windowServer.setWindowShouldClose(windowServer.getCurrentWindow(), true); }

int App::run()
{   
    output.println("Launching editor!");
    output.println(
        " ___ ___ ___  ___  _   _ ___  ___ ___     \n"
        "| _ | __/ __|/ _ || | | | _ |/ __| __|    \n"
        "|   / _||__ | (_) | |_| |   / (__| _|     \n"
        "|_|_|___|___/|___/ |___/|_|_||___|___|    \n"
        "| __| || |/ __|_ _| || | __|\n"
        "| _|| .` | (_ || || .` | _| \n"
        "|___|_||_||___|___|_||_|___|\n"
    );
    windowServer.createWindow(1280, 720, title);
    uiServer.initialize();

    Input::InputEvent e_quit;
    {
        e_quit.name = "force_quit";
        e_quit.action = forceQuit;
        e_quit.device = Input::Device::KEYBOARD;
        e_quit.key = GLFW_KEY_END;
        e_quit.mod.alt = true;
    }
    inputServer.addEvent(e_quit);

    while (!windowServer.shouldWindowClose(windowServer.getCurrentWindow()))
    {
        windowServer.updateWindow(windowServer.getCurrentWindow());
        inputServer.processInput(windowServer.getCurrentWindow());
        uiServer.update();
    }

    uiServer.destroy();
    windowServer.closeWindow(windowServer.getCurrentWindow());
    output.print("Closing editor!");

    return 0;
}