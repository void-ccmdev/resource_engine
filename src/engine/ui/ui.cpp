#include "ui.h"

#include <iostream>
#include <GLFW/glfw3.h>

using namespace Engine;

bool project_ProjectSettingsShow = false;

////////////////////////////
//ImGui Editor Definitions//
////////////////////////////



////////////////////////////
//Core Editor UI functions//
////////////////////////////


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
    glfwPollEvents();
    if (glfwGetWindowAttrib(glfwGetCurrentContext(), GLFW_ICONIFIED) != 0)
    {
        ImGui_ImplGlfw_Sleep(10);
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::DockSpaceOverViewport();

    /////////////
    //editor ui//
    /////////////


    //TopBar
    {   
        bool menu_File = false;
        bool menu_Scene = false;
        bool menu_Project = false;
        bool menu_Editor = false;
        bool menu_Debug = false;

        //bool show = true;
        //ImGui::ShowDemoWindow(&show);

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File", &menu_File)) {
                if (ImGui::MenuItem("New Scene", "Ctrl+N")) {}
                if (ImGui::MenuItem("Save Scene", "Ctrl+S")) {}
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Project", &menu_Project)) {
                if (ImGui::MenuItem("Project Settings", "Ctrl+,", &project_ProjectSettingsShow)) {
                    if (project_ProjectSettingsShow) {
                        ImGui::BeginChild("Project Settings", ImVec2(500, 500));
                        ImGui::Text("Shit");
                        ImGui::EndChild();
                    }
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Editor", &menu_Editor)) {
                if (ImGui::MenuItem("Editor Settings", "Ctrl+Shift+,")) {}
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Debug", &menu_Debug)) {
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
    }
    
    //Scene Tree Panel
    {
        ImGui::Begin("Scene tree");
        //Show nodes
        ImGui::End();
    }

    ////Viewport Panel
    //{
    //    ImGui::Begin("Viewport");     //LATER!!!
    //    
    //    ImGui::End();
    //}


    //Properties Panel
    {
        ImGui::Begin("Properties");
        //Show Properties of nodes
        ImGui::End();
    }

    //Filesystem / Assets Panel
    {
        ImGui::Begin("Assets");
        //Browse File system
        ImGui::End();
    }

    //Output
    {
        ImGui::Begin("Output");
        //Print from engine output
        ImGui::Text("----| Resource Engine -- 2026 -- v0.1 alpha |----");
        
        ImGui::End();
    }

    ImGui::Render();


    if (m_io && (m_io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::destroyUserInterface()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
