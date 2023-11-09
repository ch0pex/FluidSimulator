#!/bin/sh

perf stat build/fluid/fluid 5 res/large.fld res/large-temp.fld
