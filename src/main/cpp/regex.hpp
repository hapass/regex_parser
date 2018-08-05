#pragma once

namespace regex_parser {
    class Regex {
        private:
            bool _isParsed;
        public:
            Regex();
            ~Regex();
            bool parse();
    };
}