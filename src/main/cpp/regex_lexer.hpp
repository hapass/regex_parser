#pragma once

#include <string>
#include <vector>

namespace regex_parser {
    class RegexLexer {
        public:
            RegexLexer(std::string expression);

            std::vector<std::string> scan();
    };
}