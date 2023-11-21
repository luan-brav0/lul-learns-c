#include <stdio.h>
int main() {
  int A[] = {1, 2, 3, 4, 5};
  int ALength = sizeof(A) / sizeof(A[0]);
  int sum = 0;
  for (int i = 0; i < ALength; i++) {
    sum += A[i];
  }
  printf("Sum = %d\n", sum);

  return 0;
}
