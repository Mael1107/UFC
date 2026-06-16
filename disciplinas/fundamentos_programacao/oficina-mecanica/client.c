#include "types.h"
#include <stdio.h>
#include <string.h>

void add_client(Client clients[], int *total_clients) {
    do {
        printf("Enter the client name:\n");
        fgets(clients[*total_clients].name, sizeof(clients[*total_clients].name), stdin);
        clients[*total_clients].name[strcspn(clients[*total_clients].name, "\n")] = '\0';

        if(strlen(clients[*total_clients].name) == 0) {
            printf("Name cannot be empty! Try again.\n");
        }
    } while(strlen(clients[*total_clients].name) == 0);

    do {
        printf("Enter the phone number of the client:\n");
        scanf("%s", clients[*total_clients].phone);
        while (getchar() != '\n');

        if(strlen(clients[*total_clients].phone) == 0) {
            printf("Phone number cannot be empty! Try again.\n");
        }
    } while(strlen(clients[*total_clients].phone) == 0);

    do {
        printf("Enter the adress of the client:\n");
        fgets(clients[*total_clients].address, sizeof(clients[*total_clients].address), stdin);
        clients[*total_clients].address[strcspn(clients[*total_clients].address, "\n")] = '\0';
        if(strlen(clients[*total_clients].address) == 0) {
            printf("Adress cannot be empty! Try again.\n");
        }
    } while(strlen(clients[*total_clients].address) == 0);

    clients[*total_clients].id = *total_clients + 1;
    (*total_clients)++;
    printf("Client added with successfully!\n");
}

void list_clients(Client clients[], int total_clients) {
    if (total_clients == 0) {
        printf("No clients have been registered yet!\n");
        return;
    }
    printf("\n%-4s | %-25s | %-15s | %-30s\n", "ID", "NAME", "PHONE", "ADDRESS");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < total_clients; i++) {
        printf("%-4d | %-25s | %-15s | %-30s\n",
            clients[i].id,
            clients[i].name,
            clients[i].phone,
            clients[i].address
        );
    }
    printf("\n");
}

void delete_client(Client clients[], int *total_clients) {
    if (*total_clients == 0){ 
        printf("No clients to delete!\n");
        return;
    }

    int id_to_delete, found = 0;
    
    printf("Enter the client id to delete:\n");
    scanf("%d", &id_to_delete);

    for(int i = 0; i < *total_clients; i++) {
        if (clients[i].id == id_to_delete) {
            for(int j = i; j < *total_clients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            (*total_clients)--;
            found = 1;
            printf("Client deleted with successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Client with id %d NOT found!\n", id_to_delete);
    }
}

int client_exists(Client clients[], int total_clients, int id) {
    for(int i = 0; i < total_clients; i++) {
        if(clients[i].id == id){ 
            return i;
        }
    }
    return -1;
}