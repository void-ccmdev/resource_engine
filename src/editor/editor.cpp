#include "editor.h"
#include "ui/ui.h"

#include <iostream>

using namespace Editor;


int EditorApp::run()
{   
    running = true;

    std::string title = "Resource Engine - Editor";
    
    m_window.create(1280, 720, title);
    m_window.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    Editor::UI ui;
    ui.initUserInterface(m_window.getGlfwWindow());
    ui.setStyleColors(Editor::STYLE_COLORS::DARK);

    while (running && !m_window.shouldClose()) {
        ui.updateUserInterface();
        
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.update();
    }
    
    ui.destroyUserInterface();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }