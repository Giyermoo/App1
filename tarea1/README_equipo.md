# Proyecto App1 – Análisis de ventas de una pizzería

**Integrantes del equipo**

-Fernando Guaita  
-Guillermo Hidalgo  
-Fernanda Quirós

**Descripción general:**

Este programa fue desarrollado como parte de la tarea del ramo Lenguajes y Paradigmas de la Programación. El objetivo de este trabajp es procesar un archivo CSV con registros de ventas de pizzas y calcular una serie de métricas asociadas a la información contenida tales como las pizzas menos y mas vendidas, el promedio de pizzas, entre varias otras.

**Objetivos del proyecto:**

- Procesar datos desde un archivo CSV utilizando el lenguaje de programación C.
- Implementar estructuras y punteros para representar y manipular información de órdenes de venta.
- Calcular métricas relevantes como la pizza más vendida, promedios y tendencias, a partir de los datos leídos.
- Aplicar conceptos fundamentales de programación modular, memoria dinámica y uso de archivos.
- Desarrollar competencias en la organización de proyectos con Makefile y buenas prácticas de codificación.

**Estructura del proyecto:**

_ventas.csv_: Es el archivo de entrada con los datos de ventas de las pizzas. El archivo tiene filas y columnas donde podemos encontrar la informarción correspondiente a la venta de cada pizza como el tipo, la cantidad, el dia, entre otras.

_Makefile_: Es el archivo para compilación automatizada, este archivo contiene las instrucciones necesarias para compilar el código de manera eficiente, asegurando que el proyecto se pueda construir con el comando make.

_main.c_: Es la función principal 

_utils.c y utils.h_: Realizan la lectura del CSV y definiciones de estructuras  

_metrics.c y metrics.h_: Realizan el cálculo de métricas requeridas

**Compilación del proyecto:**
Desde la terminal o consola, ejecutar:

make app1
./app1 ventas.csv pms pls dms dls dmsp dlsp apo apd ims hp


**Uso de IA:**
Durante el desarrollo de este proyecto, se utilizó inteligencia artificial como herramienta de apoyo para:

-Aprender a estructurar correctamente el entorno de trabajo con Git y GitHub.
-Formular, organizar y depurar el código fuente en lenguaje C, asegurando modularidad, uso correcto de punteros y estructuras dinámicas.
-Comprender errores de segmentación, lectura de archivos y separación de responsabilidades entre archivos fuente.

El uso de IA fue formativo y supervisado, sin reemplazar la comprensión ni la autoría del trabajo desarrollado.


