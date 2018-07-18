#include "parser.hpp"

regex_parser::Parser::Parser() {
    _isParsed = false;
}

regex_parser::Parser::~Parser() {}

bool regex_parser::Parser::parse() {
    _isParsed = true;
    return _isParsed;
}