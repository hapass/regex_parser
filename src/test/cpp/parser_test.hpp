#pragma once

#include <string.h>
#include "gtest/gtest.h"
#include "regex.hpp"

using namespace regex_parser;

TEST(Regex, parse) {
    bool result = false;
    auto parser = std::make_unique<Regex>();
    result = parser->parse();
    EXPECT_EQ(result, true);
}