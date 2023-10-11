#!/bin/bash
echo "Cachegrind" 
valgrind --tool=cachegrind --cachegrind-out-file=cachegrind-large.out ./build/fluid/fluid 10 res/large.fld res/final.fld
cg_annotate cachegrind-large.out > details.out
