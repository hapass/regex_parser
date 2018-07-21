#pragma once

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "arguments_parser.hpp"
#include "argument_type.hpp"
#include "argument_description.hpp"

using namespace regex_parser;

TEST(ArgumentsParser, get_help_formats_help_properly) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    ArgumentDescription regexDescription;
    regexDescription.name = "-r";
    regexDescription.description = "Regex.";
    regexDescription.type = String;

    ArgumentDescription valueDescription;
    valueDescription.name = "-v";
    valueDescription.description = "String to match.";
    valueDescription.type = String;

    auto parser = std::make_unique<ArgumentsParser>();
    std::string help = parser
        ->configureArgument(helpDescription)
        ->configureArgument(regexDescription)
        ->configureArgument(valueDescription)
        ->getHelp();

    std::stringstream outStream;

    outStream
        << "Program accepts following arguments:" << "\n"
        << "    " << "-h" << " -> " << "Help." << "\n"
        << "    " << "-r [string]" << " -> " << "Regex." << "\n"
        << "    " << "-v [string]" << " -> " << "String to match." << "\n";

    EXPECT_EQ(help, outStream.str());
}

TEST(ArgumentsParser, get_flag_value_throws_argument_exception) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    auto parser = std::make_unique<ArgumentsParser>();
    parser->configureArgument(helpDescription);

    char const* arguments[] = { "-h" };
    parser->parse(1, arguments);

    bool isExceptionThrown = false;
    try {
        parser->getArgumentValue("-h");
    } catch(std::invalid_argument e) {
        isExceptionThrown = true;
    }

    EXPECT_EQ(isExceptionThrown, true);
}

TEST(ArgumentsParser, has_argument_returns_true_if_has_argument) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    auto parser = std::make_unique<ArgumentsParser>();
    parser->configureArgument(helpDescription);

    char const* arguments[] = { "-h" };
    parser->parse(1, arguments);

    EXPECT_EQ(parser->hasArgument("-h"), true);
}

TEST(ArgumentsParser, has_argument_returns_false_if_no_such_argument_configured) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    auto parser = std::make_unique<ArgumentsParser>();
    parser->configureArgument(helpDescription);

    char const* arguments[] = { "-h" };
    parser->parse(1, arguments);

    EXPECT_EQ(parser->hasArgument("--help"), false);
}

TEST(ArgumentsParser, get_argument_throws_exception_if_no_such_argument_configured) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    auto parser = std::make_unique<ArgumentsParser>();
    parser->configureArgument(helpDescription);

    char const* arguments[] = { "-h" };
    parser->parse(1, arguments);

    bool isExceptionThrown = false;
    try {
        parser->getArgumentValue("--help");
    } catch(std::invalid_argument e) {
        isExceptionThrown = true;
    }

    EXPECT_EQ(isExceptionThrown, true);
}

TEST(ArgumentsParser, get_string_value_returns_value) {
    ArgumentDescription regexDescription;
    regexDescription.name = "-r";
    regexDescription.description = "Regex.";
    regexDescription.type = String;

    auto parser = std::make_unique<ArgumentsParser>();
    parser->configureArgument(regexDescription);

    char const* arguments[] = { "-r", "regex" };
    parser->parse(2, arguments);

    EXPECT_EQ(parser->getArgumentValue("-r"), "regex");
}

TEST(ArgumentsParser, arguments_parser_recognizes_multiple_arguments) {
    ArgumentDescription helpDescription;
    helpDescription.name = "-h";
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    ArgumentDescription regexDescription;
    regexDescription.name = "-r";
    regexDescription.description = "Regex.";
    regexDescription.type = String;

    ArgumentDescription valueDescription;
    valueDescription.name = "-v";
    valueDescription.description = "String to match.";
    valueDescription.type = String;

    auto parser = std::make_unique<ArgumentsParser>();
    parser
        ->configureArgument(helpDescription)
        ->configureArgument(regexDescription)
        ->configureArgument(valueDescription);

    char const* arguments[] = { "-r", "regex", "-h", "-v", "value" };
    parser->parse(5, arguments);

    EXPECT_EQ(parser->hasArgument("-h"), true);
    EXPECT_EQ(parser->getArgumentValue("-r"), "regex");
    EXPECT_EQ(parser->getArgumentValue("-v"), "value");
}