#include "engine.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Engine;


/////////////////////////
/////// -OUTPUT- ////////
/////////////////////////

void Output::print(std::string value) { std::cout << value.c_str(); m_log.push_back(value); }
void Output::println(std::string value) { std::cout << value.c_str() << std::endl; m_log.push_back(value + "\n"); }
void Output::printErr(std::string value) { std::cerr << "Error: " << value.c_str() << std::endl; m_log.push_back("Error: " + value + "\n"); }
void Output::printWarning(std::string value) { std::cout << "Warning: " << value.c_str() << std::endl; m_log.push_back("Warning: " + value + "\n"); }

std::vector<std::string> Output::getOutputLog() { return m_log; }

/////////////////////////
/////// -WINDOW- ////////
/////////////////////////

void WindowServer::createWindow(unsigned int width, unsigned int height, std::string& title)
{
    Window window;
    window.create(width, height, title);
    m_currentWindow = window;
}
void WindowServer::setWindowTitle(std::string& title, Window window) { window.setTitle(title); }
void WindowServer::closeWindow(Window window) { window.close(); }
void WindowServer::updateWindow(Window window) { window.update(); window.pollEvents(); }
bool WindowServer::shouldWindowClose(Window window) { return window.shouldClose(); }
void WindowServer::setWindowShouldClose(Window window, bool value) { window.setShouldClose(value); }

Window WindowServer::getCurrentWindow() { return m_currentWindow; }

/////////////////////////
/////// -INPUT- /////////
/////////////////////////

void InputServer::addEvent(Input::InputEvent newEvent) { m_inputManager.addEvent(newEvent); }
void InputServer::processInput(Window window) { m_inputManager.processInput(window.getGlfwWindow()); }

/////////////////////////
///////   -UI-  /////////
/////////////////////////

void UIServer::initialize() { m_ui.initUserInterface(); }
void UIServer::update() { m_ui.updateUserInterface(); }
void UIServer::destroy() { m_ui.destroyUserInterface(); }