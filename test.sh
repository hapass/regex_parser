mkdir -p build
cd build

cmake -DCMAKE_BUILD_TYPE=Debug ..
make

export CTEST_OUTPUT_ON_FAILURE=TRUE

if [ "$1" == "memcheck" ]; then
    make test_memcheck
else
    make test
fi