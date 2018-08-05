#pragma once

#include "arguments_parser.hpp"
#include "regex_arguments_state.hpp"

namespace regex_parser {
    class RegexArgumentsParser {
        private:
            std::unique_ptr<ArgumentsParser> _argumentsParser;
        public:
            static const std::string HELP_ARGUMENT;
            static const std::string REGEX_ARGUMENT;
            static const std::string VALUE_ARGUMENT;
            static const std::string REGEX_STATE_EXCEPTION;

            RegexArgumentsParser(int argumentCount, char const* arguments[]);

            RegexArgumentsState getState();
            std::string getRegex();
            std::string getText();
            std::string getHelp();
    };
}