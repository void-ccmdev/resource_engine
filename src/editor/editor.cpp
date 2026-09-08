#include "editor.h"

#include <iostream>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

using namespace Editor;

void kill() {
    std::cout << "Hello world!" << std::endl;
}

int EditorApp::run()
{   
    running = true;

    std::string title = "Resource Engine - Editor";
    
    m_window.create(1280, 720, title);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();
    bool show_demo_window = true;
    
    m_window.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    while (running && !m_window.shouldClose()) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }


        ImGui::Render();
        m_inputManager.processInput(m_window.getGlfwWindow());
        m_window.update();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    m_window.close();

    running = false;
    return 0;
}

void EditorApp::exit() { running = false; }