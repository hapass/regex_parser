#pragma once

#include <string>
#include "token_type.hpp"

namespace regex_parser {
    class Token {
        private:
            TokenType _type;
            char _value;

            void parse(char character);
        public:
            Token(char character);

            TokenType getType();
            char getValue();
    };
}