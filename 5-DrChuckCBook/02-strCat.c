#include <stdio.h>
#include <stdlib.h>

int strLen(char* c) {
    int i;
    for(i=0; c[i] != '\0'; i++)
    while (*c != '\0')
        i++, c++;
    return i;
}

char* strCat(char* s, char* t) {
    // create alocation for s and t's chars + null terminator
    char* temp = (char*)malloc((sizeof(char) * (strLen(s)+strLen(t)))+1);
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    char* c;
    size_t i;
    printf("Attempt to concat:\n%s\nand\n%s\n", s, t);
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
    char* t = " concatenation!";
    char* result = strCat(s, t);
    if (result != NULL)
        printf("%s", result);
    free(result);
    return 0;
    }
