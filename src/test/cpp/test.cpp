#include "regex_test.hpp"
#include "arguments_parser_test.hpp"
#include "regex_arguments_parser_test.hpp"
#include "regex_lexer_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}