#include <stdio.h>

int main() {

    // QUESTION 01 =>

    int x = 10;
    int *p;
    p = &x;

    printf("%d\n", x); // Valor de x
    printf("%p\n", &x); // Endereço de x
    printf("%p\n", p); // "Valor" de p, que no caso é o endereço de x
    printf("%d\n", *p); // Valor apontado por p -> x = 10

    // QUESTION 02 =>

    *p = 25;
    printf("%d\n", x); // Novo valor de x

    // // QUESTION 03 =>

    int a = 3;
    int b = 7;

    int *pa = &a;
    int *pb = &b;

    int temp = *pa;     // guarda o valor de a (3) antes de perdê-lo
    *pa = *pb;         // a recebe o valor de b (7)
    *pb = temp;       // b recebe o valor original de a (3)

    printf("%d\n", *pa); // 7
    printf("%d\n", *pb); // 3
    
    // QUESTION 04 =>

    int v = 5;
    int *p = &v;
    int **pp = &p;

    printf("%d\n", v); // Valor de v
    printf("%d\n", *p); // Valor apontado por p -> v = 5
    printf("%p\n", pp); // "Valor de pp", que no caso é o endereço de p -> &v -> 5 
    **pp = 9;
    printf("%d\n", v);


    // QUESTION 05 =>
    

    int arr[5];

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);
    printf("%p\n", arr);

    printf("%zu\n", sizeof(int));


    // QUESTION 06 =>
    

            
    
    
    
    return 0;
}