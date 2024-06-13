#include <stdio.h>

int main(int argc, char *argv[]) {
    int x, y, result, i;
    scanf("%d %d", &x, &y);

    result = x;
    for(int i = 1; i = y; i++) {
        result = result * x;
    }

    printf("result = %d\n", result);

    return (0);
}