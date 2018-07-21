#include <iostream>
#include "arguments_parser.hpp"

using namespace regex_parser;

int main(int argumentCount, char const* arguments[]) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Brings up help.";
    helpDescription.type = Flag;

    ArgumentDescription regexDescription;
    regexDescription.name = "-r";
    regexDescription.description = "Regular expression.";
    regexDescription.type = String;

    ArgumentDescription valueDescription;
    valueDescription.name = "-v";
    valueDescription.description = "String that regular expression will match against.";
    valueDescription.type = String;

    auto argumentsParser = std::make_unique<ArgumentsParser>();
    argumentsParser
        ->configureArgument(helpDescription)
        ->configureArgument(regexDescription)
        ->configureArgument(valueDescription);

    argumentsParser->parse(argumentCount, arguments);

    if(argumentsParser->getArgumentCount() == 2 &&
       argumentsParser->hasArgument("-v") &&
       argumentsParser->hasArgument("-r")) {
        
        std::cout << argumentsParser->getArgumentValue("-v") << "\n"
            << argumentsParser->getArgumentValue("-r") << "\n";

        return 0;
    }

    std::cout << argumentsParser->getHelp();
    return 0;
}