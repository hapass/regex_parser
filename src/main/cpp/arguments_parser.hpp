#pragma once

#include <map>
#include <string>
#include "argument_description.hpp"
#include "argument_type.hpp"

namespace regex_parser {
    class ArgumentsParser {
        private:
            std::map<std::string, ArgumentDescription> _map;
            std::string getValueHelp(ArgumentType type);
        public:
            ArgumentsParser();
            ~ArgumentsParser();

            ArgumentsParser* configureArgument(ArgumentDescription description);
            ArgumentsParser* parse(int argumentCount, char const* arguments[]);

            std::string getArgumentValue(std::string name);
            bool hasArgument(std::string name);
            bool isArgumentConfigured(std::string name);

            std::string getHelp();
    };
}