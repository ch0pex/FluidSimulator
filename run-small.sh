#!/bin/sh

perf stat build/fluid/fluid 250 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 500 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 750 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 1000 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 1250 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 1500  res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 1750  res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 2000 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 2250 res/small.fld res/small-temp.fld
perf stat build/fluid/fluid 2500 res/small.fld res/small-temp.fld





perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 250 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 500 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 750 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 1000 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 1250 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 1500 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 1750 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 2000 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 2250 res/small.fld res/small-temp.fld
perf stat -a -e 'energy-cores, energy-gpu,energy-pkg,energy-ram' build/fluid/fluid 2500 res/small.fld res/small-temp.fld
