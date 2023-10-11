#!/bin/bash

if [ ! -d "build" ]; then
   mkdir build
   cd build
   cmake -DCMAKE_CXX_FLAGS="-O0" -DCMAKE_C_FLAGS="-O0" -DCMAKE_BUILD_TYPE=Debug ..
   cd ..
fi

cmake --build build
