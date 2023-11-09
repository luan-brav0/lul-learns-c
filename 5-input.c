#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You're %d years old", age);
    char name[30];

    printf("Enter your first and last name:");
    fgets(name, 30, stdin);

    return 0;
}