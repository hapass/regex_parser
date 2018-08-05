#include "regex.hpp"

using namespace regex_parser;

Regex::Regex() {
    _isParsed = false;
}

Regex::~Regex() {}

bool Regex::parse() {
    _isParsed = true;
    return _isParsed;
}