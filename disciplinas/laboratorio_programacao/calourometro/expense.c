#include <stdio.h>
#include <string.h>
#include "expense.h"

// Arquivo com as implementações das funções
const char* category_to_string(Category c) {
    switch(c) {
        case FOOD: return "FOOD";
        case TRANSPORTATION: return "TRANSPORTATION";
        case HOUSING: return "HOUSING";
        case MATERIAL: return "MATERIAL";
        default: return "OTHERS";
    }
}

void add_expense(Expense expenses[], int *total) {
    int cat_input;
    printf("Enter the description:\n");
    fgets(expenses[*total].description, sizeof(expenses[*total].description), stdin);
    expenses[*total].description[strcspn(expenses[*total].description, "\n")] = '\0';
    printf("Enter the price:\n");
    scanf("%lf", &expenses[*total].price);
    while (getchar() != '\n');
    printf("Enter the date:\n");
    scanf("%s", expenses[*total].date);
    while (getchar() != '\n');
    printf("Enter the category:\n");
    printf("1 - FOOD\n");
    printf("2 - TRANSPORTATION\n");
    printf("3 - HOUSING\n");
    printf("4 - MATERIAL\n");
    printf("5 - OTHERS\n");
    scanf("%d", &cat_input);
    expenses[*total].category = (Category)cat_input;
    expenses[*total].id = *total + 1;
    printf("Expense added successfully!\n");
    while (getchar() != '\n');
    (*total)++;
}

void list_expenses(Expense expenses[], int total) {
    if (total == 0) {
        printf("\nNo expenses have been added!\n\n");
    } else {
        printf("\nDescription of the expenses:\n\n");
        for(int i = 0; i < total; i++) {
            printf("ID: %d | %s | R$ %.2f | %s | %s\n",
                expenses[i].id,
                expenses[i].description,
                expenses[i].price,
                category_to_string(expenses[i].category),
                expenses[i].date);
        };
    }
}

Category string_to_category(const char *s) {
    if (strcmp(s, "FOOD") == 0) return FOOD;
    if (strcmp(s, "TRANSPORTATION") == 0) return TRANSPORTATION;
    if (strcmp(s, "HOUSING") == 0) return HOUSING;
    if (strcmp(s, "MATERIAL") == 0) return MATERIAL;
    return OTHERS;
}