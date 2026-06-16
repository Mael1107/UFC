#ifndef TYPES_H
#define TYPES_H

typedef enum {
    MOTORCYCLE = 1,
    CAR,
    BIKE,
    BUS,
    OTHERS
} Category;

typedef enum {
    SIMPLE_WASH = 1,
    FULL_WASH,
    OIL_EXCHANGE,
    CALIBRATE_TIRE,
    PAINTING
} Service;

typedef struct {
    int id;
    char phone[15];
    char name[50];
    char address[50];
} Client;

typedef struct {
    int id;
    int client_id;
    char plate[10];
    Category category_vehicle;
} Vehicle;

typedef struct {
    int id;
    int vehicle_id;
    int services_ids[5];
    int total_services;
    double total_price;
} Order;    

#endif