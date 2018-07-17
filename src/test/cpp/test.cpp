#include <string.h>

#include "gtest/gtest.h"
#include "parser.hpp"

using namespace regex_parser;

TEST(Parser, parse) {
    bool result = false;
    auto parser = new Parser();
    result = parser->parse();
    EXPECT_EQ(result, true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}