#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "expense.h"
#include "persistence.h"

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