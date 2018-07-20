#include <string.h>
#include "gtest/gtest.h"
#include "arguments_parser.hpp"

using namespace regex_parser;

TEST(ArgumentsParser, getHelp) {
    auto parser = std::make_unique<ArgumentsParser>();
    char const* arguments[] = { "none" };
    std::string help = parser
        ->configureArgument("name", "value")
        ->configureArgument("name", "value")
        ->parse(1, arguments)
        ->getHelp();

    EXPECT_EQ(help, "help");
}

TEST(ArgumentsParser, getValue) {
    auto parser = std::make_unique<ArgumentsParser>();
    char const* arguments[] = { "none" };
    std::string value = parser
        ->configureArgument("name", "value")
        ->configureArgument("name", "value")
        ->parse(1, arguments)
        ->getValue();

    EXPECT_EQ(value, "value");
}