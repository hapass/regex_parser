#include <string.h>

#include "gtest/gtest.h"

#include "parser.hpp"
#include "arguments_parser.hpp"

using namespace regex_parser;

TEST(Parser, parse) {
    bool result = false;
    auto parser = std::make_unique<Parser>();
    result = parser->parse();
    EXPECT_EQ(result, true);
}

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}