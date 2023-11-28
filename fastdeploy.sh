#! /bin/bash

group="JFK"
cmake -S . -B build
cmake --build build

clear

chmod +x ./build/Books
echo "script made by $group group"
echo "Running Books"
./build/Books
