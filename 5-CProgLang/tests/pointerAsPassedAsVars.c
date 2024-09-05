#include <stdio.h>

void nextChar(char* c) {
    c++;
    return;
}
int main() {
    char c[] = "string";
    printf("%c\n", *c);
    nextChar(c);
    printf("%c\n", *c);
    return 0;
}
