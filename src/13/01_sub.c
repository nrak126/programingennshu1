#include <stdio.h>

int subOf(int a, int b) { return a - b; }

int main(int argc, const char *argv[]) {
    int a = 5, b = 10, result = 0;
    result = subOf(a, b);
    printf("%d - %d = %d\n", a, b, result);
    return 0;
}