mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
valgrind --leak-check=full ./regex_parser
./test