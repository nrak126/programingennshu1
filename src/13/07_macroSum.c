#include <stdio.h>

#define NUM_MIN (5)
#define NUM_MAX (15)

int main() {
    int sum = (NUM_MIN + NUM_MAX) * (NUM_MAX - NUM_MIN + 1) / 2;
    printf("総和 = %d\n", sum);
    return 0;
}