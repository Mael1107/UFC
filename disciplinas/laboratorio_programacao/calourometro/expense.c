#include <stdio.h>
#include <string.h>
#include "expense.h"
#include "persistence.h"
// Arquivo com o código/corpo das funções


// Converte do formato do enum para string
const char* category_to_string(Category c) {
    switch(c) {
        case FOOD: return "FOOD";
        case TRANSPORTATION: return "TRANSPORTATION";
        case HOUSING: return "HOUSING";
        case MATERIAL: return "MATERIAL";
        default: return "OTHERS";
    }
}

// Função de inserção de despesa
void add_expense(Expense expenses[], int *total) {
    int cat_input;
    
    // Input descrição
    do {
        printf("Enter the description:\n");
        fgets(expenses[*total].description, sizeof(expenses[*total].description), stdin);
        expenses[*total].description[strcspn(expenses[*total].description, "\n")] = '\0';

        if (strlen(expenses[*total].description) == 0) {
            printf("Description cannot be empty! Try again.\n");
        }
    } while (strlen(expenses[*total].description) == 0);

    // Input preço
    do {
        printf("Enter the price:\n");
        scanf("%lf", &expenses[*total].price);
        while(getchar() != '\n');

        if(expenses[*total].price < 0) {
            printf("Price cannot be negative! Try again.\n");
        }
    } while (expenses[*total].price < 0);

    // Input data
    printf("Enter the date:\n");
    scanf("%s", expenses[*total].date);
    while (getchar() != '\n');

    // Input categoria
    do {
        printf("Enter the category:\n");
        printf("1 - FOOD\n");
        printf("2 - TRANSPORTATION\n");
        printf("3 - HOUSING\n");
        printf("4 - MATERIAL\n");
        printf("5 - OTHERS\n");
        scanf("%d", &cat_input);
        while (getchar() != '\n');

        if (cat_input < 1 || cat_input > 5) {
            printf("Invalid category! Chosse between 1 and 5.\n");
        }
    } while (cat_input < 1 || cat_input > 5);
    expenses[*total].category = (Category)cat_input;

    // Sucesso!
    expenses[*total].id = *total + 1;
    printf("Expense added successfully!\n");
    (*total)++;
}

// Listar despesas salvas, se houver
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

// Função de remoção de despesa
void delete_expense(Expense expenses[], int *total) {
    if (*total == 0) { 
        printf("No expenses to delete!\n");
        return;
    }

    int id_to_delete;
    printf("Enter the ID of the expense to delete:\n");
    scanf("%d", &id_to_delete);
    while(getchar() != '\n');   

    int found_index = -1;
    for(int i = 0; i < *total; i++) {
        if (expenses[i].id == id_to_delete) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Expense with ID %d not found!\n", id_to_delete);
        return;
    }

    for(int i = found_index; i < *total - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    (*total)--;

    printf("Expense deleted successfully!\n");
    save_to_json(expenses, *total);
}

// Converte de string para o formato do enum
Category string_to_category(const char *s) {
    if (strcmp(s, "FOOD") == 0) return FOOD;
    if (strcmp(s, "TRANSPORTATION") == 0) return TRANSPORTATION;
    if (strcmp(s, "HOUSING") == 0) return HOUSING;
    if (strcmp(s, "MATERIAL") == 0) return MATERIAL;
    return OTHERS;
}