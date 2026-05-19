#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    cJSON * obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "id", 1);
    cJSON_AddStringToObject(obj, "description", "Test");
    cJSON_AddNumberToObject(obj, "Price", 2.50);

    char *text = cJSON_Print(obj);
    printf("JSON gerado:\n%s\n", text);

    free(text);
    cJSON_Delete(obj);
    return 0;
}
