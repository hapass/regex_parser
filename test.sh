mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
make test_memcheck