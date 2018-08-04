#include "regex_arguments_parser.hpp"

using namespace regex_parser;

const std::string RegexArgumentsParser::HELP_ARGUMENT = "-h";
const std::string RegexArgumentsParser::REGEX_ARGUMENT = "-r";
const std::string RegexArgumentsParser::VALUE_ARGUMENT = "-v";

RegexArgumentsParser::RegexArgumentsParser(int argumentCount, char const* arguments[]) {
    ArgumentDescription helpDescription;
    helpDescription.name = HELP_ARGUMENT;
    helpDescription.description = "Brings up help.";
    helpDescription.type = Flag;

    ArgumentDescription regexDescription;
    regexDescription.name = REGEX_ARGUMENT;
    regexDescription.description = "Regular expression.";
    regexDescription.type = String;

    ArgumentDescription valueDescription;
    valueDescription.name = VALUE_ARGUMENT;
    valueDescription.description = "String that regular expression will match against.";
    valueDescription.type = String;

    _argumentsParser = std::make_unique<ArgumentsParser>();
    _argumentsParser
        ->configureArgument(helpDescription)
        ->configureArgument(regexDescription)
        ->configureArgument(valueDescription);

    _argumentsParser->parse(argumentCount, arguments);
}

RegexArgumentsState RegexArgumentsParser::getState() {
    if(_argumentsParser->getArgumentCount() == 2 &&
        _argumentsParser->hasArgument(VALUE_ARGUMENT) &&
        _argumentsParser->hasArgument(REGEX_ARGUMENT)) {
        return Regex;
    }

    return Help;
}

std::string RegexArgumentsParser::getHelp() {
    return _argumentsParser->getHelp();
}

std::string RegexArgumentsParser::getRegex() {
    if(!_argumentsParser->hasArgument(REGEX_ARGUMENT)) {
        return "";
    }

    return _argumentsParser->getArgumentValue(REGEX_ARGUMENT);
}

std::string RegexArgumentsParser::getText() {
    if(!_argumentsParser->hasArgument(VALUE_ARGUMENT)) {
        return "";
    }

    return _argumentsParser->getArgumentValue(VALUE_ARGUMENT);
}