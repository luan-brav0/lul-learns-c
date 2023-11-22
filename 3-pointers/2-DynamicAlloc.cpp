#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "How many elements in the array? " << endl;
  cin >> n;
  // d y n a m i c
  int *A = (int *)malloc(n * sizeof(int));

  // not initialized memory (not zeroed)
  cout << "The not initialized elements in the A array are: " << endl;
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  // Courtesy of Codeium
  for (int i = 0; i < n; i++) {
    A[i] = i + 1;
  }
  cout << "The elements in the A array now are: " << endl;
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  // i n i t i a l i z e d   d y n a m i c
  int *B = (int *)calloc(n, sizeof(int));
  cout << "The inicialized elements in the B array are: " << endl;
  for (int i = 0; i < n; i++) {
    cout << B[i] << " ";
  }
  cout << endl;

  // realocating
  int *C = (int *)realloc(A, (n / 2) * sizeof(int));
  // in n=5 2.5 will be floored and only 3/5 will NOT be allocated [anymore]
  cout << "There are half as many elements in the C array: " << endl;
  for (int i = 0; i < n / 2; i++) {
    cout << C[i] << " ";
  }
  cout << endl;

  // freeing all of dynamicly alocated space for A
  // same as reallocating to same address but to size 0; also to realloc to NULL
  free(A);
  cout << "The elements in the deallocated A array are: " << endl;
  for (int i = 0; i < (sizeof(*A) / sizeof(int)); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  cout << "Respectively A, B & C: " << A << " " << B << " " << C << endl;

  return 0;
}
