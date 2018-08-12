#include "token.hpp"
#include "illegal_state_exception.hpp"

using namespace regex_parser;

Token::Token(char character) {
    parse(character);
}

void Token::parse(char character) {
    switch(character) {
        case '.': {
            _type = Dot;
            break;
        }
        case '(': {
            _type = OpeningBracket;
            break;
        }
        case ')': {
            _type = ClosingBracket;
            break;
        }
        case '?': {
            _type = QuestionMark;
            break;
        }
        case '+': {
            _type = PlusSign;
            break;
        }
        case '*': {
            _type = Asterisk;
            break;
        }
        case '|': {
            _type = VerticalLine;
            break;
        }
        default: {
            _type = Letter;
            _value = character;
            break;
        }
    }
}

TokenType Token::getType() {
    return _type;
}

char Token::getValue() {
    if(_type != Letter) {
        throw IllegalStateException("Only letter tokens have value.");
    }

    return _value;
}