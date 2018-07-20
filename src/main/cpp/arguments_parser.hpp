#pragma once

#include <map>
#include <string>

namespace regex_parser {
    enum ArgumentType {
        Path,
        Number,
        String,
        Flag
    };

    class ArgumentDescription {
        public:
            std::string description;
            std::string value;
            bool hasValue;
            ArgumentType type;
    };

    class ArgumentsParser {
        private:
            std::map<std::string, ArgumentDescription> _map;
        public:
            ArgumentsParser();
            ~ArgumentsParser();

            ArgumentsParser* configureArgument(std::string name, ArgumentDescription description);
            ArgumentsParser* parse(int argumentCount, char const* arguments[]);

            std::string getValue(std::string name);
            bool hasFlag(std::string name);
            std::string getHelp();
    };
}