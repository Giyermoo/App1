Proyecto App1 – Análisis de ventas de una pizzería

Integrantes del equipo
-Fernando Guaita
-Guillermo Hidalgo
-Fernanda Quirós

Descripción general:
Este programa fue desarrollado como parte de la tarea del ramo Lenguajes y Paradigmas de la Programación. El objetivo de este trabajp es procesar un archivo CSV con registros de ventas de pizzas y calcular una serie de métricas asociadas a la información contenida tales como las pizzas menos y mas vendidas, el promedio de pizzas, entre varias otras.

Estructura del proyecto:
ventas.csv: Es el archivo de entrada con los datos de ventas de las pizzas. El archivo tiene filas y columnas donde podemos encontrar la informarción correspondiente a la venta de cada pizza como el tipo, la cantidad, el dia, entre otras.
Makefile Es el archivo para compilación automatizada, este archivo contiene las instrucciones necesarias para compilar el código de manera eficiente, asegurando que el proyecto se pueda construir con el comando make.
main.c Es la función principal 
utils.c y utils.h Realizan la lectura del CSV y definiciones de estructuras  
metrics.c y metrics.h Realizan el cálculo de métricas requeridas

Compilación del proyecto:
Desde la terminal o consola, ejecutar:

make app1
./app1 ventas.csv pms pls dms dls dmsp dlsp apo apd ims hp


Uso de IA:
Durante el desarrollo de este proyecto, se utilizó inteligencia artificial como herramienta de apoyo para:

-Aprender a estructurar correctamente el entorno de trabajo con Git y GitHub.
-Formular, organizar y depurar el código fuente en lenguaje C, asegurando modularidad, uso correcto de punteros y estructuras dinámicas.
-Comprender errores de segmentación, lectura de archivos y separación de responsabilidades entre archivos fuente.

El uso de IA fue formativo y supervisado, sin reemplazar la comprensión ni la autoría del trabajo desarrollado.


