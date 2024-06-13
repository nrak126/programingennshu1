#include <stdio.h>

int main(int argc, const char *argv[]) {
    int array[100] = {0};
    for(int i = 0; i < 100; i++) {
        array[i] = i;
        printf("array[%d]: %d\n", i, array[i]);
    }

    return 0;
}