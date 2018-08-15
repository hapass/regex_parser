#pragma once

#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "regex_lexer.hpp"

using namespace regex_parser;

TEST(RegexLexer, lexer_reads_symbols_from_expression) {
    RegexLexer lexer;
    std::vector<Token> tokens = lexer.scan("a.(x|y)?g+h*b");
    
    EXPECT_EQ(13, tokens.size());

    EXPECT_EQ(Letter, tokens[0].getType());
    EXPECT_EQ('a', tokens[0].getValue());

    EXPECT_EQ(Dot, tokens[1].getType());
    EXPECT_THROW(tokens[1].getValue(), IllegalStateException);

    EXPECT_EQ(OpeningBracket, tokens[2].getType());
    EXPECT_THROW(tokens[2].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[3].getType());
    EXPECT_EQ('x', tokens[3].getValue());

    EXPECT_EQ(VerticalLine, tokens[4].getType());
    EXPECT_THROW(tokens[4].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[5].getType());
    EXPECT_EQ('y', tokens[5].getValue());

    EXPECT_EQ(ClosingBracket, tokens[6].getType());
    EXPECT_THROW(tokens[6].getValue(), IllegalStateException);

    EXPECT_EQ(QuestionMark, tokens[7].getType());
    EXPECT_THROW(tokens[7].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[8].getType());
    EXPECT_EQ('g', tokens[8].getValue());

    EXPECT_EQ(PlusSign, tokens[9].getType());
    EXPECT_THROW(tokens[9].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[10].getType());
    EXPECT_EQ('h', tokens[10].getValue());

    EXPECT_EQ(Asterisk, tokens[11].getType());
    EXPECT_THROW(tokens[11].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[12].getType());
    EXPECT_EQ('b', tokens[12].getValue());
}