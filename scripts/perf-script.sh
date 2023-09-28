#!/bin/sh
echo Running fluid
perf stat build/fluid/fluid 10 res/small.fld res/final.fld
