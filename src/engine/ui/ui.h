#pragma once

#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Engine {
    enum STYLE_COLORS {
        LIGHT,
        DARK
    };

    class UI final {
        public:
            void initUserInterface(GLFWwindow* window);
            void updateUserInterface();
            void destroyUserInterface();
            void setToDefault();

            void setStyleColors(STYLE_COLORS theme);
        private:
            float m_mainScale = 1.0f;
            ImGuiIO* m_io = nullptr;
    };

    class Panel {
        public:
            void create(std::string title);
    };
}