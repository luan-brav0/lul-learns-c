#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("My fav %s is %d\n", "number", 13);
    // prints as "3.141500"
    printf("2 Pi is %f\n", 3.1415 * 2);
    char mathGrade = 'F';
    printf("Math: %c\n", mathGrade);
    const int SQUARE = 2;
    printf("3² = %f", pow(3, SQUARE));
    return 0;
}
