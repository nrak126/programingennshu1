#include <stdio.h>

int main(int argc, char *argv[]) {
    char inputText[11] = {'\0'};
    int cnt = 0;

    printf("入力(10文字以内): ");
    scanf("%s", &inputText);

    while(inputText[cnt] != '\0')
        putchar(inputText[cnt++]);

    printf("\n");
    return 0;
}