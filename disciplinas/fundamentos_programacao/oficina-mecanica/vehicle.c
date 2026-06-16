#include <stdio.h>
#include "types.h"
#include <string.h>
#include "client.h"

const char* category_to_string(Category c) {
    switch (c) {
        case MOTORCYCLE: return "Motorcycle";
        case CAR:        return "Car";
        case BIKE:       return "Bike";
        case BUS:        return "Bus";
        case OTHERS:     return "Others";
        default:         return "Unknown";
    }
}

void add_vehicle(Vehicle vehicles[], int *total_vehicles, Client clients[], int total_clients) {
    int client_index, category_input;
    list_clients(clients, total_clients);
    do {
        printf("Enter the vehicle owner id:\n");
        scanf("%d", &vehicles[*total_vehicles].client_id);
        while (getchar() != '\n');
        client_index = client_exists(clients, total_clients, vehicles[*total_vehicles].client_id);
        if (client_index == -1) {
            printf("No client with that id! Try again.\n");
        }
    } while (client_index == -1);

    do {
        printf("Enter the vehicle plate:\n");
        fgets(vehicles[*total_vehicles].plate, sizeof(vehicles[*total_vehicles].plate), stdin);
        vehicles[*total_vehicles].plate[strcspn(vehicles[*total_vehicles].plate, "\n")] = '\0';

        if(strlen(vehicles[*total_vehicles].plate) == 0 || strlen(vehicles[*total_vehicles].plate) > 7) {
            printf("The vehicle plate cannot be empty or greater than 6! Try again.\n");
        }
    } while (strlen(vehicles[*total_vehicles].plate) == 0 || strlen(vehicles[*total_vehicles].plate) > 7);

    do {
        printf("What the category of the vehicle?\n");
        printf("1 - Motorcycle\n");
        printf("2 - Car\n");
        printf("3 - Bike\n");
        printf("4 - Bus\n");
        printf("5 - Others\n");

        scanf("%d", &category_input);
        while (getchar() != '\n');
        if(category_input < 1 || category_input > 5) {
            printf("Invalid category! Choose between 1 and 5.\n");
        }
    } while(category_input < 1 || category_input > 5);
    vehicles[*total_vehicles].category_vehicle = (Category)category_input;

    vehicles[*total_vehicles].id = *total_vehicles + 1;
    printf("Vehicle added with successfully!\n");
    (*total_vehicles)++;
}

void list_vehicles(Vehicle vehicles[], int total_vehicles) {
    if (total_vehicles == 0) {
        printf("No vehicles have been registered yet!\n");
        return;
    }
    printf("\n%-4s | %-10s | %-10s | %-12s\n", "ID", "CLIENT ID", "PLATE", "CATEGORY");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < total_vehicles; i++) {
        printf("%-4d | %-10d | %-10s | %-12s\n",
            vehicles[i].id,
            vehicles[i].client_id,
            vehicles[i].plate,
            category_to_string(vehicles[i].category_vehicle)
        );
    }
    printf("\n");
}

void delete_vehicle(Vehicle vehicles[], int *total_vehicles) {
    if(*total_vehicles == 0) {
        printf("No vehicles have been registered yet!\n");
        return;
    } 

    int id_to_delete, found = 0;

    printf("Enter the vehicle id to delete:\n");
    scanf("%d", &id_to_delete);
    
    for(int i = 0; i < *total_vehicles; i++) {
        if (vehicles[i].id == id_to_delete) {
            for(int j = i; j < *total_vehicles - 1; j++) {
                vehicles[j] = vehicles[j + 1];
            }
            (*total_vehicles)--;
            found = 1;
            printf("Vehicle deleted with successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("Vehicle with id %d NOT found!\n", id_to_delete);
    }
}

int vehicle_exists(Vehicle vehicles[], int total_vehicles, int id) {
    for(int i = 0; i < total_vehicles; i++) {
        if(vehicles[i].id == id){ 
            return i;
        }
    }
    return -1;
}