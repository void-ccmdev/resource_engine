#pragma once

#include <string>
#include <vector>

namespace Engine
{
    class Output {
        public:
            void print(std::string value);
            void println(std::string value);
            void printWarning(std::string value);
            void printErr(std::string value);

        private:
            std::vector<std::string> lines;
    };
} // namespace Engine

