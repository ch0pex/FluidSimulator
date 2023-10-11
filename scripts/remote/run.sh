#!/bin/bash

# Verificar si se proporcionó un argumento
if [ "$#" -eq 0 ]; then
    echo "Error: No se proporcionó ningún comando."
    echo "Uso: $0 <comando>"
    exit 1
fi

# Número de veces que deseas ejecutar el comando proporcionado
num_execuciones=$1

# Comando proporcionado como argumento
comando=${@:2}

echo "--------------------------------------------------"
echo "Ejecuciones: $num_execuciones"
# Ejecutar el comando proporcionado el número especificado de veces
for ((i = 1; i <= num_execuciones; i++)); do
    $comando &> /dev/null
done
echo "--------------------------------------------------"
