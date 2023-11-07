#!/bin/sh

perf stat -r 5 build/fluid/fluid 1000 res/large.fld res/large-temp.fld
