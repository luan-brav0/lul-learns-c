#include <stdio.h>
#include <stdlib.h>

int main(){
    double n1;
    double n2;
    printf("Enter first number: ");
    scanf("%lf", &n1);
    printf("Enter second number: ");
    scanf("%lf", &n2);

    printf("%f + %f = %f\n", n1, n2, n1+n2);
    return 0;
}
