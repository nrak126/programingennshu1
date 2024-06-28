#include <stdio.h>

int factOf(int n) { return (n + 1) * n / 2; }

int main(int argc, const char *argv[]) {
    int n;
    printf("n? ");
    scanf("%d", &n);
    printf("1から%dまでの和は %d\n", n, factOf(n));

    return 0;
}