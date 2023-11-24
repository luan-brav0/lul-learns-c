#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int Alength) {
  for (int i = 0; i < Alength; i++) {
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
  int min = 0;
  for (int i = 0; i < n; i++) {
    if (i != min && A[i] > A[min]) {
      min = i;
    }
    int k = (int)round(((float)A[min] - (float)A[i]) / 2.0);

    if (k >= 0 && k < n && A[k] < A[min]) {
      swap(&A[k], &A[min]);
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
