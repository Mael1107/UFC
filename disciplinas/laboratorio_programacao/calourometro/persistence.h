#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "expense.h"

// Arquivo de declaração das funções de serialização
void save_to_json(Expense expenses[], int total);
int load_from_json(Expense expenses[]);

#endif