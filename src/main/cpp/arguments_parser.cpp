#include <string>
#include <sstream>
#include "arguments_parser.hpp"

using namespace regex_parser;

ArgumentsParser::ArgumentsParser() {}

ArgumentsParser::~ArgumentsParser() {}

ArgumentsParser* ArgumentsParser::parse(int argumentCount, char const* arguments[]) {
    bool isArgumentValue = false;

    for(int i = 0; i < argumentCount; i++) {
        std::string argument = arguments[i];

        if(isArgumentValue) {
            std::string argumentName = arguments[i - 1];
            _map[argumentName].value = argument;
            _map[argumentName].hasValue = true;
            isArgumentValue = false;
            continue;
        }

        if(_map.count(argument) == 1) {
            if(_map[argument].type == Flag) {
                _map[argument].hasValue = true;
                continue;
            }

            isArgumentValue = true;
        }
    }

    return this;
}

ArgumentsParser* ArgumentsParser::configureArgument(std::string name, ArgumentDescription description) {
    description.hasValue = false;
    description.value = "";
    _map[name] = description;
    return this;
}

std::string ArgumentsParser::getValue(std::string name) {
    if(_map.count(name) != 1) {
        return "";
    }
    return _map[name].value;
}

bool ArgumentsParser::hasFlag(std::string name) {
    return _map.count(name) == 1 && _map[name].hasValue;
}

std::string ArgumentsParser::getHelp() {
    std::stringstream help;

    help << "Program accepts following arguments:" << "\n";

    for (std::pair<std::string, ArgumentDescription> element : _map) {
        help
            << "    " << element.first << " "
            << "[" << element.second.type << "]" 
            << " -> " << element.second.description << "\n";
    }

    return help.str();
}