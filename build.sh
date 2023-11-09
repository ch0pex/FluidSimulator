#!/bin/sh

mkdir build
cd build
. /etc/profile
module avail 
module load gcc/12.1.0
cmake .. -DCMAKE_BUILD_TYPE=Release 
cmake --build .
