cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(regex_parser VERSION 0.1.0)

#dependencies
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src" "${CMAKE_BINARY_DIR}/googletest-build")

#executable
add_library(regex_parser_lib
    src/main/cpp/parser.cpp
    src/main/cpp/arguments_parser.cpp
    src/main/cpp/regex_arguments_parser.cpp
)

add_executable(regex_parser
    src/main/cpp/main.cpp
)
target_link_libraries(regex_parser regex_parser_lib)

#tests
include(GoogleTest)
include(CTest)

add_executable (test_regex
    src/test/cpp/test.cpp
)

target_link_libraries(test_regex gtest_main regex_parser_lib)
target_include_directories(test_regex PUBLIC src/main/cpp)

gtest_discover_tests(test_regex)

add_custom_target(test_memcheck
    COMMAND ${CMAKE_CTEST_COMMAND} -T memcheck -S
)
