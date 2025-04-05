# Proyecto App1 – Análisis de ventas de una pizzería

**Integrantes del equipo**

- Fernando Guaita  
- Guillermo Hidalgo  
- Fernanda Quirós

**Descripción general:**

Este programa fue desarrollado como parte de la tarea del ramo **Lenguajes y Paradigmas de la Programación**. El objetivo de este trabajo es procesar un archivo CSV con registros de ventas de pizzas y calcular una serie de métricas asociadas a la información contenida tales como las pizzas menos y mas vendidas, el promedio de pizzas, entre varias otras.

**Objetivos del proyecto:**

- Procesar datos desde un archivo CSV utilizando el lenguaje de programación C.
- Implementar estructuras y punteros para representar y manipular información de órdenes de venta.
- Calcular métricas relevantes como la pizza más vendida, promedios y tendencias, a partir de los datos leídos.
- Aplicar conceptos fundamentales de programación modular, memoria dinámica y uso de archivos.
- Desarrollar competencias en la organización de proyectos con Makefile y buenas prácticas de codificación.

**Estructura del proyecto:**

**_ventas.csv_**: Es el archivo de entrada con los datos de ventas de las pizzas. El archivo tiene filas y columnas donde podemos encontrar la informarción correspondiente a la venta de cada pizza como el tipo, la cantidad, el dia, entre otras.

**_makefile_**: Es el archivo para compilación automatizada, este archivo contiene las instrucciones necesarias para compilar el código de manera eficiente, asegurando que el proyecto se pueda construir con el comando make.

**_main.c_**: Es la función principal. Es el archivo que coordina la ejecución del programa, lee el archivo de ventas, llama a las funciones de cálculo de métricas y muestra los resultados en la consola.

**_utils.c_**:  Realizan la lectura del CSV.  
**_utils.h_**: Es el archivo de encabezado que contiene las definiciones de las estructuras de datos. 

**_metrics.c_**: Contiene las funciones encargadas de realizar los cálculos de las métricas requeridas.  
**_metrics.h_**: Es el archivo de encabezado que contiene las declaraciones de las funciones de cálculo de métricas.

**Compilación del proyecto:**
Para poder ejecutar el codigo debemos desde el terminal ejecutar el siguiente comando:

`
make app1
./app1 ventas.csv pms pls dms dls dmsp dlsp apo apd ims hp
`

En este comando podemos ver que el _make app1_ compila el proyecto, _./app1 ventas.csv_ ejecuta el programa con el archivo csv y por ultimo las metricas _pms pls dms dls dmsp dlsp apo apd ims hp_ son las que queremos que se impriman una vez se ejecute el programa.

**Diagrama de flujo general del programa:**
[Inicio] 
   → Leer archivo ventas.csv 
      → Parsear datos y guardar en arreglo de structs (order[])
         → Recorrer argumentos desde línea de comandos (argv[i])
            → Por cada argumento:
               ¿Es un acrónimo válido de métrica?
                  → Sí:
                     → Llamar función correspondiente (e.g. pms, dms, etc.)
                        → Procesar datos de entrada
                        → Calcular resultado
                        → Imprimir resultado
                  → No:
                     → Ignorar o mostrar advertencia
         → Termina recorrido de métricas
   → Liberar memoria dinámica (free)
→ [Fin del programa]


**Razones de diseño y decisiones técnicas:**

- Se utilizó el tipo `struct order` para modelar cada fila del CSV, permitiendo un acceso claro y estructurado a los campos.
- Se usó `strtok` para separar las columnas del CSV debido a su eficiencia y compatibilidad con strings delimitados
- Para manejar memoria dinámica y copiar strings de longitud variable, se optó por `strdup`, permitiendo duplicar valores de texto sin sobrescribir los datos originales
- Las métricas se implementaron como funciones modulares para mantener el código ordenado y escalable.
- El uso de un `Makefile` permitió automatizar la compilación, facilitando pruebas rápidas y repetibles
- La lectura del CSV fue aislada en un archivo `utils.c`, separando la lógica de entrada/salida del procesamiento de datos.


**Uso de IA:**

Durante el desarrollo de este proyecto, se utilizó inteligencia artificial como herramienta de apoyo para:

-Aprender a estructurar correctamente el entorno de trabajo con Git y GitHub.
-Formular, organizar y depurar el código fuente en lenguaje C, asegurando modularidad, uso correcto de punteros y estructuras dinámicas.
-Comprender errores de segmentación, lectura de archivos y separación de responsabilidades entre archivos fuente.

El uso de IA fue formativo y supervisado, sin reemplazar la comprensión ni la autoría del trabajo desarrollado.

**Reflexión final:**

La realizacion de este proyecto represento un aprendizaje profundo y tangible, especialmente en el uso de punteros y comandos disponibles para el lenguaje C. Además, a lo largo del trabajo pudimos entender a mayor detalle como funcionan los archivos .c o .h en conjunto, así como la importancia de la claridad que hay que tener a la hora de definir cada archivo, variable, detalles, notación, etc. Esto fue escencial para permitir el buen funcionamiento del codigo.

Durante el trabajo, algunos de los mayores desafios que se nos presentaron fueron los siguientes: El mal traspaso de archivos mediante el mal uso de punteros, funciones mal estructuradas, mala obtención de datos desde el csv, datos repetidos con mismos valores, etc. (demasiados) pero se logro mediante la ayuda mutua y la ayuda de agentes externos (chat gpt, GitHub) determinar donde estaban los errores, entender a totalidad el código, los archivos y la función que cumple cada engranaje, con el resto.

Como equipo, logramos una distribución eficiente de tareas, dividiendo entre código, informe, desarrollo de GitHub, trabajo con IA, y un mix de ayuda mutua para que todos sepamos que se esta haciendo, así trabajamos de una manera mas integral, y menos separada entre todos, y de esta forma logramos que el proyecto resultara con éxito, con una estructura solida y funcional. El mayor aprendizaje fue reforzar el dominio de el lenguaje C en escenarios de procesamiento real de datos, donde el sistema funciona, no solo con nuestros datos, sino que es aplicable a cualquier data base (con los mismos parámetros), por lo que no es un trabajo sin mas, es un trabajo integral que podría servir en al realidad, ayudando a nuestra experiencia y consideración de la aplicación de los lenguajes.







**Referencias utilizadas:**

- [cppreference.com – C Library Reference](https://en.cppreference.com/)
- [cplusplus.com – strtok, malloc, strdup](https://cplusplus.com/)
- Documentación de MSYS2 y GCC
- Archivos CSV de prueba generados manualmente
- Respuestas validadas de ChatGPT (IA utilizada como guía técnica)

