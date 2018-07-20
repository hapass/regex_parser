#include <string.h>
#include "gtest/gtest.h"
#include "parser.hpp"

using namespace regex_parser;

TEST(Parser, parse) {
    bool result = false;
    auto parser = std::make_unique<Parser>();
    result = parser->parse();
    EXPECT_EQ(result, true);
}