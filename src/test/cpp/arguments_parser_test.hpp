#pragma once

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "arguments_parser.hpp"
#include "argument_type.hpp"
#include "argument_description.hpp"

using namespace regex_parser;

std::shared_ptr<ArgumentsParser> createTestParser() {
    ArgumentDescription flagDescription;
    flagDescription.name = "flag";
    flagDescription.description = "flag";
    flagDescription.type = Flag;

    ArgumentDescription firstStringDescription;
    firstStringDescription.name = "firstString";
    firstStringDescription.description = "firstString";
    firstStringDescription.type = String;

    ArgumentDescription secondStringDescription;
    secondStringDescription.name = "secondString";
    secondStringDescription.description = "secondString";
    secondStringDescription.type = String;

    auto parser = std::make_shared<ArgumentsParser>();
    parser
        ->configureArgument(flagDescription)
        ->configureArgument(firstStringDescription)
        ->configureArgument(secondStringDescription);

    return parser;
}

TEST(ArgumentsParser, get_help_formats_help_properly_in_alphabet_order) {
    auto parser = createTestParser();
    std::string help = parser->getHelp();

    std::stringstream outStream;

    outStream
        << "Program accepts following arguments:" << std::endl
        << "    " << "firstString [string]" << " -> " << "firstString" << std::endl
        << "    " << "flag" << " -> " << "flag" << std::endl
        << "    " << "secondString [string]" << " -> " << "secondString" << std::endl;

    EXPECT_EQ(help, outStream.str());
}

TEST(ArgumentsParser, get_flag_value_throws_argument_exception) {
    auto parser = createTestParser();

    char const* arguments[] = { "flag" };
    parser->parse(1, arguments);

    bool isExceptionThrown = false;
    try {
        parser->getArgumentValue("flag");
    } catch(std::invalid_argument e) {
        isExceptionThrown = true;
    }

    EXPECT_EQ(isExceptionThrown, true);
}

TEST(ArgumentsParser, has_argument_returns_true_if_has_argument) {
    auto parser = createTestParser();

    char const* arguments[] = { "flag" };
    parser->parse(1, arguments);

    EXPECT_EQ(parser->hasArgument("flag"), true);
}

TEST(ArgumentsParser, has_argument_returns_false_if_no_such_argument_configured) {
    auto parser = createTestParser();

    char const* arguments[] = { "flag" };
    parser->parse(1, arguments);

    EXPECT_EQ(parser->hasArgument("notConfiguredFlag"), false);
}

TEST(ArgumentsParser, get_argument_throws_exception_if_no_such_argument_configured) {
    auto parser = createTestParser();

    char const* arguments[] = { "flag" };
    parser->parse(1, arguments);

    bool isExceptionThrown = false;
    try {
        parser->getArgumentValue("notConfiguredFlag");
    } catch(std::invalid_argument e) {
        isExceptionThrown = true;
    }

    EXPECT_EQ(isExceptionThrown, true);
}

TEST(ArgumentsParser, get_string_value_returns_value) {
    auto parser = createTestParser();

    char const* arguments[] = { "firstString", "stringValue" };
    parser->parse(2, arguments);

    EXPECT_EQ(parser->getArgumentValue("firstString"), "stringValue");
}

TEST(ArgumentsParser, arguments_parser_recognizes_multiple_arguments) {
    auto parser = createTestParser();

    char const* arguments[] = { "firstString", "firstStringValue", "flag", "notConfiguredFlag", "secondString", "secondStringValue" };
    parser->parse(6, arguments);

    EXPECT_EQ(parser->hasArgument("flag"), true);
    EXPECT_EQ(parser->hasArgument("notConfiguredFlag"), false);
    EXPECT_EQ(parser->getArgumentValue("firstString"), "firstStringValue");
    EXPECT_EQ(parser->getArgumentValue("secondString"), "secondStringValue");
    EXPECT_EQ(parser->getArgumentCount(), 3);
}