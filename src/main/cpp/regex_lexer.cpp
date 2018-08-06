#include "regex_lexer.hpp"

using namespace regex_parser;

RegexLexer::RegexLexer(std::string expression) {

}

std::vector<std::string> RegexLexer::scan() {
    std::vector<std::string> vec;
    vec.push_back(".");
    return vec;
}