#!/bin/bash

cd build
. /etc/profile
module avail
module load gcc/12.1.0
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build 


perf stat -r 5 build/fluid/fluid 1000 res/large.fld res/large-temp.fld
