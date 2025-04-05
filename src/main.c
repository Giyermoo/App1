#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"
#include "utils.h"
 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <ventas.csv>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int size = 0;
    order *orders = read_csv(filename, &size);

    if (orders == NULL) {
        fprintf(stderr, "Error al leer el archivo CSV.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "pms") == 0) {
            char *pizza = pms(orders, size);
            printf("Pizza mas vendida: %s\n", pizza);
            free(pizza);
        } else if (strcmp(argv[i], "pls") == 0) {
            char *pizza = pls(orders, size);
            printf("Pizza menos vendida: %s\n", pizza);
            free(pizza);
        } else if (strcmp(argv[i], "dms") == 0) {
            double total;
            char *fecha = dms(orders, size, &total);
            printf("Fecha con mas ventas en dinero: %s, Total recaudado: $%.2f\n", fecha, total);
            free(fecha);
        
        } else if (strcmp(argv[i], "dls") == 0) {
            double total;
            char *fecha = dls(orders, size, &total);
            printf("Fecha con menos ventas en dinero: %s, Total recaudado: $%.2f\n", fecha, total);
            free(fecha);
        } else if (strcmp(argv[i], "dmsp") == 0) {
            int cantidad;
            char *fecha = dmsp(orders, size, &cantidad);
            printf("Fecha con mas ventas en cantidad de pizzas: %s, Cantidad: %d\n", fecha, cantidad);
            free(fecha);
        } else if (strcmp(argv[i], "dlsp") == 0) {
            int cantidad;
            char *fecha = dlsp(orders, size, &cantidad);
            printf("Fecha con menos ventas en cantidad de pizzas: %s, Cantidad: %d\n", fecha, cantidad);
            free(fecha);
        } else if (strcmp(argv[i], "apo") == 0) {
            double promedio = apo(orders, size);
            printf("Promedio de pizzas por orden: %.2f\n", promedio);
        } else if (strcmp(argv[i], "apd") == 0) {
            double promedio = apd(orders, size);
            printf("Promedio de pizzas por dia: %.2f\n", promedio);
        } else if (strcmp(argv[i], "ims") == 0) {
            char *ingrediente = ims(orders, size);
            printf("Ingrediente mas vendido: %s\n", ingrediente);
            free(ingrediente);
        } else if (strcmp(argv[i], "hp") == 0) {
            char *categorias = hp(orders, size);
            printf("Cantidad de pizzas por categoria vendidas:\n%s", categorias);
            free(categorias);
        } else {
            printf("Metrica no reconocida: %s\n", argv[i]);
        }
    }

    free(orders);
    return 0;
}
