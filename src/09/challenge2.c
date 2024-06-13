#include <ctype.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    char ch;
    int isMinus = 0, answer = 0, inputNumber = 0;
    printf("equation? ");

    while((ch = getchar()) != '=') {

        switch(ch) {
        case '0' ... '9':
            inputNumber *= 10;
            inputNumber += ch - '0';
            break;
        case '+':
            isMinus = 0;
            break;
        case '-':
            isMinus = 1;
            break;
        case ' ':
            if(isMinus) {
                answer -= inputNumber;
            } else {
                answer += inputNumber;
            }
            inputNumber = 0;
            break;
        }
    }
    printf("answer: %d\n", answer);
    return 0;
}