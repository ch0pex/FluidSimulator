#!/bin/bash

# Directorio de salida
OUTPUT_DIR="$(dirname "$0")/perf-outputs"

# Crear el directorio si no existe
mkdir -p "$OUTPUT_DIR"

# Uso de getopts para analizar opciones
MESSAGE=""
SAVE_TO_FILE=false
SPECIFIED_OUTPUT=false
REPEATS=1
DEBUG=false

while getopts "m:o:sr:d" opt; do
  case $opt in
    m) MESSAGE="$OPTARG";;        # -m para mensaje
    o)
       OUTPUT_FILE="$OPTARG"
       SPECIFIED_OUTPUT=true
       ;;                        # -o para nombre del archivo de salida
    s) SAVE_TO_FILE=true;;       # -s para guardar en un archivo
    r) REPEATS="$OPTARG";;       # -r para número de repeticiones
    d) DEBUG=true;;
    *)
       echo "Uso: $0 [-m mensaje] [-o archivo_de_salida] [-s] [-r repeticiones]"
       exit 1
       ;;
  esac
done

# Si no se especifica un archivo de salida, usamos la fecha y hora actuales.
if [ "$SPECIFIED_OUTPUT" = false ]; then
    OUTPUT_FILE="$OUTPUT_DIR/output-$(date +%Y%m%d-%H%M%S).txt"
fi

if $DEBUG; then
  COMMAND="/usr/bin/perf stat  $REPEATS cmake-build-debug/fluid/fluid 10 res/large.fld res/final.fld"
else
  COMMAND="/usr/bin/perf stat -r $REPEATS cmake-build-release/fluid/fluid 10 res/large.fld res/final.fld"
fi

if $SAVE_TO_FILE; then
    if $DEBUG; then
      echo "$MESSAGE (Debug mode)" > "$OUTPUT_FILE"
    else
      echo "$MESSAGE (Release mode)" > "$OUTPUT_FILE"
    fi
    echo "--------------------------------------------------" >> "$OUTPUT_FILE"
      {
        echo "Ejecuciones: $REPEATS" >> "$OUTPUT_FILE"
        $COMMAND
        echo "--------------------------------------------------" >> "$OUTPUT_FILE"
      } 2>&1 | tee -a "$OUTPUT_FILE"
else
    # Si no se decide guardar en un archivo, simplemente ejecuta el comando y muestra la salida en la terminal
    $COMMAND
fi
