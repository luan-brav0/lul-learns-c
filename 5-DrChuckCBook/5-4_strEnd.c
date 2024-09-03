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
        printf("Error: strEnd recived at least one null pointer");
        return 0;
    }
    if (tLen > sLen) {
        printf("Error trying to check for bigger string inside of another smaller string");
        printf("Swapping S with T and sLen with tLen ");
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
    int result;
    char* c = s[(sLen - tLen)]
    size_t i;
    printf("Checking if S ends in with T:\n%s\nand\n%s\n", s, t);
    for (c = s; *c != '\0'; c++, i++)
        temp[i] = *c;
    // starts adding str t where str s ended
    for (c = t; *c != '\0'; c++, i++)
        temp[i] = *c;
    return temp;
}

int main() {
    // strcat(s,t) -> "s"+"t"
    char* s = "String";
    char* t = "ing";
    char* r = "ion";
    int sLen = strLen(s);
    int tLen = strLen(t);
    int rLen = strLen(r);
    char* result = strEnd(s, t, sLen, tLen);
    if (result != NULL)
        printf("%s", result);
    char* result = strEnd(s, r, sLen, rLen);
    if (result != NULL)
        printf("%s", result);
    free(result);
    return 0;
    }

