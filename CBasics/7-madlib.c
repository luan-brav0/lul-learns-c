#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[20];
    char age[20];
    char job[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%s", age);
    printf("Enter your job: ");
    scanf("%s", job);

    printf("Hi!, My name is %s, I'm %s years old, I'm a %s!\n", name, age, job);

    return 0;
}