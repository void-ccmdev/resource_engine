#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Engine {
    class Window final {
        public:
            void create(
                unsigned int width,
                unsigned int height,
                std::string& title
            );

            void update();
            void close();

            void setTitle(std::string& title);
            void setClearColor(float r, float g , float b, float a);

            int shouldClose();
            void setShouldClose(bool value);
            GLFWwindow* getGlfwWindow();
        private:
            static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

            GLFWwindow* m_window = nullptr;
            int m_framebufferWidth = 0;
            int m_framebufferHeight = 0;
    };

}  //namespace Engine
