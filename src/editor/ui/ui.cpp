#include "ui.h"

#include <iostream>
#include <GLFW/glfw3.h>

using namespace Editor;

void UI::initUserInterface(GLFWwindow* window) 
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    m_io = &ImGui::GetIO();

    m_io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    m_io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    m_io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    m_io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 440");
}

void UI::setStyleColors(STYLE_COLORS theme) 
{
    if (theme == STYLE_COLORS::DARK) { ImGui::StyleColorsDark(); }
    else if (theme == STYLE_COLORS::LIGHT) { ImGui::StyleColorsLight(); }
    else { std::cout << "No ImGui theme selected -> using default theme (DARK)"; ImGui::StyleColorsDark(); }

    m_mainScale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(m_mainScale);      
    style.FontScaleDpi = m_mainScale;     
    
    if (m_io && (m_io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
}

void UI::updateUserInterface()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::DockSpaceOverViewport();

    bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();

#if defined(_WIN32)
    if (m_io && (m_io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
#endif
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::destroyUserInterface() 
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
