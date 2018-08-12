#include "regex_lexer.hpp"
#include "token.hpp"

using namespace regex_parser;

std::vector<Token> RegexLexer::scan(std::string expression) {
    std::vector<Token> vec;

    for(char& character : expression) {
        vec.push_back(Token(character));
    }

    return vec;
}