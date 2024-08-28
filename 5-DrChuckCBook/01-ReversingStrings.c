#include <stdio.h>

#define ARR_LEN(arr) (sizeof(arr) / sizeof((arr)[0])) - 1
/*
// cant do that, right?
int strLen(char str[]) {
    int len = sizeof(str) / sizeof(str[0]);
    printf("%zu\n", len);
    return len;
}
 * */


void reverseString (char s[], size_t len) {
    printf("Reversing '%s' Len: %d\n", s, len);
    for (size_t i=0; i<(len)/2; i++) {
        size_t j = len - i - 1; 
        printf("Before\ni: %zu // j: %zu\n", i, j);
        printf("i: %c // j: %c\n", s[i], s[j]);
        s[i] = s[i] ^ s[j];
        s[j] = s[i] ^ s[j];
        s[i] = s[i] ^ s[j];
        printf("After\ni: %zu // j: %zu\n", i, j);
        printf("i: %c // j: %c\n", s[i], s[j]);
    }
    printf("Reversed: %s\n", s);
    return;
}

int main() {
    char string[] = "Hello CLang!";
    printf("Original: %s\n", string);
    size_t len = ARR_LEN(string);
    printf("%zu\n", len);
    reverseString(string, len);
    reverseString(string, len);
    char str2[] = "even";
    reverseString(str2, 4);
    /*
// this does not work as passings strings as args doesnt provide a variable address to access during the XOR swap
    // empty
    reverseString("", ARR_LEN(""));
    // single char
    reverseString("a", ARR_LEN("a"));
    // odd len
    reverseString("odd", ARR_LEN("odd"));
    // even len
    reverseString("even", ARR_LEN("even"));
    */
    return 0;
}

