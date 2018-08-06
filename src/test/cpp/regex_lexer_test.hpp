#pragma once

#include "regex_lexer.hpp"
#include <vector>
#include <string>
#include "gtest/gtest.h"

using namespace regex_parser;

TEST(RegexLexer, lexer_reads_dot_from_expression) {
    RegexLexer lexer("test.text");
    std::vector<std::string> tokens = lexer.scan();
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ(".", tokens[0]);
}