#include <stdio.h>

int main(int argc, char *argv[]) {
    char inputText[6] = {'\0'};

    printf("input: ");
    scanf("%s", &inputText);
    for(int i = sizeof(inputText) - 1; 0 <= i; i--) {
        putchar(inputText[i]);
    }
    putchar('\n');
    return 0;
}