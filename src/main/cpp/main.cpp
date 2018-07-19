#include <iostream>
#include "parser.hpp"

using namespace regex_parser;

int main(int argumentCount, char* arguments[]) {
    //auto parser = std::make_unique<regex_parser::Parser>();
    Parser* parser = new Parser();
    std::cout << "Expression is parsed: " << std::boolalpha << parser->parse() << "\n";
}