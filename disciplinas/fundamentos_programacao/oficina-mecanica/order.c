#include "types.h"
#include <stdio.h>
#include <string.h>
#include "vehicle.h"
#include "service.h"

void add_order(Order orders[], int *total_orders, Vehicle vehicles[], int total_vehicles) {
    int vehicle_index, service_input;
    orders[*total_orders].total_services = 0;
    orders[*total_orders].total_price = 0;
    list_vehicles(vehicles, total_vehicles);
    do {
        printf("Enter the vehicle id:\n");
        scanf("%d", &orders[*total_orders].vehicle_id);
        while (getchar() != '\n');
        vehicle_index = vehicle_exists(vehicles, total_vehicles, orders[*total_orders].vehicle_id);

        if(vehicle_index == -1){ 
            printf("No vehicle with that id! Try again.\n");
        }
    } while(vehicle_index == -1);

    do {
        printf("What services do you want?\n");
        printf("1 - Simple Wash\n");
        printf("2 - Full Wash\n");
        printf("3 - Oil Exchange\n");
        printf("4 - Calibrate Tire\n");
        printf("5 - Painting\n");
        printf("0 <- Finish Order ->\n");
        scanf("%d", &service_input);
        while (getchar() != '\n');

        if (service_input == 0) {
            break; 
        }
        if (service_input < 1 || service_input > 5) {
            printf("Invalid service! Try again.\n");
            continue;
        }

        orders[*total_orders].services_ids[ orders[*total_orders].total_services ] = service_input;
        orders[*total_orders].total_services++;

    } while (1);

    for (int i = 0; i < orders[*total_orders].total_services; i++) {
        orders[*total_orders].total_price += service_price(orders[*total_orders].services_ids[i]);
    }

    orders[*total_orders].id = *total_orders + 1;
    printf("Order created successfully! Total: R$ %.2f\n", orders[*total_orders].total_price);
    (*total_orders)++;
} 


void list_orders(Order orders[], int total_orders) {
    if(total_orders == 0) {
        printf("No orders have been registered yet!\n");
        return;
    }

    for (int i = 0; i < total_orders; i++) {
        printf("\nOrder #%d | Vehicle ID: %d\n",
            orders[i].id,
            orders[i].vehicle_id
        );
        printf("Services:\n");
        for (int j = 0; j < orders[i].total_services; j++) {
            printf("  - %s (R$ %.2f)\n",
                service_to_string(orders[i].services_ids[j]),
                service_price(orders[i].services_ids[j])
            );
        }
        printf("TOTAL: R$ %.2f\n\n", orders[i].total_price);
    }
}

