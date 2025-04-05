#include "metrics.h"
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include <float.h> // Para DBL_MAX
#include <stdio.h> // Para printf, si es necesario
// Función para encontrar la pizza más vendida
char *pms(order *orders, int size) {
    typedef struct {
        char *pizza;
        int cantidad;
    } PizzaCount;

    PizzaCount *conteo = (PizzaCount *) malloc(sizeof(PizzaCount) * size);

    int total_pizzas = 0;

    for (int i = 0; i < size; i++) {
        int encontrado = 0;
        for (int j = 0; j < total_pizzas; j++) {
            if (strcmp(orders[i].pizza_name, conteo[j].pizza) == 0) {
                conteo[j].cantidad += orders[i].quantity;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            conteo[total_pizzas].pizza = strdup(orders[i].pizza_name);
            conteo[total_pizzas].cantidad = orders[i].quantity;
            total_pizzas++;
        }
    }

    int max_index = 0;
    for (int i = 1; i < total_pizzas; i++) {
        if (conteo[i].cantidad > conteo[max_index].cantidad) {
            max_index = i;
        }
    }

    char *mas_vendida = strdup(conteo[max_index].pizza);

    for (int i = 0; i < total_pizzas; i++) {
        free(conteo[i].pizza);
    }
    free(conteo);

    return mas_vendida;
}

char *pls(order *orders, int size) {
    typedef struct {
        char *pizza;
        int cantidad;
    } PizzaCount;

    PizzaCount *conteo = (PizzaCount *) malloc(sizeof(PizzaCount) * size);
    int total_pizzas = 0;

    for (int i = 0; i < size; i++) {
        int encontrado = 0;
        for (int j = 0; j < total_pizzas; j++) {
            if (strcmp(orders[i].pizza_name, conteo[j].pizza) == 0) {
                conteo[j].cantidad += orders[i].quantity;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            conteo[total_pizzas].pizza = strdup(orders[i].pizza_name);
            conteo[total_pizzas].cantidad = orders[i].quantity;
            total_pizzas++;
        }
    }

    int min_index = 0;
    for (int i = 1; i < total_pizzas; i++) {
        if (conteo[i].cantidad < conteo[min_index].cantidad) {
            min_index = i;
        }
    }

    char *menos_vendida = strdup(conteo[min_index].pizza);

    for (int i = 0; i < total_pizzas; i++) {
        free(conteo[i].pizza);
    }
    free(conteo);

    return menos_vendida;
}

#include <string.h>
#include <stdlib.h>

char *dms(order *orders, int size, double *total) {
    typedef struct {
        char *fecha;
        double suma;
    } FechaVentas;

    FechaVentas *fechas = (FechaVentas *) malloc(sizeof(FechaVentas) * size);
    int num_fechas = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_fechas; j++) {
            if (strcmp(orders[i].order_date, fechas[j].fecha) == 0) {
                fechas[j].suma += orders[i].total_price;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            fechas[num_fechas].fecha = strdup(orders[i].order_date);
            fechas[num_fechas].suma = orders[i].total_price;
            num_fechas++;
        }
    }

    int max_index = 0;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].suma > fechas[max_index].suma) {
            max_index = i;
        }
    }

    *total = fechas[max_index].suma;
    char *resultado = strdup(fechas[max_index].fecha);

    for (int i = 0; i < num_fechas; i++) {
        free(fechas[i].fecha);
    }
    free(fechas);

    return resultado;
}

#include <string.h>
#include <stdlib.h>
#include <float.h>  // para usar DBL_MAX

char *dls(order *orders, int size, double *total) {
    typedef struct {
        char *fecha;
        double suma;
    } FechaVentas;

    FechaVentas *fechas = (FechaVentas *) malloc(sizeof(FechaVentas) * size);
    int num_fechas = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_fechas; j++) {
            if (strcmp(orders[i].order_date, fechas[j].fecha) == 0) {
                fechas[j].suma += orders[i].total_price;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            fechas[num_fechas].fecha = strdup(orders[i].order_date);
            fechas[num_fechas].suma = orders[i].total_price;
            num_fechas++;
        }
    }

    int min_index = 0;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].suma < fechas[min_index].suma) {
            min_index = i;
        }
    }
    *total = fechas[min_index].suma;
    char *resultado = strdup(fechas[min_index].fecha);

    for (int i = 0; i < num_fechas; i++) {
        free(fechas[i].fecha);
    }
    free(fechas);

    return resultado;
}

// dmsp: Fecha con más ventas en términos de cantidad de pizzas
char *dmsp(order *orders, int size, int *cantidad_pizzas) {
    typedef struct {
        char *fecha;
        int total;
    } FechaCantidad;

    FechaCantidad *fechas = (FechaCantidad *) malloc(sizeof(FechaCantidad) * size);
    int num_fechas = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_fechas; j++) {
            if (strcmp(orders[i].order_date, fechas[j].fecha) == 0) {
                fechas[j].total += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            fechas[num_fechas].fecha = strdup(orders[i].order_date);
            fechas[num_fechas].total = orders[i].quantity;
            num_fechas++;
        }
    }

    if (num_fechas == 0) {
        *cantidad_pizzas = 0;
        return strdup("N/A");
    }

    int max_index = 0;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].total > fechas[max_index].total) {
            max_index = i;
        }
    }

    *cantidad_pizzas = fechas[max_index].total;
    char *resultado = strdup(fechas[max_index].fecha);

    for (int i = 0; i < num_fechas; i++) {
        free(fechas[i].fecha);
    }
    free(fechas);

    return resultado;
}

char *dlsp(order *orders, int size, int *cantidad_pizzas) {
    typedef struct {
        char *fecha;
        int total;
    } FechaCantidad;

    FechaCantidad *fechas = (FechaCantidad *) malloc(sizeof(FechaCantidad) * size);
    int num_fechas = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_fechas; j++) {
            if (strcmp(orders[i].order_date, fechas[j].fecha) == 0) {
                fechas[j].total += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            fechas[num_fechas].fecha = strdup(orders[i].order_date);
            fechas[num_fechas].total = orders[i].quantity;
            num_fechas++;
        }
    }

    int min_index = 0;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].total < fechas[min_index].total) {
            min_index = i;
        }
    }

    *cantidad_pizzas = fechas[min_index].total;
    char *resultado = strdup(fechas[min_index].fecha);

    for (int i = 0; i < num_fechas; i++) {
        free(fechas[i].fecha);
    }
    free(fechas);

    return resultado;
}

// apo: Promedio de pizzas por orden
#include <string.h>
#include <stdlib.h>

double apo(order *orders, int size) {
    typedef struct {
        int order_id;
        int total_quantity;
    } Orden;

    Orden *ordenes = (Orden *) malloc(sizeof(Orden) * size);
    int num_ordenes = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_ordenes; j++) {
            if (orders[i].order_id == ordenes[j].order_id) {
                ordenes[j].total_quantity += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            ordenes[num_ordenes].order_id = orders[i].order_id;
            ordenes[num_ordenes].total_quantity = orders[i].quantity;
            num_ordenes++;
        }
    }

    int suma_total = 0;
    for (int i = 0; i < num_ordenes; i++) {
        suma_total += ordenes[i].total_quantity;
    }

    double promedio = (double)suma_total / num_ordenes;

    free(ordenes);
    return promedio;
}

// apd: Promedio de pizzas por día
#include <string.h>
#include <stdlib.h>

double apd(order *orders, int size) {
    typedef struct {
        char *fecha;
        int total_quantity;
    } VentaPorDia;

    VentaPorDia *dias = (VentaPorDia *) malloc(sizeof(VentaPorDia) * size);
    int num_dias = 0;

    for (int i = 0; i < size; i++) {
        int encontrado = 0;
        for (int j = 0; j < num_dias; j++) {
            if (strcmp(orders[i].order_date, dias[j].fecha) == 0) {
                dias[j].total_quantity += orders[i].quantity;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            dias[num_dias].fecha = strdup(orders[i].order_date);
            dias[num_dias].total_quantity = orders[i].quantity;
            num_dias++;
        }
    }

    int total_pizzas = 0;
    for (int i = 0; i < num_dias; i++) {
        total_pizzas += dias[i].total_quantity;
        free(dias[i].fecha);
    }

    free(dias);

    return (double)total_pizzas / num_dias;
}

// ims: Ingrediente más vendido
#include <string.h>
#include <stdlib.h>

char *ims(order *orders, int size) {
    typedef struct {
        char *ingrediente;
        int total;
    } IngredienteCount;

    IngredienteCount *ingredientes = (IngredienteCount *) malloc(sizeof(IngredienteCount) * size * 5);
    int num_ingredientes = 0;

    for (int i = 0; i < size; i++) {
        char *ingredientes_str = strdup(orders[i].pizza_ingredients);
        char *token = strtok(ingredientes_str, ",");

        while (token != NULL) {
            // Quitar espacios al inicio
            while (*token == ' ') token++;

            // Quitar espacios al final
            char *end = token + strlen(token) - 1;
            while (end > token && (*end == ' ' || *end == '\n')) {
                *end = '\0';
                end--;
            }

            // Verificar si ya existe ese ingrediente
            int encontrado = 0;
            for (int j = 0; j < num_ingredientes; j++) {
                if (strcmp(token, ingredientes[j].ingrediente) == 0) {
                    ingredientes[j].total += orders[i].quantity;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                ingredientes[num_ingredientes].ingrediente = strdup(token);
                ingredientes[num_ingredientes].total = orders[i].quantity;
                num_ingredientes++;
            }

            token = strtok(NULL, ",");
        }

        free(ingredientes_str);
    }

    // Buscar el ingrediente más vendido
    int max_index = 0;
    for (int i = 1; i < num_ingredientes; i++) {
        if (ingredientes[i].total > ingredientes[max_index].total) {
            max_index = i;
        }
    }

    char *resultado = strdup(ingredientes[max_index].ingrediente);

    for (int i = 0; i < num_ingredientes; i++) {
        free(ingredientes[i].ingrediente);
    }
    free(ingredientes);

    return resultado;
}

// hp: Cantidad de pizzas por categoría vendidas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *hp(order *orders, int size) {
    typedef struct {
        char *categoria;
        int total;
    } CategoriaCount;

    CategoriaCount *categorias = (CategoriaCount *) malloc(sizeof(CategoriaCount) * size);
    int num_categorias = 0;

    for (int i = 0; i < size; i++) {
        int encontrada = 0;
        for (int j = 0; j < num_categorias; j++) {
            if (strcmp(orders[i].pizza_category, categorias[j].categoria) == 0) {
                categorias[j].total += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            categorias[num_categorias].categoria = strdup(orders[i].pizza_category);
            categorias[num_categorias].total = orders[i].quantity;
            num_categorias++;
        }
    }

    // Calcular espacio total necesario para la cadena de resultado
    size_t buffer_size = 0;
    for (int i = 0; i < num_categorias; i++) {
        buffer_size += strlen(categorias[i].categoria) + 20; // nombre + número + \n
    }

    char *resultado = (char *) malloc(buffer_size + 1);
    resultado[0] = '\0';

    for (int i = 0; i < num_categorias; i++) {
        char linea[100];
        snprintf(linea, sizeof(linea), "- %s: %d\n", categorias[i].categoria, categorias[i].total);
        strcat(resultado, linea);
        free(categorias[i].categoria);
    }

    free(categorias);
    return resultado;
}
// Fin de METRICS.C













