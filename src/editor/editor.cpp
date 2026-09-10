#include "editor.h"

#include "../engine/ui/ui.h"
#include "../engine/engine.h"

#include <iostream>

using namespace Editor;

int EditorApp::run()
{
    running = true;

    std::string title = "Resource Engine - Editor";

    Engine::Output output;

    output.println("----------------------------------------");
    output.println("----| Resource Engine - v0.1 alpha |----");
    output.println("----------------------------------------");

    output.println("Loading application!");

    m_window.create(1280, 720, title);
    m_window.setClearColor(0.2f, 0.2f, 0.2f, 0.2f);

    output.println("Initializing Editor UI!");

    Engine::UI ui;
    ui.initUserInterface(m_window.getGlfwWindow());
    ui.setStyleColors(Engine::STYLE_COLORS::DARK);

    output.println("Initialized successfully!");

    while (running && !m_window.shouldClose()) {
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.pollEvents();


        ui.updateUserInterface(output);
        m_window.update();
    }

    output.println("----------------------------------------");
    output.println("----|    Exiting Resource Engine   |----");
    output.println("----------------------------------------");

    ui.updateUserInterface(output);
    ui.destroyUserInterface();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }
