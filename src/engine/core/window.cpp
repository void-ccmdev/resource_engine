#include <glad/glad.h>
#include "window.h"

#include <string>
#include <stdexcept>

using namespace Engine;

void Window::create(unsigned int width, unsigned int height, std::string& title)
{
    if (glfwInit() != GLFW_TRUE) {
        std::runtime_error("Failed to initialize GLFW!");
    }

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        glfwTerminate();
        std::runtime_error("Failed to create a window!");
    }

    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);

    if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0) {
           glfwDestroyWindow(m_window);
           m_window = nullptr;
           glfwTerminate();
           throw std::runtime_error("Failed to initialize GLAD");
       }

    glfwGetFramebufferSize(m_window, &m_framebufferWidth, &m_framebufferHeight);
    glViewport(0, 0, m_framebufferWidth, m_framebufferHeight);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::update()
{
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(m_window);
}

void Window::close()
{
    if (m_window == nullptr) {
        return;
    }

    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::setTitle(std::string& title) { glfwSetWindowTitle(m_window, title.c_str()); }
void Window::setClearColor(float r, float g, float b, float a) { glClearColor(r,g,b,a); }

int Window::shouldClose() { return glfwWindowShouldClose(m_window); }
void Window::setShouldClose(bool value) { glfwSetWindowShouldClose(m_window, value); }

GLFWwindow* Window::getGlfwWindow() { return m_window; }

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    auto* owner = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (owner != nullptr) {
        owner->m_framebufferWidth = width;
        owner->m_framebufferHeight = height;
    }
    glViewport(0, 0, width, height);
}
