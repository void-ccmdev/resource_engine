#include "engine.h"

#include "ui/ui.h"
#include "core/input.h"
#include "core/window.h"

#include <iostream>

using namespace Engine;

void Output::print(std::string value) { std::cout << value.c_str(); }
void Output::println(std::string value) { std::cout << value.c_str() << std::endl; }
void Output::printErr(std::string value) { std::cerr << "Error: " << value.c_str() << std::endl; }
void Output::printWarning(std::string value) { std::cout << "Warning: " << value.c_str() << std::endl; }
