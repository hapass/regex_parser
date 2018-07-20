#pragma once

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "arguments_parser.hpp"

using namespace regex_parser;

TEST(ArgumentsParser, getHelp) {
    ArgumentDescription firstDescription;
    firstDescription.description = "first_argument";
    firstDescription.type = Path;

    ArgumentDescription secondDescription;
    secondDescription.description = "second_argument";
    secondDescription.type = Number;

    auto parser = std::make_unique<ArgumentsParser>();
    std::string help = parser
        ->configureArgument("-fa", firstDescription)
        ->configureArgument("-fs", secondDescription)
        ->getHelp();

    std::stringstream outStream;

    outStream 
        << "Program accepts following arguments:" << "\n"
        << "    " << "-fa [0]" << " -> " << "first_argument" << "\n"
        << "    " << "-fs [1]" << " -> " << "second_argument" << "\n";

    EXPECT_EQ(help, outStream.str());
}

TEST(ArgumentsParser, getValue) {
    ArgumentDescription helpDescription;
    helpDescription.description = "Help.";
    helpDescription.type = Flag;

    ArgumentDescription regexDescription;
    regexDescription.description = "Regex.";
    regexDescription.type = String;

    auto parser = std::make_unique<ArgumentsParser>();
    parser
        ->configureArgument("-h", helpDescription)
        ->configureArgument("-r", regexDescription);

    char const* arguments[] = { "-h", "-r", "regex" };
    parser->parse(3, arguments);

    EXPECT_EQ(parser->hasFlag("-h"), true);
    EXPECT_EQ(parser->getValue("-h"), "");

    EXPECT_EQ(parser->hasFlag("-r"), true);
    EXPECT_EQ(parser->getValue("-r"), "regex");

    EXPECT_EQ(parser->hasFlag("--help"), false);
    EXPECT_EQ(parser->getValue("--help"), "");
}