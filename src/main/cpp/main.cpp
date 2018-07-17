#include <iostream>
#include "parser.hpp"

int main(int, char**) {
    auto parser = new regex_parser::Parser();
    std::cout << "Expression is parsed: " << parser->parse() << "\n";
}