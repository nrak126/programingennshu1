#include <stdio.h>

int factOf(int n) {
    if(n == 0)
        return 1;
    else
        return n * factOf(n - 1);
}

int main(int argc, const char *argv[]) {
    int n;

    printf("n? ");
    scanf("%d", &n);

    printf("%dの階乗は %d\n", n, factOf(n));

    return 0;
}