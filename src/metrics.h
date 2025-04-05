#ifndef METRICS_H
#define METRICS_H

#include "utils.h" // Asumiendo que la estructura `order` está definida aquí

char *pms(order *orders, int size);
char *pls(order *orders, int size);

char *dms(order *orders, int size, double *total);
char *dls(order *orders, int size, double *total);

char *dmsp(order *orders, int size, int *cantidad_pizzas);
char *dlsp(order *orders, int size, int *cantidad_pizzas);

double apo(order *orders, int size);
double apd(order *orders, int size);

char *ims(order *orders, int size);
char *hp(order *orders, int size);

#endif // METRICS_H
