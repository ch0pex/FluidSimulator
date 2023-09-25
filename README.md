# Proyecto de programacion orientada al rendimiento

- Marina Buitrago Perez
- Alvaro Cabrera Barrio 
- Alberto Diaz-Pacheco Corrales
- Miguel Dario Trosel Manrique

Tips de optimizacion:

    - C++ almacena los arrays multidimensionales por filas, no recomendable usar arrays multidimiensionales
    - Usar arrays unidimensionales, funcion para determinar posicioin i,j
    - Programacion orientada a datos

Normas y anotaciones:

     - No puede haber funciones con mas de 20 lineas
     - No puede haber funciones ocn mas de 4 parametros
     - Todo el calculo interno con doubles a la hora de escribir en el archivo lo pasamos a float

Pasos de la simulacion: 
- 1- Analisis de argumentos

       - Numero de argumentos correcto
       - Time step numerico
       - Time step no negativo
       - Archivo init para leer
       - Archivo final para escritura
- 2- Iniciacion de la simulacion

       - Longitud del suavizado
       - Masa de la particula
       - Vector de tamano de malla
       - Tamano de bloque de malla

- 3- Procesamiento de pasos de tiempo

       - Reposicionamiento de cada particual en la malla
       - Calculo de fuerzas y aceleraciones para cada particula
       - Procesamiento de colisiones
       - Movimiento de particulas
       - Procesamiento de limites

- 4- Almacenamiento de resultados

       - Tipo de archivo binario
       - Cabecera con ppm y np
       - Informacion de cad particula p, h, v

