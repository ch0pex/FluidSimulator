#!/bin/bash

# Uso de getopts para analizar opciones
REPEATS=1
DEBUG=false

while getopts "r:d" opt; do
  case $opt in
    r) REPEATS="$OPTARG";;       # -r para número de repeticiones
    d) DEBUG=true;;
    *)
       echo "Uso: $0  [-r repeticiones]"
       exit 1
       ;;
  esac
done

# Si no se especifica un archivo de salida, usamos la fecha y hora actuales.
echo "Media de tiempo en $REPEATS ejecuciones"
if $DEBUG; then
  COMMAND="perf stat -r $REPEATS build/fluid/fluid 10 res/large.fld res/final.fld"
else
  COMMAND="perf stat -r $REPEATS build/fluid/fluid 10 res/large.fld res/final.fld"
fi
$COMMAND

