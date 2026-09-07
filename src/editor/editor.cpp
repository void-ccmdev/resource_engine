#include "editor.h"

#include <iostream>

using namespace Editor;

void kill() {
    std::cout << "Hello world!" << std::endl;
}

int EditorApp::run()
{   
    running = true;

    std::string title = "Resource Engine - Editor";
    
    m_window.create(1280, 720, title);

    
    m_window.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    while (running && !m_window.shouldClose()) {
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.update();
    }
    
    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }