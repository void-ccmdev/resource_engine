#include "editor.h"

#include "../engine/ui/ui.h"
#include "../engine/engine.h"

#include <iostream>

using namespace Editor;

int EditorApp::run()
{
    running = true;

    std::string title = "Resource Engine - Editor";

    m_window.create(1280, 720, title);
    m_window.setClearColor(0.2f, 0.2f, 0.2f, 0.2f);

    Engine::UI ui;
    ui.initUserInterface(m_window.getGlfwWindow());
    ui.setStyleColors(Engine::STYLE_COLORS::DARK);

    Engine::Output output;

    while (running && !m_window.shouldClose()) {
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.pollEvents();
        output.print("Hello!");
        output.println("New line :3");
        output.printWarning("Eh...");
        output.printErr("Oh no :(");
        ui.updateUserInterface();
        m_window.update();
    }

    output.println("Ending!");
    for (const std::string& line : Engine::getOutputLog()) {
            std::cout << line;
        }

    ui.destroyUserInterface();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }
