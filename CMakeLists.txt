cmake_minimum_required(VERSION 3.10.0)

project(regex_parser VERSION 0.1.0)

#dependencies
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src" "${CMAKE_BINARY_DIR}/googletest-build")

#executable
add_library(regex_parser_lib
    src/main/cpp/parser.hpp
    src/main/cpp/parser.cpp
)
target_include_directories(regex_parser_lib PUBLIC src/main/cpp)

add_executable(regex_parser
    src/main/cpp/main.cpp
)
target_link_libraries (regex_parser regex_parser_lib)

#tests
include(GoogleTest)

add_executable (regex_parser_test
    src/test/cpp/test.cpp
)
target_link_libraries (regex_parser_test gtest_main regex_parser_lib)

enable_testing()

gtest_discover_tests(regex_parser_test)