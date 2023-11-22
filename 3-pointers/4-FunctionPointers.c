#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void newtonSort(int *A, int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (i != max && A[i] > A[max]) {
      max = i;
    }
    int k = round(((float)A[i]) - (float)A[max] / 2.0) >= 0
                ? round(((float)A[i]) - (float)A[max] / 2.0)
                : 0;

    // Check if k is within the bounds of the array
    if (A[k] > A[max]) {
      swap(&A[k], &A[max]);
    }
  }
}

int main() {
  int A[] = {3, 5, 4, 2, 1};
  int Alength = sizeof(A) / sizeof(A[0]);

  printArray(A, 5);
  newtonSort(A, 5);
  printArray(A, 5);

  return 0;
}
