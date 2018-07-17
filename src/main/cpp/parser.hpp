#pragma once

namespace regex_parser {
    class Parser {
        private:
            bool _isParsed;
        public:
            Parser();
            ~Parser();
            bool parse();
    };
}