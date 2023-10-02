#!/bin/bash

# Valores predeterminados
MESSAGE=""
# Directorio de salida
OUTPUT_DIR="$(dirname "$0")/perf-outputs"

# Crear el directorio si no existe
mkdir -p "$OUTPUT_DIR"
OUTPUT_FILE="$OUTPUT_DIR/output-$(date +%Y%m%d-%H%M%S).txt"
SAVE_TO_FILE=false

# Uso de getopts para analizar opciones
while getopts "m:o:s" opt; do
  case $opt in
    m) MESSAGE="$OPTARG";;      # -m para mensaje
    o) OUTPUT_FILE="$OPTARG";;  # -o para nombre del archivo de salida
    s) SAVE_TO_FILE=true;;     # -s para guardar en un archivo
    *) echo "Uso: $0 [-m mensaje] [-o archivo_de_salida] [-s]"; exit 1;;
  esac
done

if $SAVE_TO_FILE; then
    echo "$MESSAGE" > "$OUTPUT_FILE"
    echo "--------------------------------------------------" >> "$OUTPUT_FILE"
    {
      /usr/bin/perf stat /home/alvaro/CLionProjects/ArquiCompP1/cmake-build-debug/fluid/fluid 10 /home/alvaro/CLionProjects/ArquiCompP1/res/large.fld /home/alvaro/CLionProjects/ArquiCompP1/res/final.fld
    } 2>&1 | tee -a "$OUTPUT_FILE"
else
    # Si no se decide guardar en un archivo, simplemente ejecuta el comando y muestra la salida en la terminal
    /usr/bin/perf stat /home/alvaro/CLionProjects/ArquiCompP1/cmake-build-debug/fluid/fluid 10 /home/alvaro/CLionProjects/ArquiCompP1/res/large.fld /home/alvaro/CLionProjects/ArquiCompP1/res/final.fld
fi
