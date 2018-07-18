#pragma once

#include <unordered_map>
#include <string>

namespace regex_parser {
    class ArgumentsParser {
        private:
            std::unordered_map<std::string, std::string> _map;
        public:
            ArgumentsParser();
            ~ArgumentsParser();

            ArgumentsParser* configureArgument(std::string name, std::string description);
            ArgumentsParser* parse(int argumentCount, char const* arguments[]);

            std::string getValue();
            std::string getHelp();
    };
}