#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char inputText[21];
    int isPalindrome = 1;

    printf("input(20文字以下): ");
    scanf("%s", &inputText);

    for(int i = 0; i < inputText[i] != '\0'; i++)
        if(inputText[i] != inputText[strlen(inputText) - i - 1]) {
            isPalindrome = 0;
            break;
        }
    if(isPalindrome)
        printf("回文OK\n");
    else
        printf("回文NG\n");
    return 0;
}