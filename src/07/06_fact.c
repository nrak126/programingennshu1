#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x, n, result = 1;
    printf("x n? ");
    scanf("%d %d", &x, &n);

    for (int i = 0; i < n; i++) {
        result *= x;
    }

    printf("%d^%d = %d\n", x, n, result);
    return 0;
}
