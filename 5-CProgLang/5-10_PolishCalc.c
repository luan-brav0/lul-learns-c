/* The C programming language
 * Chapter 5: Pointer and Arrays
 * Exercise 5-10, page 118
 * (reverse polish notation calculator)
 * done by luan-brav0*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define TESTS_AMOUNT 8

int isStrNum(char* c) {
    // TO SEARCH: why couldn't I do {} while (c++);`?
    do {
        if (*c < '0' || *c > '9') {
            // printf("%c is NaN\n", *c);
            return 0;
        }
    } while (c++ && *c);
    return 1;
}

   /* idealizing:
    *
    * result, curNum
    * if n++ == isNumber && !result && !curNum: prev[i]=result; result=curNum; curNum=n
    * else swich n / operators
    *     result += result op curNum
    * clear result & curNum
    * result = prev
    * check for n++
    */

int polishCalc(char* argv[]){
    int curNum = 0, result = 0;
    int prevs[MAX_LENGTH] = { };
    int* prev = prevs;
    do {
        // printf("\tcur: %s result: %d curNum: %d prev: %d\n", *argv, result, curNum, *(prev-1));
        if (isStrNum(*argv)) {
            // assign found number with whoever is available
            if (!result) {
                result = atoi(*argv);
            } else if (!curNum) {
                curNum = atoi(*argv);
            } else {
                *prev = result;
                prev++;
                result = curNum;
                curNum = atoi(*argv);
            }
            continue;
        } else {
            if (!result) {
                printf("polishCalc: ERROR: Operator with no number to compute.\tCurreltly: 0\n");
                return 0;
            }
            // if there is no second number set and no number previously typed & saved
            if (!curNum){
                if (prev-1 < prevs) {
                    printf("polishCalc: ERROR: too many operators for too few number.\t%s\n", *argv);
                    return 0;
                }
                printf(" %d\n", *(prev-1));
                prev--;
                curNum = *(prev);
                *prev = 0;
            }
            // if doing an operation with previously typed numbers, populate variables
            switch (**argv) {
                case '+':
                    result += curNum;
                    break;
                case '-':
                    result -= curNum;
                    break;
                case '*':
                    result *= curNum;
                    break;
                case '/':
                    if (result == 0) {
                        printf("polishCalc: ERROR: Attempting to devide by 0.\n\t%s\n", *argv);
                        return 0;
                    }
                    result = curNum / result;
                    break;
                default:
                    printf("polishCalc: ERROR: Unexpected character found in input.\n\t%s\n", *argv);
                    return 0;
            }
            curNum = 0;
            printf("result: %d\n", result);
        }
        // printf("\t curNum: %s result: %d curNum: %d prev: %d\n", *argv, result, curNum, *(prev-1));
    } while (argv++ && *argv);
    // printf("Prevs left: %s\n", (prev != prevs && *prev != 0) ? "TRUE" : "FALSE");
    if (prev != prevs && *(prev-1) != 0) {
        printf("polishCalc: ERROR: Not enough operators, there are still numbers left to compute.\n\tcurrently:%d\n", result);
        return 0;
    }
    return result;
}

void test_polishCalc() {
    char* inputs[TESTS_AMOUNT][MAX_LENGTH] = {
        { "2", "3", "4", "+", "*", NULL },
        { "69", "1000", "*", "420", "+", NULL },
        { "28", "6", "2", "4", "*", "+", "/", NULL },
        { "4", "2", "5", "*", "+", "1",  "3", "2", "*", "+", "/", NULL },
        { "96", NULL },
        {"96", "-", "+", NULL },
        {"4", "2", "5","96", "-", "+", NULL },
        { "96", "foo", NULL },
    };
    int expecteds[TESTS_AMOUNT] = {
        (3 + 4) * 2,
        (69 * 1000) + 420,
        28 / (6 + 2 * 4),
        (4 + 2 * 5) / (1 + 3 * 2),
        96,
        0,
        0,
        0
    };
    char* (*pInp)[MAX_LENGTH] = inputs;
    int* pExp = expecteds;
    int result = 0;
    int testsPassed = 0;
    do {
        result = polishCalc(*pInp);
        printf("Final result: %d\nTEST: ", result);
        if (result == *pExp) {
            testsPassed++;
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    } while (pInp++ && pExp++ && **pInp);
    printf("TOTAL TESTS PASSED: %d out of %d\n", testsPassed, TESTS_AMOUNT);
    return;
}

int main(int argc, char* argv[]) {
    test_polishCalc();
    int result = polishCalc(argv+1);
    argv++;
    do {
        printf("%s\n", *argv);
    } while (argv++ && *argv);
    printf("Result: %d\n", result);
    if (!result) return 1;
    return 0;
}
