#include <iostream>
#include "arguments_parser.hpp"

using namespace regex_parser;

int main(int argumentCount, char* arguments[]) {
    auto argumentsParser = std::make_unique<ArgumentsParser>();

    ArgumentDescription helpDescription;
    helpDescription.description = "Prints help.";
    helpDescription.type = Flag;

    argumentsParser->configureArgument("-h", helpDescription);

    ArgumentDescription regexOption;
    regexOption.description = "Regular expression.";
    regexOption.type = String;

    argumentsParser->configureArgument("-r", regexOption);

    std::cout << argumentsParser->getHelp();
}