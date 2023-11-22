#!/bin/sh


#Test funcional, ejecuta de  1 a 5 iteraciones tanto para la entrada small como large y las compara con los outputs de referencia
#proporcionados por el profesorado. Si son correctos se muestra por pantalla un mensaje de acierto, en caso contrario el propio cmp
#indicara por pantalla que hubo una discrepancia entre ambos archivos.
i=1
while [ "$i" -lt 6 ]; do

	build/fluid/fluid $i res/large.fld "outs/results-large-${i}.fld" > /dev/null 2>&1
	if cmp "outs/results-large-${i}.fld" "res/out/large-${i}.fld"; then
		echo "Resultados para large con ${i} iteraciones correctos"
	fi

	build/fluid/fluid $i res/small.fld "outs/results-small-${i}.fld" > /dev/null 2>&1
	if cmp "outs/results-small-${i}.fld" "res/out/small-${i}.fld"; then
		echo "Resultados para small con ${i} iteraciones correctos"
	fi
	i=$((i+1))
done

