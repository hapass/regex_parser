#include <iostream>
#include "parser.hpp"

int main(int argumentCount, char* arguments[]) {
    auto parser = std::make_unique<regex_parser::Parser>();
    std::cout << "Expression is parsed: " << std::boolalpha << parser->parse() << "\n";
}