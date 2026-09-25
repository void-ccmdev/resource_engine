#pragma once

#include <string>
#include <vector>

#include "core/window.h"
#include "core/input.h"
#include "ui/ui.h"

namespace Engine
{
    class Output {
        public:
            void print(std::string value);
            void println(std::string value);
            void printWarning(std::string value);
            void printErr(std::string value);

            std::vector<std::string> getOutputLog();
        private:
            std::vector<std::string> m_log;
    };

    class WindowServer {
        public:
            void createWindow(unsigned int width, unsigned int height, std::string& title);
            void setWindowTitle(std::string& title, Window window);
            void updateWindow(Window window);
            void closeWindow(Window window);

            bool shouldWindowClose(Window window);
            void setWindowShouldClose(Window window, bool value);

            Window getCurrentWindow();
        private:
            Window m_currentWindow;
    };

    class InputServer {
        public:
            void addEvent(Input::InputEvent newEvent);
            void processInput(Window window);
        private:
            Input::InputManager m_inputManager;
    };

    class UIServer {
        public:
            void initialize();
            void update();
            void destroy();
        private:
            UI m_ui;
    };
} // namespace Engine
