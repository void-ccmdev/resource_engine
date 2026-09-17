#include "editor.h"

#include "../engine/ui/ui.h"
#include "../engine/engine.h"
#include "../engine/renderer/renderer.h"

#include <iostream>

using namespace Editor;

int EditorApp::run()
{
    running = true;

    std::string title = "Resource Engine - Editor";

    Engine::Output output;
    //Engine::Renderer renderer;

    output.println("----------------------------------------");
    output.println("----| Resource Engine - v0.1 alpha |----");
    output.println("----------------------------------------");

    output.println("Loading application!");

    m_window.create(1280, 720, title);
    m_window.setClearColor(0.2f, 0.2f, 0.2f, 0.2f);

    output.println("Initializing Editor UI!");

   //Engine::UI ui;
   //ui.initUserInterface(m_window.getGlfwWindow());
   //ui.setStyleColors(Engine::STYLE_COLORS::LIGHT);

    output.println("Initialized successfully!");

    while (running && !m_window.shouldClose()) {
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.pollEvents();

        //renderer.render();

       //ui.updateUserInterface(output);
        m_window.update();
    }

    //ui.updateUserInterface(output);
    //ui.destroyUserInterface();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }
