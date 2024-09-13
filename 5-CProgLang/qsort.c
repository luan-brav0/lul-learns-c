// TO BE FINISHED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define ARR_SIZE 5

void swap(void* array[], int a, int b) {
    printf("\tswap\n");
    void* temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    return;
}
void printNumberArray(int* array) {
    for (; *array; array++)
        printf("%d%s", *array, (array+1) ? " " : "");
    printf("\n");
    return;
}
int compareNumbers(void* arr[], int a, int b) {
    printf("here\n");
    printf("\tcomp result: %d\n", ((int*)arr[a] > (int*)arr[b]) - ((int*)arr[a] < (int*)arr[b]));
    printf("\tcomp : %d %d\n", (int*)arr[a] , (int*)arr[b]);
    // casting void pointers to int pointers and dereferencing for comparison
    return ((int*)arr[a] > (int*)arr[b]) - ((int*)arr[a] < (int*)arr[b]);
}

void quickSort(void* array[], int left, int right, int (*compare)(void*, void*)) {
    // for(int i = 0; i<5 && printf("%d: %d\n", i, (int*)array[i]); i++);
    printNumberArray((int*)array);
    int iterator=0, last=0;
    //printf("left: %d right %d iter %d last %d\n", (int*)array[left], (int*)array[right], (int*)array[iterator], (int*)array[last]);
    // base case
    if (left >= right)
        return;
    swap(array, left, (left+right)/2); // set pivot to middle of array by swaping left nth item to middle
    // TODO: median of three:
    // // look at first, middle and last items, set them in order (smaller = first, biggest = last, mid = middle)

    last = left;
    printf("TOFIX: crashing after comparing here\n");
    printf("%d\n", (*compare)(array, iterator, left));
    for (iterator=left+1; iterator <= right; iterator++)
        if (((*compare)(array, iterator, left)) < 0){
            swap(array, last++, iterator);
        }
    swap(array, left, last);
    quickSort((void**)array, left, last-1, compare);
    quickSort((void**)array, last+1, right, compare);
}

int main(int argc, char** argv) {
    int array[ARR_SIZE] = { 4, 5, 1, 2 , 3 };
    int numeric = 1;
    quickSort((void**)array, 0, ARR_SIZE - 1, compareNumbers);
    printf("\tDONE\n");
    printNumberArray(array);

    int expectedArray[ARR_SIZE] = { 1, 2, 3, 4, 5 };
    int *pA = array, *pEA = expectedArray;
    bool result;
    // compare output with expectency until end or fail
    for(result=true; result && (result = *pA == *pEA); pA++, pEA++);

    printf("%s\n", result ? "PASSED" : "FAILED");
    return (int)result;
}
