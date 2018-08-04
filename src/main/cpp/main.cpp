#include <iostream>
#include "regex_arguments_parser.hpp"

using namespace regex_parser;

int main(int argumentCount, char const* arguments[]) {
    RegexArgumentsParser argumentsParser(argumentCount, arguments);

    switch(argumentsParser.getState()) {
        case Regex: {
            std::cout << argumentsParser.getText() << std::endl;
            std::cout << argumentsParser.getRegex() << std::endl;
            break;
        }
        default: {
            std::cout << argumentsParser.getHelp();
            break;
        }
    }

    return 0;
}