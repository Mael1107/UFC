#include <stdlib.h>
#include <stdio.h>
#include "expense.h"
#include "persistence.h"
#include "cJSON.h"

int main() {
    Expense expenses[100];
    int total = load_from_json(expenses);

    if(total > 0) {
        printf("Loaded %d expenses from file!\n", total);
    }
    int option;

    do {
        printf("Choose an option to go:\n");
        printf("1 - Add expense\n");
        printf("2 - List expenses\n");
        printf("3 - Save to JSON file\n");
        printf("4 - Load from JSON file\n");
        printf("0 - Quit\n");
        scanf("%d", &option);
        while (getchar() != '\n');
        switch(option) {
            case 1: add_expense(expenses, &total); break;
            case 2: list_expenses(expenses, total); break;
            case 3: save_to_json(expenses, total); break;
            case 4: 
                total = load_from_json(expenses);
                printf("Reloaded %d expenses from file!\n", total);
                break;
            case 0: printf("Bye!\n"); break;
            default: printf("Invalid Option! Try again.\n");
        }
    } while (option != 0);
    return 0;
}

