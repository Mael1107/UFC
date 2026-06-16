#include <stdio.h>
#include "types.h"
#include "client.h"
#include "vehicle.h"
#include "order.h"

int main() {
    Client clients[100];
    Vehicle vehicles[100];
    Order orders[100];

    int total_clients = 0;
    int total_vehicles = 0;
    int total_orders = 0;

    int option, sub_option;

    do {
        printf("\nWich entity do you want to operate?\n\n");
        printf("1 - Clients\n");
        printf("2 - Vehicles\n");
        printf("3 - Orders\n");
        printf("0 - Exit Menu\n\n");
        scanf("%d", &option);
        while (getchar() != '\n');

        switch(option) {
            case 0: printf("Bye...\n"); break;
            case 1:
                printf("\nWhat do you want do?\n\n");
                printf("1 - Add Client\n");
                printf("2 - list clients\n");
                printf("3 - Delete Client\n\n");
                scanf("%d", &sub_option);
                while (getchar() != '\n');

                switch(sub_option) {
                    case 1: add_client(clients, &total_clients); break;
                    case 2: list_clients(clients, total_clients); break;
                    case 3: delete_client(clients, &total_clients); break;
                    default: printf("Invalid option! Choose between 1 and 3.\n");
                }
                break;
            case 2:
                printf("\nWhat do you want do?\n\n");
                printf("1 - Add Vehicle\n");
                printf("2 - List Vehicles\n");
                printf("3 - Delete Vehicle\n");
                scanf("%d", &sub_option);
                while (getchar() != '\n');
                
                switch(sub_option) {
                    case 1: add_vehicle(vehicles, &total_vehicles, clients, total_clients); break;
                    case 2: list_vehicles(vehicles, total_vehicles); break;
                    case 3: delete_vehicle(vehicles, &total_vehicles); break;
                    default: printf("Invalid option! Choose between 1 and 3.\n");
                }
                break;
            case 3:
                printf("\nWhat do you want do?\n\n");
                printf("1 - New order\n");
                printf("2 - List orders\n");
                scanf("%d", &sub_option);
                while(getchar() != '\n');

                switch(sub_option) {
                    case 1: add_order(orders, &total_orders, vehicles, total_vehicles); break;
                    case 2: list_orders(orders, total_orders); break;
                    default: printf("Invalid option! Choose between 1 and 2.\n");
                }
                break;
            default:
                printf("Invalid option! Choose between 0 and 3.\n");
        }
    } while(option != 0);

    return 0;
}