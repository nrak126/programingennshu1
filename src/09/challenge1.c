#include <ctype.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    char ch;
    int isMinus = 0, answer = 0, inputNumber;
    printf("equation? ");

    while((ch = getchar()) != '=') {

        switch(ch) {
        case '+':
            isMinus = 0;
            break;
        case '-':
            isMinus = 1;
            break;
        case ' ':
            break;
        default:
            inputNumber = ch - '0';
            if(isMinus) {
                answer -= inputNumber;
            } else {
                answer += inputNumber;
            }
            break;
        }
    }
    printf("answer: %d\n", answer);
    return 0;
}