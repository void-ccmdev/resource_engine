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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

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
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::update()
{
    glfwSwapBuffers(m_window);

    glfwGetFramebufferSize(m_window, &m_framebufferWidth, &m_framebufferHeight);
    glViewport(0, 0, m_framebufferWidth, m_framebufferHeight);


    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::close()
{
    if (m_window == nullptr) {
        return;
    }

    glfwDestroyWindow(m_window);
    //glfwTerminate();
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
