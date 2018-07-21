#include <iostream>
#include "arguments_parser.hpp"

using namespace regex_parser;

int main(int argumentCount, char* arguments[]) {
    auto argumentsParser = std::make_unique<ArgumentsParser>();

    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Prints help.";
    helpDescription.type = Flag;

    argumentsParser->configureArgument(helpDescription);

    ArgumentDescription regexOption;
    regexOption.name = "-r";
    regexOption.description = "Regular expression.";
    regexOption.type = String;

    argumentsParser->configureArgument(regexOption);

    std::cout << argumentsParser->getHelp();
}