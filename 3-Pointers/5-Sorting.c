#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  int A = *((int *)a);
  int B = *((int *)b);

 if (A > B)
    return 1;
  else if (A < B)
    return -1;
  else
    return 0;
}
void printArray(int *A, int Alength) {
  for (int i = 0; i < Alength; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int i;
  int A[] = {-13, 22, -1, 50, -6, 4};
  qsort(A, sizeof(A) / sizeof(A[0]), sizeof(A[0]), compare);
  printArray(A, sizeof(A) / sizeof(A[0]));
  return 0;
}
