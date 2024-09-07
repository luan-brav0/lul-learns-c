#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 100

int isStrNum(char* c) {
    // TO SEARCH: why couldn't I do {} while (c++);`?
    while (*c) {
        if (*c < '0' || *c > '9') {
            printf("%c is NaN\n", *c);
            return 0;
        }
        c++;
    }
    return 1;
}

int polishCalc(char* strs[]){
    int n1 = 0, n2 = 0, result = 0;
    int prevs[MAX_LENGTH];
    int* prev = prevs;

    do {
        printf("n1: %d n2: %d prev: %d\n ", n1, n2, *prev);
        /* n1, n2
         * if n++ == isNumber && !n1 && !n2: prev[i]=n1; n1=n2; n2=n
         * else swich n / operators
             * result += n1 op n2
         * clear n1 & n2
         * n1 = prev
         * check for n++
         * */

        if (isStrNum(*strs)) {
            printf("number: %s\n", *strs);
            // assign found number with whoever is available
            if (!n1) {
                n1 = atoi(*strs);
                continue;
            } else if (!n2) {
                n2 = atoi(*strs);
                continue;
            } else {
                *prev = n1;
                prev++;
                n1 = n2;
                n2 = atoi(*strs);
                continue;
            }
        } else {
            printf("other: %s\n", *strs);
            // if doing an operation with previously typed numbers, populate variables
            if (!n1)
                n1 = result;
            if (!n2)
                n2 = *(prev--);
            switch (**strs) {
                case '+':
                    result = n1 + n2;
                    break;
                case '-':
                    result = n1 - n2;
                    break;
                case '*':
                    result = n1 * n2;
                    break;
                case '/':
                    result = n1 / n2;
                    break;
                default:
                    printf("polishCalc: ERROR: Unexpected character found in input\n\t%s\n", *strs);
                    return 0;
            }
            n1 = 0, n2 = 0;
            printf("result: %d\n", result);

            if (*prevs) {
                n1 = *prev;
                prev--;
            }
            n2 = 0;
        }

    } while (strs++ && **strs);
    printf("Final result: %d\n", result);
    return result;
}

void test_polishCalc() {
    char* inputs[][MAX_LENGTH] = {
        { "2", "3", "4", "+", "*", "\0" },
        { "69", "1000", "*", "420", "+", "\0" },
        { "28", "6", "2", "4", "*", "+", "/", "\0" },
        { "4", "2", "5", "*", "+", "1",  "3", "2", "*", "+", "/", "\0" }
    };
    char** inp = *inputs;
    int expecteds[] = {
        (3 + 4) * 2,
        (69 * 1000) + 420,
        28 / (6 + 2 * 4),
        (4 + 2 * 5) / (1 + 3 * 2)
    };
    int* exp = expecteds;
    int result;
    do {
       result = polishCalc(inp);
       // why doesn't assert return a bool?
       printf("%s: EXPECTED: %s GOT: %d \n",
              (result == *exp) ? "PASSED" : "FAILED", *exp, result);
    } while (inp++ && exp++);
    return;
}

int main() {
    test_polishCalc();
    return 0;
}
