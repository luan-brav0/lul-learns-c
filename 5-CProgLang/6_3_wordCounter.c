#include <stdio.h>
#include <string.h>
#define NKEYS  sizeof keytab / sizeof keytab[0]


struct key {
    char* word;
    int count;
} keytab [] = {
    "int", 0,
    "char", 0,
    "struct", 0,
    "return", 0,
};
const size_t keytab_length = sizeof keytab / sizeof(struct key);

int binarySearch(char* word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
                low = mid + 1;
        else
            return mid;
    }
    return -1;
}


int main() {

    return 0;
}
