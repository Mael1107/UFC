#include "types.h"

void add_vehicle(Vehicle vehicles[], int *total_vehicles, Client clients[], int total_clients);
void list_vehicles(Vehicle vehicles[], int total_vehicles);
void delete_vehicle(Vehicle vehicles[], int *total_vehicles);
int vehicle_exists(Vehicle vehicles[], int total_vehicles,int id);
const char* category_to_string(Category c);