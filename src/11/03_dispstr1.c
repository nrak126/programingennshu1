#include <stdio.h>

int main(int argc, char *argv[]) {
    char array[] = "abcde";

    printf("一文字ずつ印字: ");

    for(int i = 0; i < sizeof(array); i++)
        putchar(array[i]);

    printf("\n");
    return 0;
}