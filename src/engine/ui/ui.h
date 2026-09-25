#pragma once

#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"



namespace Engine {
    enum UI_STYLE_COLORS {
        LIGHT,
        DARK
    };

    class UI {
        public:
            void initUserInterface();
            void updateUserInterface();
            void destroyUserInterface();
            void setToDefault();

            void setStyleColors(UI_STYLE_COLORS theme);
        private:
            float m_mainScale = 1.0f;
            ImGuiIO* m_io = nullptr;
    };
}
