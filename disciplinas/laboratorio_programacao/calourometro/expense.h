#ifndef EXPENSE_H
#define EXPENSE_H

// Arquivo de declaração da struct, enum e funções
typedef enum {
    FOOD = 1,
    TRANSPORTATION,
    HOUSING,
    MATERIAL,
    OTHERS
} Category;

typedef struct {
    int id;
    char description[100];
    double price;
    Category category;
    char date[11];
} Expense;
        
const char* category_to_string(Category c);
Category string_to_category(const char *s);
void add_expense(Expense expenses[], int *total);
void list_expenses(Expense expenses[], int total);


#endif