#pragma once

#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "regex_lexer.hpp"

using namespace regex_parser;

TEST(RegexLexer, lexer_reads_dot_from_expression) {
    RegexLexer lexer;
    std::vector<Token> tokens = lexer.scan("a.b");
    EXPECT_EQ(3, tokens.size());

    EXPECT_EQ(Letter, tokens[0].getType());
    EXPECT_EQ('a', tokens[0].getValue());

    EXPECT_EQ(Dot, tokens[1].getType());
    EXPECT_THROW(tokens[1].getValue(), IllegalStateException);

    EXPECT_EQ(Letter, tokens[2].getType());
    EXPECT_EQ('b', tokens[2].getValue());
}