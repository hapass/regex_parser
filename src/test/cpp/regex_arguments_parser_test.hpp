#pragma once

#include <string>
#include <sstream>
#include "regex_arguments_parser.hpp"
#include "gtest/gtest.h"
#include "illegal_state_exception.hpp"

using namespace regex_parser;

TEST(RegexArgumentsParser, get_help_gets_help_description_for_regex_parser) {
    char const* arguments[0];
    
    RegexArgumentsParser argumentsParser(0, arguments);
    std::string help = argumentsParser.getHelp();

    std::stringstream outStream;

    outStream
        << "Program accepts following arguments:" << std::endl
        << "    " << "-h" << " -> " << "Brings up help." << std::endl
        << "    " << "-r [string]" << " -> " << "Regular expression." << std::endl
        << "    " << "-v [string]" << " -> " << "String that regular expression will match against." << std::endl;

    EXPECT_EQ(help, outStream.str());
}

TEST(RegexArgumentsParser, get_regex_throws_exception_if_parser_in_incorrect_state_by_incomplete_arguments) {
    char const* arguments[] = { "-r", "regex" };
    RegexArgumentsParser argumentsParser(2, arguments);

    EXPECT_EQ(argumentsParser.getState(), Help);
    EXPECT_THROW(argumentsParser.getRegex(), IllegalStateException);
}

TEST(RegexArgumentsParser, get_text_throws_exception_if_parser_in_incorrect_state_by_incomplete_arguments) {
    char const* arguments[] = { "-v", "text" };
    RegexArgumentsParser argumentsParser(2, arguments);

    EXPECT_EQ(argumentsParser.getState(), Help);
    EXPECT_THROW(argumentsParser.getText(), IllegalStateException);
}

TEST(RegexArgumentsParser, get_text_and_value_throws_exception_if_parser_in_incorrect_state_by_amount_of_arguments) {
    char const* arguments[] = { "-v", "text", "-v", "value", "-h" };
    RegexArgumentsParser argumentsParser(5, arguments);

    EXPECT_EQ(argumentsParser.getState(), Help);
    EXPECT_THROW(argumentsParser.getText(), IllegalStateException);
    EXPECT_THROW(argumentsParser.getRegex(), IllegalStateException);
}

TEST(RegexArgumentsParser, get_text_and_regex_gets_values_if_parser_is_in_correct_state) {
    char const* arguments[] = { "-r", "regex", "-v", "value" };
    RegexArgumentsParser argumentsParser(4, arguments);

    EXPECT_EQ(argumentsParser.getState(), RegexParams);
    EXPECT_EQ(argumentsParser.getText(), "value");
    EXPECT_EQ(argumentsParser.getRegex(), "regex");
}