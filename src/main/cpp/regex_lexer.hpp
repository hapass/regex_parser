#pragma once

#include <vector>
#include "token.hpp"

namespace regex_parser {
    class RegexLexer {
        public:
            std::vector<Token> scan(std::string expression);
    };
}