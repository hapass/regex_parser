mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
CTEST_OUTPUT_ON_FAILURE=TRUE make test_memcheck