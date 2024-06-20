#include <stdio.h>

int main(int argc, const char *argv[]) {
    int evenNumbers[5] = {}, sum = 0;

    for(int i = 2; i <= 10; i += 2) {
        evenNumbers[i / 2 - 1] = i;
    }
    for(int i = 0; i < 5; i++) {
        sum += evenNumbers[i];
    }

    printf("合計 = %d\n", sum);
    return 0;
}