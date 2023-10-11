#!/bin/sh
echo Running fluid
perf stat scripts/run.sh 20 build/fluid/fluid 10 res/small.fld res/final.fld
