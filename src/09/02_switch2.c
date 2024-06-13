#include <stdio.h>

int main(int argc, const char *argv[]) {
    char ch;
    printf("text? ");

    while((ch = getchar()) != '\n') {
        switch(ch) {
        case ' ':
            printf("\n");
            break;

        default:
            printf("%c", ch);
            break;
        }
    }
    printf("\n");
    return 0;
}