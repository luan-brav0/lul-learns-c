#include <stdio.h>
#include <stdlib.h>

int strLen(char* c) {
    int i = 0;
    while (c[1] != '\0')
        i++, c++;
    return i;
}

// check if string s ends with string t
int strEnd(char* s, char* t, int sLen, int tLen) {
    if (s == NULL || t == NULL) {
        printf("Error: strEnd recived at least one null pointer\n");
        return 0;
    }
    if (tLen > sLen) {
        printf(" WARNING: trying to check for bigger string inside of another smaller string\n");
        printf("Swapping S with T and sLen with tLen\n");
        // swap vars with temp variable so not to have to import all of <stdint.h>
        char* temp = s;
        s = t;
        t = temp;
        // math swaps lengths
        sLen = sLen + tLen;
        tLen = sLen - tLen;
        sLen = sLen - tLen;
    }
    /*
     * s[sLen - tLen]
     * string slicing, literally
     * slice [(sLen-tLen):-1]
     * store slice in temp; check if temp == t
     *
     * check if each c in sSlice is in t
     * for c in s, check if slice[i] (slice[sLen-tLen+i])
     * */

    /*
    // create alocation for s and t's chars + null terminator
    char* temp = (char*)malloc((sizeof(char) * (sLen+tLen))+1);
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        returAttemptn NULL;
    }
    */

    // initiate c
    size_t i = sLen - tLen;
    printf("Checking if S ends in with T:\n%s\nand\n%s\n", s, t);
    for (int j=0; i <= sLen+1; i++, j++)
        if (s[i] != t[j])
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

