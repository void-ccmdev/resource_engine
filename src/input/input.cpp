#include "input.h"
#include "GLFW/glfw3.h"

#include <stdexcept>
#include <iostream>

using namespace Input;

void InputManager::addEvent(InputEvent newEvent)
{
    if (eventsCount >= sizeof(events) / sizeof(events[0])) {
        std::runtime_error("Too many input events! Max 64 Input events!");
        return;
    }

    events[eventsCount] = newEvent;
    eventsCount++;
}

void InputManager::processInput(GLFWwindow* window)
{
    for (InputEvent event : events) {
        if (event.device == KEYBOARD) {
            if (glfwGetKey(window, event.key) != event.state) continue;
        } else if (event.device == MOUSE) {
            if (glfwGetMouseButton(window, event.key) != event.state) continue;
        } else {
            std::runtime_error("Unknown device!");
            break;
        }

        const int ALT = glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;
        const int CTRL = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
        const int SHIFT = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
        const int SUPER = glfwGetKey(window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS|| glfwGetKey(window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS;

        if (event.mod.alt && event.mod.alt != ALT) continue;
        if (event.mod.ctrl && event.mod.ctrl != CTRL) continue;
        if (event.mod.shift && event.mod.shift != SHIFT) continue;
        if (event.mod.super && event.mod.super != SUPER) continue;

        if (event.action) {
            event.action();
            std::cout << "Called " << event.name << "." <<std::endl;
        }
    }
}
