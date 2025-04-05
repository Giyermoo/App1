#ifndef UTILS_H
#define UTILS_H

typedef struct {
    int pizza_id;
    int order_id;
    char *pizza_name_id;
    int quantity;
    char *order_date;
    char *order_time;
    double unit_price;
    double total_price;
    char *pizza_size;
    char *pizza_category;
    char *pizza_ingredients;
    char *pizza_name;
} order;
 
order *read_csv(const char *filename, int *size);

#endif // UTILS_H
