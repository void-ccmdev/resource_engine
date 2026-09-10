#pragma once

#include <string>
#include <vector>

namespace Engine
{
    std::vector<std::string> getOutputLog();
    std::vector<std::string> log;
    class Output {
        public:
            void print(std::string value);
            void println(std::string value);
            void printWarning(std::string value);
            void printErr(std::string value);
    };
} // namespace Engine
