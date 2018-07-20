#pragma once

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "arguments_parser.hpp"

using namespace regex_parser;

TEST(ArgumentsParser, getHelp) {
    auto parser = std::make_unique<ArgumentsParser>();
    char const* arguments[] = { "-fa", "first_argument_value", "-fs", "second_argument_value" };

    ArgumentDescription firstDescription;
    firstDescription.description = "first_argument";
    firstDescription.type = Path;

    ArgumentDescription secondDescription;
    secondDescription.description = "second_argument";
    secondDescription.type = Number;

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