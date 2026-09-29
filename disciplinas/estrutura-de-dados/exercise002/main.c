#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date_birth;

typedef struct
{
    char street[50];
    char neighborhood[50];
    int number;
    char zip_code[15];
    char city[30];
    char state[15];
} Address;

typedef struct
{
    char name[50];
    char cpf[15];
    char rg[20];
    char registration[10];
    char course[50];
    Address address;
    Date_birth date_birth;
    char phone[20];
} Student;

int main() {

    Student student;

    printf("Enter your name:\n");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter your CPF:\n");
    fgets(student.cpf, sizeof(student.cpf), stdin);
    student.cpf[strcspn(student.cpf, "\n")] = '\0';

    printf("Enter your RG:\n");
    fgets(student.rg, sizeof(student.rg), stdin);
    student.rg[strcspn(student.rg, "\n")] = '\0';

    printf("Enter your registration:\n");
    fgets(student.registration, sizeof(student.registration), stdin);
    student.registration[strcspn(student.registration, "\n")] = '\0';

    printf("Enter your course:\n");
    fgets(student.course, sizeof(student.course), stdin);
    student.course[strcspn(student.course, "\n")] = '\0';

    printf("Enter your address information\n");

    printf("Enter your street:\n");
    fgets(student.address.street, sizeof(student.address.street), stdin);
    student.address.street[strcspn(student.address.street, "\n")] = '\0';

    printf("Enter your neighborhood:\n");
    fgets(student.address.neighborhood, sizeof(student.address.neighborhood), stdin);
    student.address.neighborhood[strcspn(student.address.neighborhood, "\n")] = '\0';

    printf("Enter your number:\n");
    scanf("%d", &student.address.number);
    while (getchar() != '\n')
        ;

    printf("Enter your zip code:\n");
    fgets(student.address.zip_code, sizeof(student.address.zip_code), stdin);
    student.address.zip_code[strcspn(student.address.zip_code, "\n")] = '\0';

    printf("Enter your city:\n");
    fgets(student.address.city, sizeof(student.address.city), stdin);
    student.address.city[strcspn(student.address.city, "\n")] = '\0';

    printf("Enter your state:\n");
    fgets(student.address.state, sizeof(student.address.state), stdin);
    student.address.state[strcspn(student.address.state, "\n")] = '\0';

    printf("Enter your date of birth (day month year):\n");
    scanf("%d %d %d", &student.date_birth.day, &student.date_birth.month, &student.date_birth.year);
    while (getchar() != '\n')
        ;

    printf("Enter your phone:\n");
    fgets(student.phone, sizeof(student.phone), stdin);
    student.phone[strcspn(student.phone, "\n")] = '\0';

    printf("\n===== STUDENT INFO =====\n");
    printf("Name: %s\n", student.name);
    printf("CPF: %s\n", student.cpf);
    printf("RG: %s\n", student.rg);
    printf("Registration: %s\n", student.registration);
    printf("Course: %s\n", student.course);
    printf("Address: %s, %d - %s, %s - %s, ZIP: %s\n",
           student.address.street,
           student.address.number,
           student.address.neighborhood,
           student.address.city,
           student.address.state,
           student.address.zip_code);
    printf("Date of birth: %d/%d/%d\n",
           student.date_birth.day, student.date_birth.month, student.date_birth.year);
    printf("Phone: %s\n", student.phone);

    return 0;
}