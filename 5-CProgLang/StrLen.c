#include <stdio.h>

int strLen(char* c) {
    int i;
    while (*c != '\0')
        i++, c++;
    return i;
}

int main() {
    char* c = "this is 15 long";
    printf("%d:\n%s\n",strLen(c), c);
    return 0;
}
