#include <string>
#include "arguments_parser.hpp"

using namespace regex_parser;

ArgumentsParser::ArgumentsParser() {}

ArgumentsParser::~ArgumentsParser() {}

ArgumentsParser* ArgumentsParser::parse(int argumentCount, char const* arguments[]) {
    return this;
}

ArgumentsParser* ArgumentsParser::configureArgument(std::string name, std::string description) {
    return this;
}

std::string ArgumentsParser::getValue() {
    return "value";
}

std::string ArgumentsParser::getHelp() {
    return "help";
}