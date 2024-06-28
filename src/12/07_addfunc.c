#include <stdio.h>

int addOf(int a, int b) { return a + b; }

int main(int argc, const char *argv[]) {
    int a, b;
    printf("a b? ");
    scanf("%d %d", &a, &b);
    printf("和は %d\n", addOf(a, b));

    return 0;
}