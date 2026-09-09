#include "editor.h"
#include "ui/ui.h"

#include <iostream>

using namespace Editor;

int EditorApp::run()
{
    running = true;

    std::string title = "Resource Engine - Editor";

    m_window.create(1280, 720, title);
    m_window.setClearColor(0.2f, 0.2f, 0.2f, 0.2f);

    Editor::UI ui;
    ui.initUserInterface(m_window.getGlfwWindow());
    ui.setStyleColors(Editor::STYLE_COLORS::DARK);

    while (running && !m_window.shouldClose()) {
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.pollEvents();
        ui.updateUserInterface();
        m_window.update();
    }

    ui.destroyUserInterface();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }
