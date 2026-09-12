#include "engine.h"

#include "ui/ui.h"
#include "core/input.h"
#include "core/window.h"
#include "renderer/renderer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Engine;

void Output::print(std::string value) { std::cout << value.c_str(); m_log.push_back(value); }
void Output::println(std::string value) { std::cout << value.c_str() << std::endl; m_log.push_back(value + "\n"); }
void Output::printErr(std::string value) { std::cerr << "Error: " << value.c_str() << std::endl; m_log.push_back("Error: " + value + "\n"); }
void Output::printWarning(std::string value) { std::cout << "Warning: " << value.c_str() << std::endl; m_log.push_back("Warning: " + value + "\n"); }

std::vector<std::string> Output::getOutputLog() { return m_log; }
