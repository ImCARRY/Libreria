#! /bin/bash

cmake -S . -B build
cmake --build build

clear

chmod +x ./build/Books
./build/Books
