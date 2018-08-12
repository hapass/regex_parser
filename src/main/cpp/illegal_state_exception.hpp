#pragma once

#include <stdexcept>
#include <string>

namespace regex_parser {
    class IllegalStateException : public std::logic_error {
        public:
            IllegalStateException(std::string message): logic_error(message) {}
    };
}