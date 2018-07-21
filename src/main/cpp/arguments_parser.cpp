#include <string>
#include <sstream>
#include "arguments_parser.hpp"
#include "argument_type.hpp"
#include "argument_description.hpp"

using namespace regex_parser;

ArgumentsParser::ArgumentsParser() {
    _argumentCount = 0;
}

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

        if(isArgumentConfigured(argument)) {
            _argumentCount++;

            if(_map[argument].type == Flag) {
                _map[argument].hasValue = true;
                continue;
            }

            isArgumentValue = true;
        }
    }

    return this;
}

ArgumentsParser* ArgumentsParser::configureArgument(ArgumentDescription description) {
    if(description.name == "") {
        throw std::invalid_argument("Description must contain a flag name.");
    }
    _map[description.name] = description;
    return this;
}

std::string ArgumentsParser::getArgumentValue(std::string name) {
    if(!isArgumentConfigured(name)) {
        throw std::invalid_argument("There is no configured argument by this name: " + name + ".");
    }

    if(_map[name].type == Flag) {
        throw std::invalid_argument("This argument is a flag and has no value: " + name + ".");
    }

    return _map[name].value;
}

bool ArgumentsParser::hasArgument(std::string name) {
    return isArgumentConfigured(name) && _map[name].hasValue;
}

bool ArgumentsParser::isArgumentConfigured(std::string name) {
    return _map.count(name) == 1;
}

int ArgumentsParser::getArgumentCount() {
    return _argumentCount;
}

std::string ArgumentsParser::getHelp() {
    std::stringstream help;

    help << "Program accepts following arguments:" << "\n";

    for (std::pair<std::string, ArgumentDescription> element : _map) {
        help
            << "    " << element.second.name << getValueHelp(element.second.type)
            << " -> " << element.second.description << "\n";
    }

    return help.str();
}

std::string ArgumentsParser::getValueHelp(ArgumentType type) {
    if(type == String) {
        return " [string]";
    }

    return "";
}