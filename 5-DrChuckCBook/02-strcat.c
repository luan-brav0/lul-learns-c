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
    char* temp = (char*)malloc(strLen(s)+strLen(t));
    char* c;
    size_t i;
    for (c = s, i = 0; *c != '\0'; c++, i++) {
        temp[i] = *c;
        // not going to T
        if (c[i+1] == '\0')
            c = t;
    }
    return temp;
}

int main() {
    // strcat(s,t) -> "s"+"t"
    char* s = "String";
    char* t = " concatenation!";
    char* sum = strCat(s, t);
    printf("%s", sum);
    return 0;
}
