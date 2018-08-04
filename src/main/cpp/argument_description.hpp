#pragma once

#include <string>
#include "argument_type.hpp"

namespace regex_parser {
    class ArgumentDescription {
        public:
            std::string name = "";
            std::string description = "";
            std::string value = "";
            bool hasValue = false;
            ArgumentType type = Flag;
    };
}