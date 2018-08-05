#pragma once

#include <string>
#include <sstream>
#include "regex_arguments_parser.hpp"
#include "gtest/gtest.h"

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