#include "input.h"
#include "GLFW/glfw3.h"

#include <stdexcept>

void Input::addEvent(InputEvent newEvent)
{
    if (eventsCount >= sizeof(events) / sizeof(events[0])) {
        std::runtime_error("Too many input events! Max 64 Input events!");
        return;
    }

    events[eventsCount] = newEvent;
    eventsCount++;
}

void Input::processInput(GLFWwindow* window)
{
    for (unsigned int i = 0; eventsCount; i++) {
        if (events[i].device == KEYBOARD) {
            if (glfwGetKey(window, events[i].key) != events[i].state) continue;
        }
        else if (events[i].device == MOUSE) {
            if (glfwGetMouseButton(window, events[i].key) != events[i].state) continue;
        }

        const int ALT = glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS or
            glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;
        const int CTRL = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS or
            glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
        const int SHIFT = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS or
            glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
        const int SUPER = glfwGetKey(window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS or
            glfwGetKey(window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS;

        if (events[i].mod.alt and events[i].mod.alt != ALT) continue;
        if (events[i].mod.ctrl and events[i].mod.ctrl != CTRL) continue;
        if (events[i].mod.shift and events[i].mod.shift != SHIFT) continue;
        if (events[i].mod.super and events[i].mod.super != SUPER) continue;

        events[i].action();
    }
}
