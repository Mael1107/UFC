#include "types.h"

void add_client(Client clients[], int *total_clients);
void delete_client(Client clients[], int *total_clients);
void list_clients(Client clients[], int total_clients);
int client_exists(Client clients[], int total_clients, int id);