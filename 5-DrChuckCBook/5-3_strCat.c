#include <stdio.h>
#include <stdlib.h>

int strLen(char* c) {
    int i;
    for(i=0; *c != '\0'; i++, c++);
    return i;
}

char* strCat(char* s, char* t) {
    char* temp = (char*)malloc((sizeof(char) * (strLen(s)+strLen(t)))+1);
    char* pTemp = temp;
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Attempt to concat:\n%s\nand\n%s\n", s, t);
    for (; *s != '\0'; pTemp++, s++) {
        printf("%c , %c\n", *pTemp, *s);
        *pTemp = *s;
    }
    for (; *t != '\0'; pTemp++, t++) {
        printf("%c , %c\n", *pTemp, *t);
        *pTemp = *t;
    }
    return temp;
}

int main() {
    // strcat(s,t) -> "s"+"t"
    char* s = "String";
    char* t = " concatenation!";
    char* result = strCat(s, t);
    if (result != NULL)
        printf("%s\n", result);
    free(result);
    return 0;
    }
