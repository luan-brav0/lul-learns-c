#include <stdio.h>
#include <stdlib.h>

int strLen(char* c) {
    int i = 0;
    for(i=0; *c != '\0'; i++, c++);
    return i;
}

int strEnd(char* s, char* t, int sLen, int tLen) {
    if (s == NULL || t == NULL) {
        printf("ERROR: strEnd recived at least one null pointer\n");
        return 0;
    }
    if (tLen > sLen) {
        printf("ERROR: trying to check for bigger string inside of another smaller string\n");
        return 0;
    }
    // point s to -tLen index
    printf("Checking if S ends in with T:\n%s\nand\n%s\n", s, t);
    s += sLen - tLen;
    for (; *t != '\0'; s++, t++)
        if (*s != *t)
           return 1;
    return 0;
}

int main() {
    char* s = "String";
    char* t = "ing";
    char* r = "ion";
    int sLen = strLen(s);
    int tLen = strLen(t);
    int rLen = strLen(r);
    int result = strEnd(s, t, sLen, tLen);
    printf("RESULT: %d\n", result);
    result = strEnd(s, r, sLen, rLen);
    printf("RESULT: %d\n", result);
    result = strEnd(r, s, rLen, sLen);
    printf("RESULT: %d\n", result);
    return 0;
}
