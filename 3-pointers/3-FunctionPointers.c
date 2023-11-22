#include <stdio.h>
#include <stdlib.h>

int add(int *a, int *b) {
  printf("function A: %d, B: %d\n", *a, *b);
  printf("func memory A: %p, B: %p\n", &a, &b);
  int sum = *a + *b;
  printf("Value of func sum var: %d\n Address of sum %p\n", sum, &sum);
  return sum;
}
int main() {
  int a, b;
  printf("Enter one number to add numbers: ");
  scanf("%d", &a);
  printf("Enter another number to add numbers: ");
  scanf("%d", &b);
  printf("main A: %d, B: %d\n", a, b);
  printf("memory A: %p, B: %p\n", &a, &b);

  int sum = add(&a, &b);
  printf("Value of main sum var: %d\n Address of sum %p\n", sum, &sum);
  printf("%d + %d = %d\n", a, b, sum);
  return 0;
}
