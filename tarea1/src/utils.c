#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

order *read_csv(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }
 
    char line[MAX_LINE_LENGTH];
    order *orders = malloc(sizeof(order) * 100);  // Asumiendo un tamaño inicial
    int count = 0;

    fgets(line, sizeof(line), file);  // Leer y descartar la línea de encabezados
    while (fgets(line, sizeof(line), file)) {
        if (count >= 100) break;  // Para evitar desbordamiento si hay más de 100 líneas

        orders[count].pizza_id = atoi(strtok(line, ","));
        orders[count].order_id = atoi(strtok(NULL, ","));
        orders[count].pizza_name_id = strdup(strtok(NULL, ","));
        orders[count].quantity = atoi(strtok(NULL, ","));
        orders[count].order_date = strdup(strtok(NULL, ","));
        orders[count].order_time = strdup(strtok(NULL, ","));
        orders[count].unit_price = atof(strtok(NULL, ","));
        orders[count].total_price = atof(strtok(NULL, ","));
        orders[count].pizza_size = strdup(strtok(NULL, ","));
        orders[count].pizza_category = strdup(strtok(NULL, ","));   
        orders[count].pizza_ingredients = strdup(strtok(NULL, ","));
        orders[count].pizza_name = strdup(orders[count].pizza_name_id);


        count++;
    }
    fclose(file);
    *size = count;
    return orders;
}
