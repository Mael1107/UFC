#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "expense.h"
#include "persistence.h"
#include <string.h>

void save_to_json(Expense expenses[], int total) {
    cJSON *array = cJSON_CreateArray();

    // Para cada elemento(expense) do array expenses, monta um obj JSON e coloca no array JSON
    for(int i = 0; i < total; i++) {
        cJSON *obj = cJSON_CreateObject();
        cJSON_AddNumberToObject(obj, "id", expenses[i].id);
        cJSON_AddStringToObject(obj, "description", expenses[i].description);
        cJSON_AddNumberToObject(obj, "price", expenses[i].price);
        cJSON_AddStringToObject(obj, "category", category_to_string(expenses[i].category));
        cJSON_AddStringToObject(obj, "date", expenses[i].date);
        cJSON_AddItemToArray(array, obj);
    }
    char *text = cJSON_Print(array);
    
    // Abrir arquivo
    FILE *f = fopen("expenses.json", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fputs(text, f);
    fclose(f);

    // Limpar memória
    free(text);
    cJSON_Delete(array);
    printf("\nJSON saved with successfully!\n");
}

int load_from_json(Expense expenses[]) {
    FILE *f = fopen("expense.json", "r");

    if(f == NULL) {
        return 0;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, f);
    buffer[size] = '\0';
    fclose(f);

    cJSON *array = cJSON_Parse(buffer);
    free(buffer);

    if(array = NULL) {
        printf("Error parsing JSON!\n");
        return 0;
    }

    int total = cJSON_GetArraySize(array);
    for(int i = 0; i < total; i++) {
        cJSON *obj = cJSON_GetArrayItem(array, i);
        
        expenses[i].id = cJSON_GetObjectItem(obj, "id")->valueint;
        strcpy(expenses[i].description, cJSON_GetObjectItem(obj, "description")->valuestring);
        expenses[i].price = cJSON_GetObjectItem(obj, "price")->valuedouble;
        expenses[i].category = string_to_category(cJSON_GetObjectItem(obj, "category")->valuestring);
        strcpy(expenses[i].date, cJSON_GetObjectItem(obj, "date")->valuestring);
    }

    cJSON_Delete(array);
    return total;
}