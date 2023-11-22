#!/bin/sh

#Test funcional del programa en caso de que algun output no coincida con los outputs de referencia
#proporcionados, este script mostrar por pantalla en cuantos bytes y donde difieren los outputs

build/fluid/fluid 1 res/large.fld outs/results-large-1.fld
build/fluid/fluid 2 res/large.fld outs/results-large-2.fld
build/fluid/fluid 3 res/large.fld outs/results-large-3.fld
build/fluid/fluid 4 res/large.fld outs/results-large-4.fld
build/fluid/fluid 5 res/large.fld outs/results-large-5.fld

build/fluid/fluid 1 res/small.fld outs/results-small-1.fld
build/fluid/fluid 2 res/small.fld outs/results-small-2.fld
build/fluid/fluid 3 res/small.fld outs/results-small-3.fld
build/fluid/fluid 4 res/small.fld outs/results-small-4.fld
build/fluid/fluid 5 res/small.fld outs/results-small-5.fld

cmp outs/results-large-1.fld res/out/large-1.fld
cmp outs/results-large-2.fld res/out/large-2.fld
cmp outs/results-large-3.fld res/out/large-3.fld
cmp outs/results-large-4.fld res/out/large-4.fld
cmp outs/results-large-5.fld res/out/large-5.fld

cmp outs/results-small-1.fld res/out/small-1.fld
cmp outs/results-small-2.fld res/out/small-2.fld
cmp outs/results-small-3.fld res/out/small-3.fld
cmp outs/results-small-4.fld res/out/small-4.fld
cmp outs/results-small-5.fld res/out/small-5.fld
