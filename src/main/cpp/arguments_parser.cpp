#include <string>
#include <sstream>
#include "arguments_parser.hpp"

using namespace regex_parser;

ArgumentsParser::ArgumentsParser() {}

ArgumentsParser::~ArgumentsParser() {}

ArgumentsParser* ArgumentsParser::parse(int argumentCount, char const* arguments[]) {
    return this;
}

ArgumentsParser* ArgumentsParser::configureArgument(std::string name, ArgumentDescription description) {
    _map[name] = description;
    return this;
}

std::string ArgumentsParser::getValue() {
    return "value";
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